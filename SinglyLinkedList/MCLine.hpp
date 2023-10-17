#include <iostream>
#include <string>

#ifndef MCLINE_HPP
#define MCLINE_HPP

// MCLine.cpp already includes the header file

// this will be the class for people who walk in to the store
class customer {
    private:
        std::string name;
        float money;
        customer* next;
        friend class line;
    public:
        customer(std::string n, float m);
        void setNext(customer* c);
        customer* getNext();
        std::string getName();
};

// this will be the class for the line
class line {
    private:
        customer* head;
        int size;
    public:
        line();
        ~line();
        void addCustomerFront(customer* c);
        void addCustomerBack(customer* c);
        void addCustomerBetween(customer* c, int pos);

        void removeCustomerFront();
        void removeCustomerBack();
        void removeCustomerBetween(int pos);

        void printLine();
};

#endif