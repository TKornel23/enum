#include "Ingredient.h"

Ingredient::Ingredient(const std::string& name)
	: mName(name)
{

}

Ingredient::Ingredient(const std::string& name, const Allergen allergen)
	: mName(name), mAllergen(allergen)
{

}

Ingredient::Ingredient(const std::string& name, const Allergens& allergens)
	: mName(name)
{
	if (!allergens.empty()) {
		mAllergen = allergens[0];
		for (size_t i = 1; i < allergens.size(); ++i) {
			mAllergen |= allergens[i];
		}
	}
}

Ingredient Ingredient::Parse(const std::string& line)
{
	const auto pos = line.find(',');
	if (pos == std::string::npos) {
		return Ingredient(line);
	}

	const auto name = line.substr(0, pos);
	const auto allergen = ParseAllergen(line.substr(pos + 1));
	return Ingredient(name, allergen);
}

std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient)
{
	os << ingredient.mName;
	if (static_cast<uint8_t>(ingredient.mAllergen) != 0) {
		os << "," << ingredient.mAllergen;
	}

	return os;
}
