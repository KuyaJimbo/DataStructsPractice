#include <iostream>
#include <string>

// properly include the header file
#include "MCLine.hpp"

customer::customer(std::string n, float m) {
    name = n;
    money = m;
    next = nullptr;
}

void customer::setNext(customer* c) {
    next = c;
}

customer* customer::getNext() {
    return next;
}

// missing getName() function
std::string customer::getName() {
    return name;
}

// --------------------------------------------------

line::line() {
    head = nullptr;
    size = 0;
}

line::~line() {
    customer* temp = head;
    while (temp != nullptr) {
        head = head->getNext();
        delete temp;
        temp = head;
    }
}

void line::addCustomerFront(customer* c) {
    if (head == nullptr) {
        head = c;
    }
    else { // this means that there is already a customer in line
        c->setNext(head);
        head = c;
    }
    size++;
}

void line::addCustomerBack(customer* c) {
    if (head == nullptr) {
        head = c;
    }
    else {
        // move temp to the end of the line
        customer* temp = head;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(c);
    }
    size++;
}

void line::addCustomerBetween(customer* c, int pos) {
    // check if pos is valid
    if (pos < 0 || pos > size) {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    customer* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        // the reason why we put pos - 1 is because we want to stop at the node BEFORE the position we want to insert at
        temp = temp->getNext();
    }
    c->setNext(temp->getNext());
    temp->setNext(c);
    size++;
}

void line::removeCustomerFront() {
    if (head == nullptr) {
        std::cout << "Line is empty" << std::endl;
        size--;
        return;
    }
    customer* temp = head;
    head = head->getNext();
    delete temp;
    size--;
}

void line::removeCustomerBack() {
    if (head == nullptr) {
        std::cout << "Line is empty" << std::endl;
        return;
    }

    // to avoid a seg fault, we need to check if there is only one customer in line
    if (head->getNext() == nullptr) {
        delete head;
        head = nullptr; // this is to avoid a dangling pointer
        size--;
        return;
    }

    customer* temp = head;
    while (temp->getNext()->getNext() != nullptr) {
        // the reason why we want to stop at the node BEFORE the last node is because we want to delete the last node
        temp = temp->getNext();
    }
    delete temp->getNext();
    temp->setNext(nullptr); // to avoid a dangling pointer
    size--;
}

void line::removeCustomerBetween(int pos) {
    // check if pos is valid
    if (pos < 0 || pos < size) {
        std::cout << "Invalid position" << std::endl;
        return;
    }
    // check if the line is empty
    if (head == nullptr) {
        std::cout << "Line is empty" << std::endl;
        return;
    }
    customer* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        // the reason why we put pos - 1 is because we want to stop at the node BEFORE the position we want to remove at
        temp = temp->getNext();
    }
    customer* temp2 = temp->getNext(); // to keep track of the node we want to delete

    temp->setNext(temp2->getNext()); // to skip over the node we want to delete

    delete temp2; // delete the node we want to delete
    size--;
    
}

void line::printLine() {
    if (head == nullptr) {
        std::cout << "Line is empty" << std::endl;
        return;
    }
    customer* temp = head;
    while (temp != nullptr) {
        std::cout << temp->getName() << " ";
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

int main() {
    // create the line
    line* l = new line();

    // create the customers
    customer* c1 = new customer("John", 100);
    customer* c2 = new customer("Jane", 200);
    

    // first person enters the back of the line
    l->addCustomerBack(c1);
    // second person enters the front of the line
    l->addCustomerFront(c2);

    // print the line
    l->printLine();

}

// q: how do you run this code?
// a: g++ -std=c++11 MCLine.cpp -o MCLine
//    ./MCLine
