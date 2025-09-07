#include "RestaurantIO.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

void addRestaurant(vector<Restaurant>& database) {
  int restaurantId, menuItemCount;
  string restaurantName, cuisineType;
  cout << "Enter restaurant ID: ";
  cin >> restaurantId;
  if (cin.fail()) {
    cout << "Invalid input." << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    return;
  }
  cout << "Enter restaurant name: ";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, restaurantName);
  cout << "Enter cuisine type: ";
  getline(cin, cuisineType);
  Restaurant restaurant(restaurantId, restaurantName, cuisineType);
  cout << "Enter the number of menu items: ";
  cin >> menuItemCount;
  if (cin.fail() || menuItemCount < 0) {
    cout << "Invalid number." << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    return;
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  for(int i=0; i<menuItemCount; i++) {
    string itemName;
    double itemPrice;
    string itemPriceInput;
    cout << "Enter item " << i << " name: ";
    getline(cin, itemName);
    cout << "Enter item " << i << " price: ";
    getline(cin, itemPriceInput);
    itemPrice = stod(itemPriceInput);
    cout << endl;
    if(cin.fail() || itemPrice < 0) {
      cout << "Invalid price." << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    };
    stringstream itemEntryStream; 
    itemEntryStream << itemName << fixed << setprecision(2) << itemPrice;
    restaurant.addMenuItem(itemEntryStream.str());
  }
  database.push_back(restaurant);
}

void displayRestaurants(const vector<Restaurant>& database) {
  for (const auto& restaurant : database) {
    cout << "\nID: " << restaurant.getId()
         << "\nName: " << restaurant.getName()
         << "\nCuisine: " << restaurant.getCuisine()
         << "\nMenu:\n";

    for (const auto& menuItemEntry : restaurant.getMenu()) {
      cout << "  - " << menuItemEntry << '\n';
    }
  }
}

bool loadDatabase(vector<Restaurant>& database, const string& filename) {
  ifstream inputFile(filename);
  if(!inputFile.good()) {
    cout << "[WARN] Could not open " << filename << " for reading." << endl;
    return false;
  };
  Restaurant restaurant;
  while(inputFile >> restaurant) {
    database.push_back(restaurant);
  }
  return true;
}

void saveDatabase(const vector<Restaurant>& database, const string& filename) {
  ofstream outputFile(filename);
  if(!outputFile.is_open()) {
    cerr << "[ERR] Could not open " << filename << " for writing." << endl; 
    return;
  };
  for(const Restaurant& restaurant : database) {
    outputFile << restaurant << endl;
  }
  outputFile.close();
}
