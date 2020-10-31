#ifndef STRUCT_HEADER
#define STRUCT_HEADER

#include <iostream>
#include <vector>

using namespace std;

// RESTAURANT CHOICES ARE STORED IN AN ARRAY WITH LINKED LIST
struct restInfo{
  string name;
  float ratings;
  std::string address;
  std::string hours; // Opening and closing hours
  restInfo *next;
};

struct restType{
  string name;
  restInfo *next;
};

// CITY STRUCTS TO BUILD MAP
struct City;
struct adjCity{
  City *v;
  int weight;
};

struct City{
  City(){
    this->visited = false;
    this->distance = 0;
    this->pred = NULL;
  }
  string name;
  bool visited;
  int distance;
  City *pred;
  vector<adjCity> adj;
  restType* types[3];
};

#endif
