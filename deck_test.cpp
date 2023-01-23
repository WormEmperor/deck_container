#include "deck.hpp"
#include <iostream>

template <typename T>
constexpr void print_deck(Deck<T> deck) { // prints deck in the form {a, b, c}
    std::cout << "{";
    for (int i = 0; i < deck.size() - 1; ++i) {
        std::cout << deck[i] << ", ";
    }
    std::cout << deck[deck.size() - 1] << "}\n";
}

int main() {
    Deck<int> deck = {1, 2, 3};
    print_deck(deck);
    
    return 0;
}
