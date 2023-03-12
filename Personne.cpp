#include <iostream>
#include <string>
#include<ctime>

using namespace std;

class Personne {
    private:
        string nom;
        string prenom;
        int sexe;
        int anneeNaissance;
    public:
        // Constructeur
        Personne(string t, string p, string n, int a) {
            titre = t;
            prenom = p;
            nom = n;
            anneeNaissance = a;
        }

        // Accesseurs
        string getNom() {
            return nom;
        }
        string getPrenom() {
            return prenom;
        }
        string getTitre() {
            return titre;
        }
        int getAnneeNaissance() {
            return anneeNaissance;
        }

        int getAge(){
            time_t now = time(0);
            tm *ltm = localtime(&now);
            int year_now = 1900 + ltm->tm_year;
            return year_now-anneeNaissance;
        }
        
        //Methode
        int Age(int anneNai){
            time_t now = time(0);
            tm *ltm = localtime(&now);
            int year_now = 1900 + ltm->tm_year;
            return year_now-anneNai;
        }

        // Mutateurs
        void setNom(string n) {
            nom = n;
        }
        void setPrenom(string p) {
            prenom = p;
        }
        void setTitre(string t) {
            titre = t;
        }
        void setAnneeNaissance(int a) {
            anneeNaissance = a;
        }

        // Méthode pour afficher les informations
        void afficherInfos() {
            cout << titre << ". " << prenom << " " << nom << " est né en " << anneeNaissance << endl;
        }
};

