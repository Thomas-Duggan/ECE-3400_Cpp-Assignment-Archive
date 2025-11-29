#include "restaurant.hpp"


////////////// Restaurant //////////////
Restaurant::Restaurant(string name, int year) 
:r_name(name), 
year_open(year)
{}

void Restaurant::set_name(string name){
    r_name = name;
}

int Restaurant::year(){
    return year_open;
}
void Restaurant::set_year(int year){
    year_open = year;
}

void Restaurant::print(){
    cout << r_name << " EST. " << year_open << endl;
}


////////////// Eat In Restaurant //////////////

EatInRestaurant::EatInRestaurant(string name, int year, int capacity) 
:Restaurant(name, year), 
max_patrons(capacity) 
{}

int EatInRestaurant::get_patrons(){
    return max_patrons;
}

void EatInRestaurant::set_patrons(int capacity){
    max_patrons = capacity;
}    

void EatInRestaurant::print(){
    cout << r_name << " EST. " << year_open << " (" << max_patrons << " seats)" << endl;
}


////////////// Delivery Restaurant //////////////

DeliveryRestaurant::DeliveryRestaurant(string& name,  int& year, int& distance)
:Restaurant(name, year),
max_deliverydistance(distance) 
{}

int DeliveryRestaurant::get_maxdeldist() {
    return max_deliverydistance;
}

void DeliveryRestaurant::set_maxdeldistance(int distance) {
    max_deliverydistance = distance;
}

void DeliveryRestaurant::print() {
    cout << r_name << " EST. " << year_open << " (delivers up to " << max_deliverydistance << " km)" << endl;
}


////////////// Hybrid Restaurant //////////////

HybridRestaurant::HybridRestaurant(string name, int year, int capacity, int distance)
:Restaurant(name, year),
/*parameters should change the order and it should fallow the order in the initializer list
max_deliverydistance(distance),
max_patrons(capacity) */
max_patrons(capacity),
max_deliverydistance(distance)
{}

int HybridRestaurant::get_patrons(){
    return max_patrons;
}

void HybridRestaurant::set_patrons(int capacity){
    max_patrons = capacity;
}    

int HybridRestaurant::get_maxdeldist() {
    return max_deliverydistance;
}

void HybridRestaurant::set_maxdeldistance(int distance) {
    max_deliverydistance = distance;
}

void HybridRestaurant::print() {
    cout << r_name << " EST. " << year_open
        << " (" << max_patrons << " seats, delivers up to "
        << max_deliverydistance << " km)" << endl;
}