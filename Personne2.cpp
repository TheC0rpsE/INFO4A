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
    bool marie;
    string nomConj;
    string nomusage;

public:
    // Constructeur
    Personne(string s, string p, string n, int a)
    {
        nom = n;
        prenom = p;
        anneeNaissance = a;
        nomusage = n;
        sexe = s;
        marie = false;
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

    bool getConj()
    {
        if (marie)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string getnomUsage()
    {
        return nomusage;
    }

    string getnomUsageConj()
    {
        return nomConj;
    }

    // Methode

    int Age(int anne)
    {
        return anne - anneeNaissance;
    }

    void marier(Personne *p, string nomUsage, string nomUsageConj)
    {
        if (marie || p->getConj())
        {
            cout << "Erreur : une des deux personnes est déjà mariée" << endl;
            return;
        }

        marie = true;
        nomusage = nomUsage;
        Conj = p;
        p->setMarie(true);
        p->setnomUsage(nomUsageConj);
        p->setConj(this);
        p->setnomUsageConj(nomUsage);
    }

    // Mutateurs
    void setNom(string n)
    {
        nom = n;
    }

    void setMarie(bool b)
    {
        marie = b;
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

    void setConj(Personne *p)
    {
        Conj = p;
    }

    void setnomUsage(string s)
    {
        nomusage = s;
    }

    void setnomUsageConj(string s)
    {
        nomConj = s;
    }

    // Méthode pour afficher les informations
    void afficherInfos()
    {
        if (getConj() == false)
        {
            cout << sexe << ". " << prenom << " " << nom << " est né en " << anneeNaissance << " est célibataire " << endl;
        }
        else
        {
            cout << sexe << ". " << prenom << " " << nom << " est né en " << anneeNaissance << " ayant comme nom d'usage " << nomusage << ", marié(e) avec " << Conj->getSexe() << " " << Conj->getNom() << " utilisant le nom d'usage " << Conj->getnomUsage() << endl;
        }
    }
};

int main()
{
    Personne p("M", "Pierre", "Holly", 1965);
    Personne q("Mme", "Jeanne", "Martin", 1975);
    Personne s("M", "Gille", "Forêt", 1988);
    p.afficherInfos();
    q.afficherInfos();
    s.afficherInfos();

    p.marier(&q, "Holly", "Holly");
    p.afficherInfos();
    return 0;
}