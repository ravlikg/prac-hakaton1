#pragma once

#include <iostream>
#include "structures.hpp"

struct Inventory{
    Product* items = nullptr;
    int size = 0;
    int capacity = 0;
};

inline void initInventory(Inventory &inv){
    inv.items = new Product[4];
    inv.size = 0;
    inv.capacity = 4;
}

inline void growInventory(Inventory &inv){
    Product* newItems = new Product[inv.capacity * 2];
    for(int i = 0; i < inv.size; i++){
        newItems[i] = inv.items[i];
    }
    delete[] inv.items;
    inv.items = newItems;
    inv.capacity = inv.capacity * 2;
}

inline void addProduct(Inventory &inv, const Product &p){
    if(inv.size == inv.capacity){
        growInventory(inv);
    }
    inv.items[inv.size] = p;
    inv.size++;
}

inline int findProduct(const Inventory &inv, const std::string &name){
    for(int i = 0; i < inv.size; i++){
        if(name == inv.items[i].name){
            return i;
        }
    }
    return -1;
}

inline void freeInventory(Inventory &inv){
    delete[] inv.items;
    inv.items = nullptr;
    inv.size = 0;
    inv.capacity = 0;
}