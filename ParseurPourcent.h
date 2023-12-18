#include "Fraction.h"
#include "ParseurFraction.h"
#include <iostream>
#include <sstream>

// Parseur concret pour le format "(num, den)"
class ParseurPourcent : public ParseurFraction
{
public:
    ParseurPourcent(ParseurFraction *suivant) : ParseurFraction(suivant) {}
    virtual Fraction *parser(const std::string &input) const override
    {
        std::istringstream stream(input);
        char pourcent;
        int num;

        stream >> num >> pourcent;

        if (!stream.fail() && pourcent == '/')
        {
            return new Fraction(num, 100);
        }
        else if (parseurSuivant)
        {
            return parseurSuivant->parser(input);
        }

        return nullptr;
    }
};