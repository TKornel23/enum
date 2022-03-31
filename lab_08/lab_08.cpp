// lab_08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Ingredient.h"
#include<vector>
#include <algorithm>
#include<fstream>
#include<string>

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& vec) {
	std::for_each(vec.begin(), vec.end(), [&os](const T& item) { os << item << std::endl; });
	return os;
}

template<typename T>
std::ifstream& operator>>(std::ifstream& ifs, std::vector<T>& vec) {
	while (!ifs.eof()) {
		std::string line;
		std::getline(ifs, line);
		vec.push_back(T::Parse(line));
	}

	return ifs;
}

int main()
{
	std::vector<Ingredient> ingredients;
	/*ingredients.emplace_back("water");
	ingredients.emplace_back("flour", Allergen::Gluten);
	ingredients.emplace_back("egg", Allergen::Egg);
	ingredients.emplace_back("pasta", Allergens{Allergen::Gluten,Allergen::Egg});
	ingredients.emplace_back("fish", Allergen::Fish);*/

	std::ifstream inputFile("ingredients.txt");
	inputFile >> ingredients;

	std::cout << ingredients;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing
//  code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
