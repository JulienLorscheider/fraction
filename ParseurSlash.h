#include "Fraction.h"
#include "ParseurFraction.h"
#include <iostream>
#include <sstream>

// Parseur concret pour le format "(num, den)"
class ParseurSlash : public ParseurFraction
{
public:
    ParseurSlash(ParseurFraction *suivant) : ParseurFraction(suivant) {}
    virtual Fraction *parser(const std::string &input) const override
    {
        std::istringstream stream(input);
        char slash;
        int num, den;

        stream >> num >> slash >> den;

        if (!stream.fail() && slash == '/')
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