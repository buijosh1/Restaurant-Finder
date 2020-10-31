#include "Cities.hpp"
#include "structHeader.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void displayMenu();

int main(int argc, char const *argv[]){
  Map city;
  int input;
  string cityInput, travelInput;
  City* distanceRet;
  City* currentDest;
  City* travelDest;
  restInfo* restIterate;
  // MAP CREATION
  city.addVertex("Denver");
  city.addVertex("Colorado Springs");
  city.addVertex("Aurora");
  city.addVertex("Fort Collins");
  city.addVertex("Lakewood");

  city.addEdge("Denver", "Colorado Springs", 69);
  city.addEdge("Denver", "Aurora", 17);
  city.addEdge("Denver", "Fort Collins", 66);
  city.addEdge("Denver", "Lakewood", 8);
  city.addEdge("Colorado Springs", "Aurora", 68);
  city.addEdge("Fort Collins", "Lakewood", 70);

//----------------------------------------------------------------------------//
  // ADD RESTAURANTS
  city.addRestaurantTypes("Denver", "American", "Mexican", "Japanese");
  city.addRestaurantTypes("Colorado Springs", "American", "Italian", "Indian");
  city.addRestaurantTypes("Aurora", "American", "Vietnamese", "Korean");
  city.addRestaurantTypes("Fort Collins", "Italian", "Japanese", "Chinese");
  city.addRestaurantTypes("Lakewood", "American", "Mexican", "Thai");

  city.insertRestaurant("Denver", "American", "Work & Class", 4.5, "2500 Larimer St., Denver, CO 80205", "4:00 pm - 10:00 pm");
  city.insertRestaurant("Denver", "American", "Jack's Uptown Grille", 4, "1600 East 17th Ave, Denver, CO 80218", "11:00 am - 9:00 pm");
  city.insertRestaurant("Denver", "American", "The Rotary", 5, "3200 N. Pecos St., Denver, CO 80211", "11:00 am - 9:00 pm");

  city.insertRestaurant("Denver", "Mexican", "La Loma", 4, "1801 Broadway Unit 116, Denver, CO 80202", "11:00 am - 10:00 pm");
  city.insertRestaurant("Denver", "Mexican", "Mezcal", 3.5, "3230 E. Colfax Ave., Denver, CO 80206", "11:00 am - 1:00 am");
  city.insertRestaurant("Denver", "Mexican", "Little Anita's", 4, "1550 S. Colorad Blvd., Denver, CO 80222", "6:00 am - 9:00 pm");

  city.insertRestaurant("Denver", "Japanese", "Domo Japanese Country Food Restaurant", 3.5, "1365 Osage St., Denver, CO 80204", "11:00 am - 2:00 pm / 5:00 pm - 10:00 pm");
  city.insertRestaurant("Denver", "Japanese", "Ototo", 4.5, "1501 S. Pearl St., Denver, CO 80210", "4:30 pm - 10:00 pm");
  city.insertRestaurant("Denver", "Japanese", "Gyu-Kaku Japanese BBQ", 4, "1998 18th St., Denver, CO 80202", "11:00 am - 10:15 pm");

  city.insertRestaurant("Colorado Springs", "American", "Phantom Canyon", 4, "2 E. Pikes Peak Ave., Colorado Springs, CO 80903", "11:00 am - 2:00 am");
  city.insertRestaurant("Colorado Springs", "American", "503W", 4, "503 W. Colorado Ave., Colorado Springs, CO 80905", "11:00 am - 10:00 pm");
  city.insertRestaurant("Colorado Springs", "American", "Shuga's", 4.5, "702 S. Cascade Ave., Colorado Springs, CO 80903", "11:00 am - 12:00 am");

  city.insertRestaurant("Colorado Springs", "Italian", "Panion's Eastside", 3.5, "3015 New Center Pt., Colorado Springs, CO 80922", "11:00 am - 9:00 pm");
  city.insertRestaurant("Colorado Springs", "Italian", "Paravicini's", 4, "2802 W. Colorado Ave., Colorado Springs, CO 80904", "11:00 am - 9:00 pm");
  city.insertRestaurant("Colorado Springs", "Italian", "La Bella Vita Ristorante Italiano", 4.5, "4475 Northpark Dr., Colorado Springs, CO 80907", "11:00 am - 2:00 pm / 4:00 pm - 9:00 pm");

  city.insertRestaurant("Colorado Springs", "Indian", "Urban Tandoor", 3, "8125 N. Academy Blvd., Colorado Springs, CO 80920", "11:00 am - 9:00 pm");
  city.insertRestaurant("Colorado Springs", "Indian", "Zaika Indian Cuisine", 4.5, "4661 Centennial Blvd., Colorado Springs, CO 80919", "11:30 am - 9:00 pm");
  city.insertRestaurant("Colorado Springs", "Indian", "Little Nepal: Indian Restaurant & Bar", 4, "1747 S. 8th St., Colorado Springs, CO 80905", "11:30 am - 2:30 pm / 4:30 pm - 9:00 pm");

  city.insertRestaurant("Aurora", "American", "Jackdaw", 4.5, "13696 E. Iliff Pl., Aurora, CO 80014", "11:00 am - 11:00 pm");
  city.insertRestaurant("Aurora", "American", "The Bent Fork", 4, "12191 E. Iliff Ave., Aurora, CO 80014", "11:00 am - 9:00 pm");
  city.insertRestaurant("Aurora", "American", "Bubba's 33", 4, "2270 S. Parker Rd., Aurora, CO 80231", "4:00 pm - 11:00 pm");

  city.insertRestaurant("Aurora", "Vietnamese", "Pho 888", 4.5, "539 N. Sable Blvd., Aurora, CO 80011", "10:00 am - 9:00 pm");
  city.insertRestaurant("Aurora", "Vietnamese", "Golden Saigon", 4.5, "2548 S. Parker Rd., Aurora, CO 80014", "11:00 am - 9:00 pm");
  city.insertRestaurant("Aurora", "Vietnamese", "5280 Banh Mi and Grill", 4.5, "15473 E. Hampden Ave. Unit A, Aurora, CO 80013", "11:00 am - 8:00 pm");

  city.insertRestaurant("Aurora", "Korean", "Seoul Korean BBQ & Hot Pot", 4, "2080 S. Havana St., Aurora, CO 80014", "11:00 am - 10:00 pm");
  city.insertRestaurant("Aurora", "Korean", "Tofu House", 4, "2385 S. Havana St. Unit D1, Aurora, CO 80014", "11:00 am - 10:00 pm");
  city.insertRestaurant("Aurora", "Korean", "Woo Ri", 5, "2648 S. Parker Rd. Ste. 9, Aurora, CO 80014", "11:00 am - 10:00 pm");

  city.insertRestaurant("Fort Collins", "Italian", "The Twisted Noodle", 4.5, "1335 W. Elizabeth St., Fort Collins, CO 80521", "11:00 am - 8:30 pm");
  city.insertRestaurant("Fort Collins", "Italian", "Oregano's Pizza Bistro", 4.5, "4235 S. College Ave., Fort Collins, CO 80525", "11:00 am - 9:00 pm");
  city.insertRestaurant("Fort Collins", "Italian", "Nick's Italian", 4, "1100 S. College Ave., Fort Collins, CO 80524", "11:00 am - 9:00 pm");

  city.insertRestaurant("Fort Collins", "Japanese", "White Tree", 4.5, "1015 S. Taft Hill Rd., Fort Collins, CO 80521", "11:00 am - 9:30 pm");
  city.insertRestaurant("Fort Collins", "Japanese", "Jaws Sushi", 4, "1205 W. Elizabeth St., Fort Collins, CO 80521", "11:00 am - 9:30 pm");
  city.insertRestaurant("Fort Collins", "Japanese", "Jeju", 3.5, "238 S. College Ave., Fort Collins, CO 80524", "11:00 am - 9:30 pm");

  city.insertRestaurant("Fort Collins", "Chinese", "Beijing Noodle", 4.5, "1005 W. Stuart St., Fort Collins, CO 80521", "11:00 am - 8:00 pm");
  city.insertRestaurant("Fort Collins", "Chinese", "Sally's Kitchen", 4, "4727 S. Timberline Rd., Fort Collins, CO 80528", "11:00 am - 9:30 pm");
  city.insertRestaurant("Fort Collins", "Chinese", "Dragon Lee", 3.5, "1231 W. Elizabeth St., Fort Collins, CO 80521", "11:00 am - 9:00 pm");

  city.insertRestaurant("Lakewood", "American", "Westrail Tap & Grill", 4, "195 S. Union Blvd., Lakewood, CO 80228", "11:00 am - 11:00 pm");
  city.insertRestaurant("Lakewood", "American", "Blue Pebble", 4.5, "689 Santa Fe Dr., Lakewood, CO 80204", "11:30 am - 9:00 pm");
  city.insertRestaurant("Lakewood", "American", "Mac & Cheezary", 4.5, "3895 Wadsworth Blvd., Lakewood, CO 80033", "11:00 am - 8:00 pm");

  city.insertRestaurant("Lakewood", "Mexican", "Las Dalias", 4, "7800 W. Jewell, Lakewood, CO 80232", "8:30 am - 9:00 pm");
  city.insertRestaurant("Lakewood", "Mexican", "El Torito", 4, "180 S. Union Blvd., Lakewood, CO 80228", "8:00 am - 9:30 pm");
  city.insertRestaurant("Lakewood", "Mexican", "Moose Hill Cantina", 4, "11911 W. Colfax, Lakewood, CO 80215", "10:30 am - 8:45 pm");

  city.insertRestaurant("Lakewood", "Thai", "Farmhouse Thai Eatery", 4.5, "98 Wadsworth Blvd., Lakewood, CO 80226", "11:00 am - 9:00 pm");
  city.insertRestaurant("Lakewood", "Thai", "Bangkok Thai Food", 4, "2099 Wadsworth Blvd., Lakewood, CO 80214", "11:00 am - 9:00 pm");
  city.insertRestaurant("Lakewood", "Thai", "Thai Diamond Cafe", 4, "1560 Kipling St., Lakewood, CO 80215", "11:00 am - 9:00 pm");

  // -----------------------------------------------------------------------------------------------------------------------------------//
  // User Interface

  displayMenu();
  do {
    cin >> input;
    switch (input) {
      // PRINTS CITIES AND CONNECTED CITIES
      case 1:
        city.printGraph();

        displayMenu();
        break;

      case 2:
        city.printRestaurants();

        displayMenu();
        break;

      case 3:
        cout << "What city are you located at: ";
        cin.ignore();
        getline(cin, cityInput);

        cout << endl;
        cout << "What city do you want to travel to: ";
        getline(cin, travelInput);
        cout << endl;

        city.DijkstraAlgorithm(cityInput, travelInput);
        distanceRet = city.shortestpath(cityInput, travelInput);
        cout << endl;
        cout << "The shortest distance you will have to travel " << distanceRet->distance << " miles to your destination." << endl;
        cout << endl;

        currentDest = city.findVertex(cityInput);
        travelDest = city.findVertex(travelInput);

        cout << "The restaurants located in " << travelInput << " are: " << endl << endl;
        for(int j=0; j<3; j++){ // Goes through each type in array
          cout << travelDest->types[j]->name << ": ";

          restIterate = travelDest->types[j]->next;

          while(restIterate != NULL){
            // if(restIterate->next != NULL){
              cout << endl << restIterate->name << " (" << restIterate->ratings << "/5" << ")"<< " || " << "Store Hours: " << restIterate->hours << " || " << "Store Address: " << restIterate->address;
            // }
            // else{
            //   cout << endl << restIterate->name << "(" << restIterate->ratings << "/5" << ")";
            // }
            restIterate = restIterate->next;
          }
          cout << endl << endl;
        }

      default:
        displayMenu();
    }
  } while(input != 4);
  cout << "Thank you! Goodbye!" << endl;

  return 0;
}

void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Print City Map" << endl;
    cout << " 2. Print Restaurant" << endl;
    cout << " 3. Travel" << endl;
    cout << " 4. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
