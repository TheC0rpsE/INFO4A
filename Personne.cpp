//Classe Personne pour pour l'exercice 1 à 5 du TP2C++

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Personne
{
private:
    string nom;
    string prenom;
    string sexe;
    int anneeNaissance;

public:
    // Constructeur
    Personne(string s, string p, string n, int a)
    {
        nom = n;
        prenom = p;
        anneeNaissance = a;
        sexe = s;
    }

    // Accesseurs
    string getNom()
    {
        return nom;
    }
    string getPrenom()
    {
        return prenom;
    }

    int getAnneeNaissance()
    {
        return anneeNaissance;
    }

    string getSexe()
    {
        return sexe;
    }

    int getAge()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int year_now = 1900 + ltm->tm_year;
        return year_now - anneeNaissance;
    }

    // Methode

    int Age(int anneNai)
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int year_now = 1900 + ltm->tm_year;
        return year_now - anneNai;
    }

    // Mutateurs
    void setNom(string n)
    {
        nom = n;
    }
    void setPrenom(string p)
    {
        prenom = p;
    }

    void setAnneeNaissance(int a)
    {
        anneeNaissance = a;
    }
    
    void setSexe(string s)
    {
        sexe = s;
    }
    // Méthode pour afficher les informations
    void afficherInfos()
    {
        cout << sexe << ". " << prenom << " " << nom << " est né en " << anneeNaissance << endl;
    }
};
