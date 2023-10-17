#include <string>

#ifndef BKLINE_HPP
#define BKLINE_HPP

class customer {
    public:
        customer(std::string n, float m);
        std::string getName();
        float getMoney();
        void setMoney(float m);
        void setNext(customer* c);
        customer* getNext();
        void setPrev(customer* c);
        customer* getPrev();
    private:
        std::string name;
        float money;
        customer* next;
        customer* prev;
        friend class line;
};

class line {
    public:
        line();
        ~line();
        void addCustomerFront(customer* c);
        void addCustomerBack(customer* c);
        void addCustomerBetween(customer* c, int index);
        void removeCustomerFront();
        void removeCustomerBack();
        void removeCustomerBetween(int index);
        void printLine();
        void printLineBackwards();
    private:
        customer* head;
        customer* tail;
        int size;
};

#endif
