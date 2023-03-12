// Classe Personne2 pour l'exercice 6 du TP2C++

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
    Personne *Conj;
    string nomConj;
    string nomusage;

        public :
        // Constructeur
        Personne(string s, string p, string n, int a)
    {
        nom = n;
        prenom = p;
        anneeNaissance = a;
        sexe = s;
        Conj = NULL;
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

    string getStatut()
    {
        if (Conj == NULL)
        {
            return NULL;
        }
        else
        {
            return "Marié(e)";
        }
    }

    string getnomUsage(){
        return nomusage;
    }

    string getnomUsageConj(){
        return nomConj;
    }

    // Methode

    int Age(int anneNai)
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int year_now = 1900 + ltm->tm_year;
        return year_now - anneNai;
    }

    void marier(Personne *p, string nomUsage, string nomUsageConj)
    {
        if (p->getStatut() == "Célibataire")
        {
            cout << "ERROR" << endl;
        }
        else
        {
            Conj = p;
            nomusage = nomUsage;
            nomConj = nomUsageConj;
            p.setStatut(this);
            p.set
        }
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

    void setStatut(Personne *p){
        Conj = p;
    }

    void setnomUsage(string s){
        nomusage = s;
    }

    void setnomUsageConj(string s){
        nomConj = s;
    }



    // Méthode pour afficher les informations
    void afficherInfos()
    {
        if(getStatut()==NULL){
        cout << sexe << ". " << prenom << " " << nom << " est né en " << anneeNaissance << "célibataire " endl;
        }else{
            cout << sexe << ". " << prenom << " " << nom << " est né en " << anneeNaissance << " ayant comme nom d'usage " << nomusage <<", marié(e) avec " << Conj.getSexe() << " " <<  Conj.getNom() << "utilisant le nom " << getnomUsageConj() endl;
        }
    }
};
