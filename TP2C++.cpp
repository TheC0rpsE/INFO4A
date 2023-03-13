#include "Personne"
#include <iostream>

int main() {
    Personne p("M", "Pierre", "Holly", 1965);
    Personne q("Mme","Jeanne","Martin",1975);
    Personne s("M","Gille","Forêt",1988);
    p.afficherInfos();
    q.affecherInfos();
    s.afficherinfos();
    return 0;
}