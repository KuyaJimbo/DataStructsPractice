#include <string.h>

#ifndef LEGOSTACK_HPP
#define LEGOSTACK_HPP

class Lego {
    private:
        std::string color;
        Lego* next;
        friend class Tower;
    public:
        Lego(std::string color);
        std::string getColor();
};

class Tower {
    private:
        Lego* top;
    public:
        Tower();
        void push(Lego* lego);
        void pop();
        Lego* peek();
        bool isEmpty();
};

#endif