#include <string.h>
#include <iostream>

#include "RBLine.hpp"

// Constructor
player::player(std::string name, int score) {
    this->name = name;
    this->score = score;
    this->next = nullptr;
    this->prev = nullptr;
}

line::line() {
    this->Ball = nullptr;
    this->size = 0;
}

// Destructor
line::~line() {
    while (!empty()) {
        removePlayer();
    }
}

// Check if line is empty
bool line::empty() const {
    return size == 0;
}

// Return player with ball
player* line::PlayerFront() {
    return Ball->next;
}

// Return player following player with ball
player* line::PlayerBack() {
    return Ball;
}

void line::advanceBall() {
    Ball = Ball->next;
}

void line::retreatBall() {
    Ball = Ball->prev;
}

// Add player after player with ball
void line::addPlayer(player* p) {
    if (empty()) {
        Ball = p;
        Ball->next = Ball;
        Ball->prev = Ball;
    } else {
        p->next = Ball->next;
        p->prev = Ball;

        Ball->next->prev = p;
        Ball->next = p;
    }
    size++;
}

// Remove player with the ball who passes it to the next player after them
void line::removePlayer() {
    if (empty()) {
        return;
    }
    player* oldPlayer = Ball->next; // also known as PlayerFront() (the player with the ball)
    if (oldPlayer == Ball) {
        Ball = nullptr;
    } else {
        Ball->next = oldPlayer->next; // skip over oldPlayer
        oldPlayer->next->prev = Ball; //
    }
    delete oldPlayer;
    size--;
    // now who has the ball?
    // the player following the player with the ball
}

// Print line of players
void line::printLine() {
    if (empty()) {
        return;
    }
    player* current = Ball->next;
    while (current != Ball) {
        std::cout << current->name << " ";
        current = current->next;
    }
    std::cout << current->name << std::endl;
}

int main() {
    // create the line
    line* l = new line();

    // create some players
    player* p1 = new player("Alice", 0);
    player* p2 = new player("Bob", 0);
    player* p3 = new player("Charlie", 0);
    player* p4 = new player("Diana", 0);
    player* p5 = new player("Eve", 0);

    // add players to the line
    l->addPlayer(p1);
    l->addPlayer(p2);
    l->addPlayer(p3);
    l->addPlayer(p4);
    l->addPlayer(p5);

    // print the line
    l->printLine();
    std::cout << "Player with ball: " << l->PlayerFront()->name << std::endl;
    std::cout << "Player following player with ball: " << l->PlayerBack()->name << std::endl;
    std::cout << std::endl;

    // advance the ball
    l->advanceBall();
    std::cout << "The ball has been advanced." << std::endl;
    std::cout << "Player with ball: " << l->PlayerFront()->name << std::endl;
    std::cout << "Player following player with ball: " << l->PlayerBack()->name << std::endl;

    // remove a player
    l->removePlayer(); // removes the player with the ball
    std::cout << "A player has been removed." << std::endl;
    l->printLine();

    // now who has the ball?
    std::cout << "Player with ball: " << l->PlayerFront()->name << std::endl;
}