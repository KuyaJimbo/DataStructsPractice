#include <iostream>

// Interface
template <typename Thingy>
class Stack {
    public:
        int size();
        bool empty();
        const Thingy& peek() const throw(StackEmpty); // top element
            // const - can't change the element
            // Thingy& - reference to the element
            // peek() - function name
            // const - can't change the function
            // throw(StackEmpty) - throws StackEmpty exception

        void push(const Thingy& e); // push element onto stack
            // const - can't change the element
            // Thingy& - reference to the element
            // e - element

        void pop() throw(StackEmpty); // pop the stack
            // pop() - function name
            // throw(StackEmpty) - throws StackEmpty exception

        void print();
    private:
        Thingy* top;
        int n;
};



// Implementation
Stack::Stack() {
    top = nullptr;
}

Stack::size() {
    return n;
}

Stack::empty() {
    return size() == 0;
}

Stack::peek() {
    if (empty()) {
        throw StackEmpty("Peek attempted on empty stack");
    }
    return top->elem;
}

Stack::push(const Thingy& e) {
    Thingy* v = new Thingy;
    v->elem = e;
    v->next = top;
    top = v;
    n++;
}

Stack::pop() {
    if (empty()) {
        throw StackEmpty("Pop attempted on empty stack");
    }
    Thingy* old = top;
    top = top->next;
    delete old;
    n--;
}

Stack::print() {
    Thingy* temp = top;
    while (temp != nullptr) {
        std::cout << temp->elem << std::endl;
        temp = temp->next;
    }
}

// test
int main() {
    // create the stack object
    Stack* s = new Stack();

    // test the stack functions
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);

    s->print();

    s->pop();
    s->pop();

    s->print();

    return 0;
}


    