#include <iostream>
#include "RestaurantIO.hpp"
using namespace std;

int main() {
  vector<Restaurant> restaurantDatabase;
  const string databaseFile = "restaurants.txt";

  loadDatabase(restaurantDatabase, databaseFile);

  int userChoice;
  do {
    cout << "\n--- Restaurant Database ---\n"
         << "1. Add Restaurant\n"
         << "2. View Restaurants\n"
         << "3. Save & Exit\n"
         << "Choice: ";
    cin >> userChoice;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid choice.\n";
      continue;
    }

    switch (userChoice) {
      case 1:
        addRestaurant(restaurantDatabase);
        break;
      case 2:
        displayRestaurants(restaurantDatabase);
        break;
      case 3:
        saveDatabase(restaurantDatabase, databaseFile);
        cout << "Data saved. Goodbye!\n";
        break;
      default:
        cout << "Please choose a valid option (1–3).\n";
    }
  } while (userChoice != 3);

  return 0;
}
