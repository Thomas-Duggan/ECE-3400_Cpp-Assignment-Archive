// Copyright (c) 2025 Thomas Duggan
// This work is licensed under CC BY-SA 4.0


#include <iostream>

int main() {

    // Var initialization
    int num1, num2, final; 
    char operation;


//===============// Prompts //===============// 

    // Prompt for first number
    std::cout << "Enter first integer: ";
    std::cin >> num1;

    // Prompt for operator
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operation;

    // Prompt for second number
    std::cout << "Enter second integer: ";
    std::cin >> num2;


//===============// Calculations //===============//

    // Adds numbers and appends them to final
    if (operation == '+'){
        final = (num1 + num2);
    }

    // Subtracts numbers and appends them to final
    else if (operation == '-'){
        final = (num1 - num2);
    }

    // Multiplies numbers and appends them to final
    else if (operation == '*'){
        final = (num1 * num2);
    }

    // Divides numbers and appends them to final
    else if (operation ==  '/'){
        final = (num1 / num2);
    }
    
    // Returns a -1 in the event of an invalid operator
    else {
        std::cout << "Invalid Operator! \n";
        return -1;
    }
     
    std::cout << final << std::endl;
}