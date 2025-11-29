// Copyright (c) 2025 Thomas Duggan and Tadiwanashe Chimuputi
// This work is licensed under CC BY-SA 4.0


#include <iostream>
#include <vector>

using namespace std;
    

class Restaurant{ 

    public:
        // Constructor
        Restaurant(string name, int year);
    
        // Name Accessor
        string name();

        // Name Mutator
        void set_name(string name);

        // Year Accessor
        int year();

        // Year Mutator
        void set_year(int year);

        // Info Accessor
        virtual void print();

    protected:
        string r_name;
        int year_open;
};

// wee should specify the inheritance type as public here
class EatInRestaurant: public Restaurant{

    public:
        // Constructor
        EatInRestaurant(string name, int year, int capacity);

        // Patrons Accessor
        int get_patrons();

        // Patrons Mutator
        void set_patrons(int capacity);   

        // Info Accessor
        void print() override;

    private:
        int max_patrons;
};


class DeliveryRestaurant:public Restaurant {

    public:
        // Constructor
        DeliveryRestaurant(string& name, int& year, int& distance);

        // Delivery Distance Accessor
        int get_maxdeldist();

        // Delivery Distance Mutator
        void set_maxdeldistance(int distance);
        
        // Info Accessor
        void print() override;

    private:
        int max_deliverydistance;
};


class HybridRestaurant: public Restaurant{

    public:
        // Constructor
        HybridRestaurant(string name, int year, int capacity, int distance);
        
        // Delivery Distance Accessor
        int get_maxdeldist();

        // Delivery Distance Mutator
        void set_maxdeldistance(int distance);

        // Patrons Accessor
        int get_patrons();

        // Patrons Mutator
        void set_patrons(int capacity); 

        void print() override;

    private:
        int max_deliverydistance;
        int max_patrons;
};