#ifndef CITIES_H
#define CITIES_H
#include "structHeader.hpp"
#include <iostream>
#include <vector>

using namespace std;

// CITY MAP CREATION USING GRAPH STRUCTURE
class Map
{
  public:
    void addEdge(string city1, string city2, int num);
    void addVertex(std::string name);
    void displayEdges();
    City* DijkstraAlgorithm(string start, string end);
    City* shortestpath(string s1, string s2);
    void addRestaurantTypes(string city, string type1, string type2, string type3);
    City* findVertex(string city);
    bool isEmpty();
    void insertRestaurant(string city, string type, string restaurantName, float ratings, string address, string hours);
    void printGraph();
    void printRestaurants();

  private:
    //restType* types[10];
    vector<City*> cities;
};

#endif
