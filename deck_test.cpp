#include "deck.hpp"
#include <iostream>

template <typename T>
constexpr void print_deck(Deck<T> deck) const { // prints deck in the form {a, b, c}
    std::cout << "{";
    for (int i = 0; i < deck.size() - 1; ++i) {
        std::cout << deck[i] << ", ";
    }
    std::cout << deck[deck.size() - 1] << "}\n";
}

int main() {
    Deck<int> deck = {1, 2, 3};
    std::cout << "Initial deck:\n";
    print_deck(deck);
   
    std::cout << "Drew " << deck.draw() << "\n";
    std::cout << "After drawing:\n";
    print_deck(deck);

    std::cout << "After adding 5:\n";
    deck.add(5);
    print_deck(deck);

    std::cout << "Print top and bottom:\n";
    std::cout << deck.top() << ", " << deck.bottom() << "\n";

    std::cout << "After shuffling:\n";
    deck.shuffle();
    print_deck(deck);
    return 0;
}
