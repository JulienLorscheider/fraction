#include <string>
#include "Fraction.h"

class ParseurFraction
{
public:
    ParseurFraction *parseurSuivant;
    ParseurFraction(ParseurFraction *suivant) : parseurSuivant(suivant) {}
    virtual Fraction *parser(const std::string &input) const = 0;
};