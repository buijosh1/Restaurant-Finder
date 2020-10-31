#include "Cities.hpp"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Map::addVertex(string name){
  City* newCity = new City; // Allocates memory for new city

  newCity->name = name; // Sets the name to the one given
  cities.push_back(newCity); // Adds new city to end of vector
}

void Map::addEdge(string city1, string city2, int num){
  adjCity* newEdge = new adjCity; // New edge variable

  for(int i=0; i<cities.size(); i++){ // Runs for loop until end of vector
    if(cities[i]->name == city1){ // If the name in the vector matches the one being passed
      for(int j=0; j<cities.size(); j++){
        if(cities[j]->name == city2 && i!=j){ // Finds the second city in the vector
          newEdge->v = cities[j];
          newEdge->weight = num;
          cities[i]->adj.push_back(*newEdge);

          newEdge->v = cities[i];
          newEdge->weight = num;
          cities[j]->adj.push_back(*newEdge);
        }
      }
    }
  }
}

void Map::displayEdges(){
  for(unsigned int i=0; i<cities.size(); i++){ // Goes to each city vertex
    cout << cities[i]->name << "-->";
    for(unsigned int j=0; j<cities[i]->adj.size(); j++){ // Goes to each adjacent city vertex
      cout << cities[i]->adj[j].v->name << " ";
    }
    cout << endl;
  }
}

City* Map::DijkstraAlgorithm(string start, string end){
  City* endVertex = new City;
  City* startVertex = new City;
  City* solvedVertex = new City;
  City* parent = new City;
  City* s = new City;

  int minDistance, dist;

  City* visitedArray[cities.size()];

  for(int i=0; i<cities.size(); i++){ // Sets all value of the array to NULL
    visitedArray[i] = NULL;
  }

  for(unsigned int i=0; i<cities.size(); i++){ // Finds end adjCity
    if(cities[i]->name == end){
      endVertex = cities[i];
      break;
    }
  }

  for(unsigned int i=0; i<cities.size(); i++){ // Finds starting city
    if(cities[i]->name == start){
      startVertex = cities[i];
      break;
    }
  }

  visitedArray[0] = startVertex;
  int count = 1; // Counter for visitedArray index

  while(endVertex->visited == false){
    minDistance = 9999;
    solvedVertex = NULL;

    for( int i=0; i < cities.size(); i++){ // Traverses through each vertex
      if(visitedArray[i] != NULL){ // Makes sure the index isn't null
        s = visitedArray[i]; // s is set to the vertex at i

        for(unsigned int j=0; j < s->adj.size(); j++){ // Traverses through each adjacent vertex
          if(s->adj[j].v->visited == false){ // If the adjacent vertex is false
            dist = s->distance + s->adj[j].weight; // Dist is the vertex distance and adjacent vertex weigth added

            if(dist < minDistance){ // Checks through each adjacent vertex and sets the minDistance if true
              solvedVertex = s->adj[j].v;
              minDistance = dist;
              parent = s;
            }
          }
        }
      }
    }
    solvedVertex->distance = minDistance;
    solvedVertex->pred = parent;
    solvedVertex->visited = true;
    visitedArray[count] = solvedVertex; // Adds to the solved array
    count ++;
  }
  return endVertex;
}

City* Map::shortestpath(string s1, string s2){
  City* startVertex = new City;
  City* endVertex = new City;
  City* tempPrint = new City;
  stack <City*> s;

  for(unsigned int i=0; i<cities.size(); i++){ // Finds the end in the vector
    if(cities[i]->name == s2){
      endVertex = cities[i]; // Sets the endVertex
      break;
    }
    // else if(cities[i] == cities.back()){
    //   cout << "We can not find the city that you are located at, please enter a valid city." << endl;
    // }
  }
  for(unsigned int i=0; i<cities.size(); i++){ // Finds the start in the vector
    if(cities[i]->name == s1){
      startVertex = cities[i]; // Sets the startVertex
      break;
    }
    // else if(cities[i] == cities.back()){
    //   cout << "We can not find the city that you are traveling to, please enter a valid city." << endl;
    // }
  }

  while(endVertex->name != startVertex->name){
    s.push(endVertex);
    endVertex = endVertex->pred;
  }

  cout << "You will have to travel from: ";
  cout << startVertex->name << " || " <<" Through: ";

  while(!s.empty()){
    cout << s.top()->name << " ";
    tempPrint = s.top();
    s.pop();
  }
  return tempPrint;
}

void Map::printGraph(){
  for(unsigned int i=0; i<cities.size(); i++){
    cout << "City: " << cities[i]->name << " || "<< " Connected Cities: ";
    for(unsigned int j=0; j<cities[i]->adj.size(); j++){
      cout << cities[i]->adj[j].v->name << " ";
    }
    cout << endl;
  }
}

City* Map::findVertex(string city){
  for(unsigned int i=0; i<cities.size(); i++){
    if(city == cities[i]->name){
      return cities[i];
      break;
    }
  }
  cout << "Can't find the city" << endl;
}

void Map::addRestaurantTypes(string city, string type1, string type2, string type3){
  City* tempCity = findVertex(city); // Finds city to add types

  for(int i=0; i<3; i++){
    tempCity->types[i] = new restType;
    tempCity->types[i]->next = NULL;
  }

  tempCity->types[0]->name = type1;
  tempCity->types[1]->name = type2;
  tempCity->types[2]->name = type3;
}

void Map::insertRestaurant(string city, string type, string restaurantName, float ratings, string address, string hours){
  City* tempCity = findVertex(city);
  bool found = false;
  restInfo* restIterate = new restInfo;
  restType* rType = new restType;

  restInfo* tempRest = new restInfo;
  tempRest->name = restaurantName;
  tempRest->ratings = ratings;
  tempRest->address = address;
  tempRest->hours = hours;


  for(int i=0; i<3; i++){ // Goes through array to find the type
    if(tempCity->types[i]->name == type){
      rType = tempCity->types[i];
    }
  }

  if(rType->next == NULL){ // If there's no restaurant yet
    rType->next = tempRest;
    tempRest->next = NULL;
  }
  else{ // If there are restaurants added already

    restIterate = rType->next;
    while(found == false){
      if(restIterate->next != NULL){ // Next LL has a restaurant already
        restIterate = restIterate->next;
      }
      else{
        restIterate->next = tempRest;
        tempRest->next = NULL;
        found = true;
      }
    }
  }
}

void Map::printRestaurants(){
  restType* rType;
  restInfo* restIterate;

  for(unsigned int i=0; i<cities.size(); i++){
    cout << "City: " << cities[i]->name << endl;
    City* tempCity = cities[i];

    for(int j=0; j<3; j++){ // Goes through each type in array
      cout << tempCity->types[j]->name << ": ";

      restIterate = tempCity->types[j]->next;

      while(restIterate != NULL){
        if(restIterate->next != NULL){
          cout << restIterate->name << " (" << restIterate->ratings << "/5" << ")"<< ", ";
        }
        else{
          cout << restIterate->name<< " (" << restIterate->ratings << "/5" << ")";
        }
        restIterate = restIterate->next;
      }
      cout << endl;
    }
    cout << endl;
  }
}
