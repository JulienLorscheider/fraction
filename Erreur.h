#pragma once
/**
classe Erreur
*/
using namespace std;

#include <string>
#include <iostream>

class Erreur
{
public:
    const static int LONGUEURMESSAGE = 500;
    char message[1 + LONGUEURMESSAGE];
    Erreur();
    Erreur(const char *messageErreur);

    operator string() const;
};

ostream &operator<<(ostream &os, const Erreur &erreur);

Erreur::Erreur()
{
    strcpy(this->message, "Erreur !");
}

Erreur::Erreur(const char *messageErreur)
{
    strcpy(this->message, "Erreur : ");
    int l = strlen(messageErreur);
    static int n = LONGUEURMESSAGE - 9;
    if (l <= n)
        strcat(this->message, messageErreur);
    else
    {
        strncat(this->message, messageErreur, n);
        this->message[LONGUEURMESSAGE] = '\0';
    }
}

Erreur::operator string() const
{
    return string(this->message);
}

ostream &operator<<(ostream &os, const Erreur &erreur)
{
    os << (string)erreur;
    return os;
}