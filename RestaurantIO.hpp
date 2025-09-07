#pragma once
#include <vector>
#include <string>
#include "Restaurant.hpp"

void addRestaurant(std::vector<Restaurant>& database);
void displayRestaurants(const std::vector<Restaurant>& database);
bool loadDatabase(std::vector<Restaurant>& database, const std::string& filename);
void saveDatabase(const std::vector<Restaurant>& database, const std::string& filename);
