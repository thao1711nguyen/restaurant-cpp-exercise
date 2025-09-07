#include "Restaurant.hpp"
#include <sstream>

Restaurant::Restaurant() : id(0) {}

Restaurant::Restaurant(int id, string name, string cuisine)
  : id(id), name(move(name)), cuisine(move(cuisine)) {}

void Restaurant::addMenuItem(const string& menuItemEntry) {
  menuItems.push_back(menuItemEntry);
}

int Restaurant::getId() const {
  return id;
}

const string& Restaurant::getName() const {
  return name;
}

const string& Restaurant::getCuisine() const {
  return cuisine;
}

const vector<string>& Restaurant::getMenu() const {
  return menuItems;
}

ostream& operator<<(ostream& outputStream, const Restaurant& restaurant) {
  outputStream << restaurant.id << "#" << restaurant.name << "#" << restaurant.cuisine << "#" << restaurant.menuItems.size() << "#";
  for(int i=0; i<restaurant.menuItems.size(); i++) {
    outputStream << restaurant.menuItems[i];
    if(i != (restaurant.menuItems.size() - 1)) {
      outputStream << "#";
    }
  }
  return outputStream;
}

istream& operator>>(istream& inputStream, Restaurant& restaurant) {
  string rawLine;
  restaurant.menuItems.clear();
  if(!getline(inputStream, rawLine)) {
    return inputStream;
  };
  stringstream lineStream(rawLine);
  string field;
  getline(lineStream, field, '#');
  restaurant.id = stoi(field);
  getline(lineStream, field, '#');
  restaurant.name = field;
  getline(lineStream, field, '#');
  restaurant.cuisine = field;
  getline(lineStream, field, '#');
  int itemCount = stoi(field);
  for(int i=0; i<itemCount; i++) {
    if(!getline(lineStream, field, '#')){
      return inputStream;
    } else {
      restaurant.menuItems.push_back(field);
    };

  }

  return inputStream;
}
