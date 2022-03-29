#pragma once
#include "Allergen.h"




class Ingredient
{
public:
	Ingredient(const std::string& name);
	Ingredient(const std::string& name, const Allergen allergen);
	Ingredient(const std::string& name, const Allergens& allergens);

	static Ingredient Parse(const std::string& line);

	friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);
private:
	std::string mName;
	Allergen mAllergen = static_cast<Allergen>(0);
};

