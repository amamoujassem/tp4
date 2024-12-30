#include <iostream>
using namespace std;

struct Produit {
    string type;     
    double prixHT;   
    bool solde;      
};
double calculerPrix(const Produit& p) {
    double tauxTaxe = (p.type == "luxe") ? 0.25 : 0.19;  
    double prixTTC = p.prixHT * (1 + tauxTaxe);  

    if (p.solde) {
        prixTTC *= 0.80; 
    }

    return prixTTC;
}
int main() {
    Produit produit1;
    produit1.type = "standard";
    produit1.prixHT = 100;
    produit1.solde = true;  

    Produit produit2;
    produit2.type = "luxe";
    produit2.prixHT = 200;
    produit2.solde = false; 

    // Afficher les prix nets
    cout << "Prix produit 1 : " << calculerPrix(produit1) << endl;
    cout << "Prix produit 2 : " << calculerPrix(produit2) << endl;

    return 0;
}
