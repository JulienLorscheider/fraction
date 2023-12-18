#include "Fraction.h"
#include "ParseurFraction.h"
#include <iostream>
#include <sstream>

// Parseur concret pour le format "(num, den)"
class ParseurParentheses : public ParseurFraction
{
public:
    ParseurParentheses(ParseurFraction *suivant) : ParseurFraction(suivant) {}
    virtual Fraction *parser(const std::string &input) const override
    {
        std::istringstream stream(input);
        char parentheseOuvrante, virgule, parentheseFermante;
        int num, den;

        stream >> parentheseOuvrante >> num >> virgule >> den >> parentheseFermante;

        if (!stream.fail() && parentheseOuvrante == '(' && virgule == ',' && parentheseFermante == ')')
        {
            return new Fraction(num, den);
        }
        else if (parseurSuivant)
        {
            return parseurSuivant->parser(input);
        }

        return nullptr;
    }
};