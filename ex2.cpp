#include <iostream>
#include<vector>
void afficherP(int& x, int seuil = 0) {
    if (x >= 0)
    std::cout << x << "\t";
}
void afficherN(int& x,int seuil = 0) {
    if (x < 0)
    std::cout << x << "\t";

}
void greaterThan(int& x, int seuil){
    if(x>=seuil)
    std::cout << x << "\t";

}
void appliquerFiltre(std::vector<int>& vec, void(*filtre)(int&,int)){
    int seuil=0;
    if (filtre == greaterThan) {
        std::cout << "Donner seuil:";
        std::cin >> seuil;
    }
    for (int& e : vec) {
        filtre(e,seuil);
    }
}
int main()
{
    std::vector<int> tab{ -2,19,-8,7,17,-122,3 };
    std::cout << "************************\n";
    std::cout << "* 1. Afficher positif *\n";
    std::cout << "* 2. Afficher Negatif *\n";
    std::cout << "* 3. Superieur A *\n";
    std::cout << "************************\n";
    std::cout << "Entrez votre choix?\n";
    int choix;
    std::cin >> choix;
    switch (choix){
        case 1: appliquerFiltre(tab, afficherP);
            break;
        case 2: appliquerFiltre(tab, afficherN);
            break;
        case 3:
            appliquerFiltre(tab, greaterThan);
        default:
            break;
        }
    return 0;
}