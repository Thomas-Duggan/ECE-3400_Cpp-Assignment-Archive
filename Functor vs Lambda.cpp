// Copyright (c) 2025 Thomas Duggan
// This work is licensed under CC BY-SA 4.0

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct sort_decending {
    bool operator()(double a, double b) {
        return a > b;
    }
};

int main(){
    vector<double> numbers;

    cout << "Enter values to create a list.\n Press Ctrl+Z to end.";

    double number;
    while (cin >> number) // Ctrl + Z is EoF
        numbers.push_back(number);

    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";

    // Functor Method:
    sort(numbers.begin(), numbers.end(), sort_decending());
    
    // Lambda Method:
    sort(numbers.begin(), numbers.end(), [](double a, double b)->bool{return a>b;});

    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";

}
