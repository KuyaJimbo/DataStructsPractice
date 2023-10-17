#include <string>

#ifndef RBLINE_HPP
#define RBLINE_HPP

class player {
    public:
    player(std::string name, int score);
    std::string name;
    int score;
    player* next;
    player* prev;
    friend class line;
};

class line {
    private:
        player* Ball; // Head node is the player with the ball
        int size;
    public:
        line();
        ~line();
        bool empty() const;
        player* PlayerFront(); // player with the ball
        player* PlayerBack(); // player following player with the ball
        void advanceBall(); // move ball to next player
        void retreatBall(); // move ball to previous player
        void addPlayer(player* p); // add player after player with ball
        void removePlayer(); // remove player after player with ball
        void printLine(); // print line of players
};
#endif