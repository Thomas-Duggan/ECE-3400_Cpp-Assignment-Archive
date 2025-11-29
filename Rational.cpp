// Rational Fraction Calculator  Copyright (c) 2025  Thomas Duggan
// This work is licensed under CC BY-SA 4.0 


#include "Rational.hpp"


///////////////////////// INIT AND VALUE TRANSFER /////////////////////////

Rational::Rational(int numerator, int denominator){ // value initializer
    this->numerator   = numerator;   // default = 0 (see Rational.h)
    this->denominator = denominator; // default = 1 (see Rational.h)
}

Rational::Rational(Rational&& other){ // value moving
    this->numerator   = other.numerator;
    this->denominator = other.numerator;
}

Rational::Rational(const Rational& other){ // value cloning
    this->numerator   = other.numerator; 
    this->denominator = other.denominator;
}


///////////////////////// OPERATOR REPLACEMENTS /////////////////////////

Rational& Rational::operator=(const Rational&& other){ // equate using move constructor
    this->numerator   = other.numerator;
    this->denominator = other.denominator;
    return *this;
}; 

Rational& Rational::operator=(const Rational& other){ // equate using clone constructor
    this->numerator   = other.numerator;
    this->denominator = other.denominator;
    return *this;
}; 


/////// Creates a New Class and Replaces Default Values

Rational Rational::operator+(const Rational& other){ // add
    Rational add;
    add.numerator   = (this->numerator * other.denominator) + (this->denominator * other.numerator);
    add.denominator =  this->denominator * other.denominator;
    return add;
};

Rational Rational::operator-(const Rational& other){ // subtract
    Rational sub;
    sub.numerator   = (this->numerator * other.denominator) - (this->denominator * other.numerator);
    sub.denominator =  this->denominator * other.denominator;
    return sub;
};

Rational Rational::operator*(const Rational& other){ // multiply
    Rational mul;
    mul.numerator   = this->numerator * other.numerator;
    mul.denominator = this->denominator * other.denominator;
    return mul;
};

Rational Rational::operator/(const Rational& other){ // divide
    Rational div;
    div.numerator   = this->numerator * other.denominator;
    div.denominator = this->denominator * other.numerator;
    return div;
}; // Note: muliplies by flipped fraction


/////// Adds values to Current Class

Rational& Rational::operator+=(const Rational& other){ // add
    this->numerator    = (this->numerator * other.denominator) + (this->denominator * other.numerator);
    this->denominator *= other.denominator;
    return *this;
};

Rational& Rational::operator-=(const Rational& other){ // subtract
    this->numerator    = (this->numerator * other.denominator) - (this->denominator * other.numerator);
    this->denominator *= other.denominator;
    return *this;
};

Rational& Rational::operator*=(const Rational& other){ // multiply
    this->numerator   *= other.numerator;
    this->denominator *= other.denominator;
    return *this;
};

Rational& Rational::operator/=(const Rational& other){ // divide
    this->numerator   *= other.denominator;
    this->denominator *= other.numerator;
    return *this;
}; // Note: muliplies by flipped fraction


/////// IOStream Operator Replacements

istream& operator>>(istream& in, Rational& rational){ // cin
    return rational.scan(in);
}

ostream& operator<<(ostream& out, Rational& rational){ // cout
    return rational.print(out);
}


///////////////////////// SPECIAL FUNCTIONS /////////////////////////

double Rational::toDouble(){ // Converts fraction to numerical form
    return (double(this->numerator) / double(this->denominator));
}