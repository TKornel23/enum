#include "Allergen.h"

#include<map>

std::map<Allergen, std::string> allergenNames{
	{Allergen::Gluten, "GLUTEN"},
	{Allergen::Lactose, "LACTOSE"},
	{Allergen::Egg, "EGG"},
	{Allergen::Fish, "FISH"}
};

void operator|=(Allergen& lhs, const Allergen rhs)
{
	lhs = static_cast<Allergen>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}

Allergen operator&(const Allergen lhs, const Allergen rhs)
{
	Allergen result;
	result = static_cast<Allergen>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
	return result;
}

Allergen ParseAllergen(const std::string& remainingLine)
{
	const auto selectAllergen = [](const auto& allergenName) {
		for (const auto& [key, value] : allergenNames) {
			if (allergenName == value) {
				return key;
			}
		}
		throw std::invalid_argument(allergenName);
	};

	auto pos = remainingLine.find(',');
	if (pos == std::string::npos) {
		try {
			return selectAllergen(remainingLine);
		}
		catch (const std::invalid_argument&) {
			return static_cast<Allergen>(0);
		}
	}
	Allergen result = static_cast<Allergen>(0);
	auto remainingString = remainingLine;
	do {
		try {
			result |= selectAllergen(remainingString.substr(0, pos));
		}
		catch (const std::invalid_argument&) {

		}
		remainingString = remainingString.substr(pos + 1);
		pos = remainingString.find(',');
	} while (pos != std::string::npos);
	try {
		result |= selectAllergen(remainingString);
	}
	catch (const std::invalid_argument&) {

	}
}

std::ostream& operator<<(std::ostream& os, const Allergen& allergen)
{
	std::string separator = "";
	for (const auto& [key, value] : allergenNames)
	{
		if ((key & allergen) == key) {
			os << separator << value;
			separator = ",";
		}
	}
	return os;
}
