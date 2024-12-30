#include <iostream>
#include <array>
template<typename T>
void echanger(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void trie_selection(std::array<T ,10>&t){
    for (size_t i = 0; i < t.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < t.size(); ++j) {
            if (t[j] < t[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            echanger(t[i], t[minIndex]);
        }
    }

}

int main() {
    std::array<int, 10> tableau = {9, 2, 5, 6, 3, 8, 1, 7, 4, 0};
    std::cout << "Tableau avant tri : ";
    for (const auto& elem : tableau) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    trie_selection(tableau);

    std::cout << "Tableau après tri : ";
    for (const auto& elem : tableau) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}