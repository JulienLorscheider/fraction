/**  Représente un nombre rationnel */

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Fraction
{
    int num;
    unsigned int den;

public:
    /**
    lance une exception de type Erreur si b == 0
    */
    Fraction(const int &a, const int &b);
    int getNum() const;
    unsigned int getDen() const;
    operator string() const;
};

ostream &operator<<(ostream &os, const Fraction &f);

/**
lance une exception de type Erreur si b == 0
*/
Fraction::Fraction(const int &a, const int &b)
{
    if (b == 0)
        throw Erreur("tentative de création d'une fraction de dénominateur nul");

    if (b > 0)
    {
        num = a;
        den = (unsigned int)b;
    }
    else
    {
        num = -a;
        den = (unsigned int)(-b);
    }
}

int Fraction::getNum() const
{
    return num;
}

unsigned int Fraction::getDen() const
{
    return den;
}

Fraction::operator string() const
{
    ostringstream oss;
    oss << num << "/" << den;
    return oss.str();
}

ostream &operator<<(ostream &os, const Fraction &f)
{
    return os << (string)f;
}