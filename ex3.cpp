#include <iostream>
#include <vector>
#include <functional>

void appliquerFiltre(std::vector<int>& vec, std::function<void(int&, int)> filtre) {
    int seuil = 0;

    // If you still want to ask for a threshold in case of "superior" filtering
    std::cout << "Donner seuil : ";
    std::cin >> seuil;

    for (int& e : vec) {
        filtre(e, seuil);
    }
}

int main() {
    std::vector<int> tab{ -2, 19, -8, 7, 17, -122, 3 };

    std::cout << "************************\n";
    std::cout << "* 1. Afficher positif *\n";
    std::cout << "* 2. Afficher Negatif *\n";
    std::cout << "* 3. Superieur A *\n";
    std::cout << "************************\n";
    std::cout << "Entrez votre choix :\n";

    int choix;
    std::cin >> choix;

    switch (choix) {
        case 1: 
            appliquerFiltre(tab, [](int& x, int seuil) { 
                if (x >= 0) std::cout << x << "\t"; 
            });
            break;
        case 2: 
            appliquerFiltre(tab, [](int& x, int seuil) { 
                if (x < 0) std::cout << x << "\t"; 
            });
            break;
        case 3: 
            appliquerFiltre(tab, [](int& x, int seuil) { 
                if (x >= seuil) std::cout << x << "\t"; 
            });
            break;
        default: 
            break;
    }

    return 0;
}
