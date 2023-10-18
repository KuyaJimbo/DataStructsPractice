#include <iostream>
#include <string.h>

#include "Train.hpp"

std::string Car::get_id() {
    return "Car ID: " + std::to_string(id) + "\n";
}

void Car::set_id(int id) {
    this->id = id; // using the this notation allows us to differentiate between the 
                   // class variable and the parameter since they have the same name.
}

Car* Car::get_next() {
    return next;
}

void Car::set_next(Car* next) {
    this->next = next;
}

Car* Car::get_prev() {
    return prev;
}

void Car::set_prev(Car* prev) {
    this->prev = prev;
}

//----------------------------------------------------------------------------------

Train::Train() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Train::~Train() {
    Car* temp = head;
    while (temp != nullptr) {
        Car* next = temp->get_next();
        delete temp;
        temp = next;
    }
}

void Train::insertFront(int id) {
    // create a new car
    Car* new_car = new Car();
    // set the id of the new car
    new_car->set_id(id);
    // set the next of the new car to the head
    new_car->set_next(head);
    // set the prev of the new car to nullptr
    new_car->set_prev(nullptr);

    // if the head is not nullptr
    if (head != nullptr) {
        // set the prev of the head to the new car
        head->set_prev(new_car);
    }
    head = new_car;
    
    // if the tail is nullptr
    if (tail == nullptr) {
        // set the tail to the new car
        tail = new_car;
    }
    // increment the size
    size++;
}

void Train::insertBack(int id) {
    // create a new car
    Car* new_car = new Car();
    // set the id of the new car
    new_car->set_id(id);
    // set the next of the new car to nullptr
    new_car->set_next(nullptr);
    // set the prev of the new car to the tail
    new_car->set_prev(tail);

    // if the tail is not nullptr
    if (tail != nullptr) {
        // set the next of the tail to the new car
        tail->set_next(new_car);
    }
    tail = new_car;

    // if the head is nullptr
    if (head == nullptr) {
        // set the head to the new car
        head = new_car;
    }
    // increment the size
    size++;
}

void Train::removeFront() {
    Car* temp = head;
    head = head->get_next();
    head->set_prev(nullptr); // REMEMBER TO DO THIS!
    delete temp;
    size--;
}

void Train::removeBack() {
    Car* temp = tail;
    tail = tail->get_prev();
    tail->set_next(nullptr); // REMEMBER TO DO THIS!
    delete temp;
    size--;
}

int Train::getSize() {
    return size;
}

void Train::print() {
    Car* temp = head;
    while (temp != nullptr) {
        std::cout << temp->get_id();
        temp = temp->get_next();
    }
}

void Train::printReverse() {
    Car* temp = tail;
    while (temp != nullptr) {
        std::cout << temp->get_id();
        temp = temp->get_prev();
    }
}

bool Train::isEmpty() {
    return size == 0;
}

//----------------------------------------------------------------------------------

// test code
int main() {
    // create a train
    Train* train = new Train();

    // insert 5 cars to the front
    for (int i = 0; i < 5; i++) {
        train->insertFront(i);
    }

    // insert 5 cars to the back
    for (int i = 10; i < 15; i++) {
        train->insertBack(i);
    }

    // print the train
    train->print();
    std::cout << std::endl;

    // print the train in reverse
    train->printReverse();
    std::cout << std::endl;

    // remove 5 cars from the front
    for (int i = 0; i < 5; i++) {
        train->removeFront();
    }

    train->print();
}