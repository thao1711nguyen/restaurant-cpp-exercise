#pragma once
#include <string>
#include <vector>
using namespace std;

class Restaurant {
private:
  int id;
  string name;
  string cuisine;
  vector<string> menuItems;  
  
public:
  Restaurant();
  Restaurant(int id, string name, string cuisine);

  void addMenuItem(const string& menuItemEntry);
  int getId() const;
  const string& getName() const;
  const string& getCuisine() const;
  const vector<string>& getMenu() const;

  friend ostream& operator<<(ostream& outputStream, const Restaurant& restaurant);
  friend istream& operator>>(istream& inputStream, Restaurant& restaurant);
};
