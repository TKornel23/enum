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

std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient)
{
	os << ingredient.mName;
	if (static_cast<uint8_t>(ingredient.mAllergen) != 0) {
		os << "(" << ingredient.mAllergen << ")";
	}

	return os;
}
