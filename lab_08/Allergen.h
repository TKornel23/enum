#pragma once
#include<cstdint>
#include <string>
#include <iostream>
#include<vector>

enum class Allergen : uint8_t
{
	Gluten = 1, Lactose = 2, Egg = 4, Fish = 8
};

using Allergens = std::vector<Allergen>;

void operator|=(Allergen& lhs, const Allergen rhs);

Allergen operator&(const Allergen lhs, const Allergen rhs);

Allergen ParseAllergen(const std::string& remainingLine);

std::ostream& operator<<(std::ostream& os, const Allergen& allergen);



