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

std::ostream& operator<<(std::ostream& os, const Allergen& allergen)
{
	std::string separator = "";
	for (const auto& [key, value] : allergenNames)
	{
		if ((key & allergen) == key) {
			os << separator << value;
			separator = "|";
		}
	}
	return os;
}
