#include <iostream>
#include <string.h>

#include "LegoStack.hpp"

Lego::Lego(std::string color) {
    this->color = color;
    this->next = NULL;
}

std::string Lego::getColor() {
    return this->color;
}

//--------------------------------------------

Tower::Tower() {
    top = nullptr;
}

void Tower::push(Lego* lego) {
    lego->next = top;
    top = lego;
}

void Tower::pop() {
    // check if empty
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    // temp holds top, move top, delete temp
    Lego* temp = top;
    top = top->next;
    delete temp;
}

Lego* Tower::peek() {
    // check if empty
    if (top == nullptr) {
        return nullptr;
    }
    return top;
}

bool Tower::isEmpty() {
    return top == nullptr;
}

// test the stack
int main() {
    // create the stack object
    Tower* t = new Tower();

    // create some legos
    Lego* l1 = new Lego("red");
    Lego* l2 = new Lego("blue");
    Lego* l3 = new Lego("green");

    // push the legos onto the stack
    t->push(l1);
    t->push(l2);
    t->push(l3);

    // test if peek works
    std::cout << t->peek()->getColor() << std::endl;

    // test if the stack is empty
    if (t->isEmpty()) std::cout << "Stack is empty" << std::endl;
    else std::cout << "Stack is not empty" << std::endl;

    // test if pop works on an empty stack

    return 0;
}