#include <iostream>
#include <string.h>

#ifndef TRAIN_HPP
#define TRAIN_HPP

class Car {
    private:
        int id;
        Car* next;
        Car* prev;
        friend class Train;
    public:
        std::string get_id();
        void set_id(int id);
        Car* get_next();
        void set_next(Car* next);
        Car* get_prev();
        void set_prev(Car* prev);
};

class Train {
    private:
        Car* head;
        Car* tail;
        int size;
    public:
        Train();
        ~Train();
        void insertFront(int id);
        void insertBack(int id);
        void removeFront();
        void removeBack();
        int getSize();
        void print();
        void printReverse();
        bool isEmpty();
};

#endif