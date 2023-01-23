#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

// Tested with g++ -std=c++20

template <typename T>
class Deck {
    public:
        // Required container type definitions, all copied from vector-class

        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = typename std::vector<T>::iterator;
        using const_iterator = typename std::vector<T>::const_iterator;
        using difference_type = typename std::vector<T>::difference_type;
        using size_type = typename std::vector<T>::size_type;

        // Required container methods:
        
        constexpr Deck() : data_container() {}
        constexpr Deck(const Deck& other) : data_container(other.data_container) {}
        constexpr Deck(Deck&& other) {
            data_container = std::move(other.data_container);
        }
                                                                            
        constexpr Deck& operator=(const Deck& other) {
            data_container = other.data_container;
            return *this;
        }
        constexpr Deck& operator=(Deck&& other) {
            data_container = std::move(other.data_container);
            return *this;
        }
        ~Deck() = default;
        constexpr iterator begin() {
            return data_container.begin();
        }
        constexpr iterator end() {
            return data_container.end();
        }
        constexpr const_iterator begin() const {
            return data_container.cbegin();
        }
        constexpr const_iterator end() const {
            return data_container.cend();
        }
        constexpr const_iterator cbegin() const {
            return data_container.cbegin();
        }
        constexpr const_iterator cend() const {
            return data_container.cend();
        }
        constexpr void swap(Deck& other) {
            data_container.swap(other.data_container);
        }
        constexpr size_type size() const {
            return data_container.size();
        }
        constexpr size_type max_size() const {
            return data_container.max_size();
        }
        constexpr bool empty() const {
            return data_container.empty();
        }

        // Not required by container objects, but useful nonetheless:

        constexpr Deck(std::initializer_list<T> ilist) : data_container(ilist) {} // Allows contruction / assignment from initializer lists
        constexpr Deck& operator=(std::initializer_list<T> ilist) {
            data_container = ilist;
            return *this;
        }

        constexpr T operator[](int index) {
            if (index >= size())
                throw std::runtime_error("Index out of range");
            return data_container[index];
        }

        // Special methods for Deck-class

        constexpr T top() {
            return this->operator[](size() - 1);
        }

        constexpr T bottom() {
            return this->operator[](0);
        }

        constexpr T draw() { // Remove and return top value
            T top_value = top();
            data_container.pop_back();
            return top_value;
        }

        constexpr void add(T new_value) {
            data_container.emplace_back(new_value);
        }

        constexpr void shuffle() {
            std::random_device random_device;
            std::mt19937 rng(random_device());
            std::shuffle(begin(), end(), rng);
        }

    private:
        std::vector<T> data_container;
};

// Required non-member functions for container:

template <typename T>
constexpr bool operator==(const Deck<T>& lhs, const Deck<T>& rhs) {
    return std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
}

template <typename T>
constexpr bool operator!=(const Deck<T>& lhs, const Deck<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
constexpr void swap(Deck<T>& first, Deck<T>& second) {
    first.swap(second);
}
#endif
