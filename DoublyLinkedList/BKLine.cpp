#include <iostream>
#include <string>

// properly include the header file
#include "BKLine.hpp"

// customer constructor
customer::customer(std::string n, float m) {
    name = n;
    money = m;
    next = nullptr;
    prev = nullptr;
}

std::string customer::getName() {
    return name;
}

float customer::getMoney() {
    return money;
}

void customer::setMoney(float m) {
    money = m;
}

void customer::setNext(customer* c) {
    next = c;
}

customer* customer::getNext() {
    return next;
}

void customer::setPrev(customer* c) {
    prev = c;
}

customer* customer::getPrev() {
    return prev;
}

// ---------------------------------------------------------------

// line constructor
line::line() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// line destructor (SAME AS SINGLE LINKED LIST)
line::~line() {
    customer* temp = head;
    while (temp != nullptr) {
        customer* next = temp->getNext();
        delete temp;
        temp = next;
    }
}

// add customer to front of line (NOW NEED TO SET PREV POINTER)
void line::addCustomerFront(customer* c) {
    if (head == nullptr) {
        head = c;
        tail = c;
    } else {
        c->setNext(head);
        head->setPrev(c); // NOTICE THE DIFFERENCE
        head = c;
    }
    size++;
}

// add customer to back of line (NOW NEED TO SET PREV POINTER)
void line::addCustomerBack(customer* c) {
    if (head == nullptr) {
        std::cout << "Line is empty" << std::endl;
        head = c;
        tail = c;
        std::cout << "Added " << c->getName() << " to the line" << std::endl;
    } else {
        tail->setNext(c);
        c->setPrev(tail); // NOTICE THE DIFFERENCE
        tail = c;
    }
    size++;
}

// add customer to line at index (NOW NEED TO SET PREV POINTER)
void line::addCustomerBetween(customer* c, int index) {
    if (index < 0 || index > size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    customer* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->getNext();
    } // temp = node before new node
    temp->getNext()->setPrev(c); // NOTICE THE DIFFERENCE
    c->setNext(temp->getNext());
    temp->setNext(c);
    c->setPrev(temp); // NOTICE THE DIFFERENCE
    size++;
}

// remove customer from front of line (SAME AS SINGLE LINKED LIST)
void line::removeCustomerFront() {
    if (head == nullptr) {
        std::cout << "Line is empty" << std::endl;
        return;
    }
    //check if only one customer in line
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }
    customer* temp = head;
    head = head->getNext();
    delete temp;
    size--;
}

// remove customer from back of line (DIFFERENT SINGLE LINKED LIST BECAUSE OF TAIL USE)
// NO NEED TO TRAVERSE LIST WITH TEMP POINTER AND WHILE LOOP
void line::removeCustomerBack() {
    if (head == nullptr) {
        std::cout << "Line is empty" << std::endl;
        return;
    }
    //check if only one customer in line
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }
    customer* temp = tail;
    tail = tail->getPrev(); // NOTICE THE DIFFERENCE (this fixes the tail pointer)
    delete temp;
    size--;
}

// remove customer from line at index (NOW NEED TO SET PREV POINTER)
void line::removeCustomerBetween(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    customer* temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->getNext();
    } // temp = node before node to delete

    customer* toDelete = temp->getNext();
    temp->setNext(toDelete->getNext()); // skip over node to delete forwards
    toDelete->getNext()->setPrev(temp); // NOTICE THE DIFFERENCE, skip over node to delete backwards
    delete toDelete;
    size--;
}

// print line from front to back (SAME AS SINGLE LINKED LIST)
void line::printLine() {
    customer* temp = head;
    while (temp != nullptr) {
        std::cout << temp->getName() << " ";
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

// print line from back to front (DIFFERENT SINGLE LINKED LIST BECAUSE OF TAIL USE)
// USE TAIL AND PREV POINTERS TO TRAVERSE LIST BACKWARDS
void line::printLineBackwards() {
    customer* temp = tail;
    while (temp != nullptr) {
        std::cout << temp->getName() << " ";
        temp = temp->getPrev();
    }
    std::cout << std::endl;
}

// ---------------------------------------------------------------

int main() {
    // first create a line
    line* l = new line();

    // create some customers
    customer* c1 = new customer("Bob", 100);
    customer* c2 = new customer("Alice", 200);
    customer* c3 = new customer("John", 300);

    // add customers to line
    l->addCustomerBack(c1);
    // add customer to the front of the line
    l->addCustomerFront(c2);
    // add customer to the middle of the line
    l->addCustomerBetween(c3, 1);

    // print line
    l->printLine();
    std::cout << std::endl;
    // print line backwards
    l->printLineBackwards();
    std::cout << std::endl;
}

