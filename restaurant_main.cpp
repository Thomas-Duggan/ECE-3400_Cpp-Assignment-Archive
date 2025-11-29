// Copyright (c) 2025 Thomas Duggan and Tadiwanashe Chimuputi
// This work is licensed under CC BY-SA 4.0

#include "restaurant.cpp"

int main(){

    // Determines size of array
    int chainSize;
    cout << "Resteraunt Chain Size: ";
    cin >> chainSize;
    cout << endl << endl;
    
    // Info for upcoming questions
    cout << "Resteraunt Types: \n  U = Undefined \n  E = Eat In \n  D = Delivery \n  H = Hybrid";
    cout << endl << endl;

    // Creation of array
    // This is pointer dynamic array (Class ** var == new Class * [])
    Restaurant ** resteraunts = new Restaurant * [chainSize];

    // Array allocation
    for (int i = 0; i < chainSize; i++){
        //resteraunts[i] = nullptr;

        string type;
        cout << "Resteraunt Type (U/E/D/H): ";
        cin >> type;

        string name;
        cout << "Resteraunt Name: ";
        cin >> name;

        int year;
        cout << "Resteraunt Year: ";
        cin >> year;

        if (type == "U") {
            resteraunts[i] = new Restaurant(name, year); // creates pointer of class object
        }
        else if (type == "E"){
            int capacity;
            cout << "Resteraunt Capacity: ";
            cin >> capacity;

            resteraunts[i] = new EatInRestaurant(name, year, capacity); // creates pointer of class object
        }
        else if (type == "D"){
            int distance;
            cout << "Resteraunt Distance: ";
            cin >> distance;

            resteraunts[i] = new DeliveryRestaurant(name, year, distance); // creates pointer of class object
        }
        else if (type == "H"){
            int capacity;
            cout << "Resteraunt Capacity: ";
            cin >> capacity;

            int distance;
            cout << "Resteraunt Distance: ";
            cin >> distance;

            resteraunts[i] = new HybridRestaurant(name, year, capacity, distance); // creates pointer of class object
        }
    }

    //////////////////////////// Outputs ////////////////////////////

    cout << " Restaurant Chain\n";
    for (int i = 0; i < chainSize; i++) {
        resteraunts[i]->print();  // from resteraunts, run it's print function
    }

    // Deletes for each "new" operator
    for (int i = 0; i < chainSize; i++) {
        delete resteraunts[i];
    }
    delete[] resteraunts;
}
