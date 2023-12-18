#include <vector>
#include <fstream>
#include <sstream>
#include "Fraction.h"
#include "Erreur.h"
#include "ParseurSlash.h"
#include "ParseurFraction.h"
#include "ParseurParentheses.h"
#include "ParseurPourcent.h"

class ChargeurListeFraction
{
public:
    vector<Fraction> charge(istream &fichier)
    {
        vector<Fraction> listeFractions;
        string ligne;

        while (getline(fichier, ligne))
        {
            try
            {
                Fraction *f = parseFraction(ligne);
                listeFractions.push_back(*f);
            }
            catch (const Erreur &e)
            {
                // Gérer l'erreur ou ignorer la ligne non conforme
                cout << e << endl;
            }
        }

        return listeFractions;
    }

private:
    Fraction *parseFraction(const string &ligne)
    {
        // Définir la chaîne de responsabilité des parseurs
        ParseurPourcent parseurPourcent(nullptr); // dernier parseur dans la chaîne
        ParseurSlash parseurSlash(&parseurPourcent);
        ParseurParentheses parseurParentheses(&parseurSlash);

        // Essayer de parser la ligne en utilisant le premier parseur
        return parseurParentheses.parser(ligne);
    }
};