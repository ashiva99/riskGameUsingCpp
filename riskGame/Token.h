//Token.h
#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

using namespace std;

class Token {
protected:
    int troopValue;
    string color;
public:
    Token(int troop, string col) : troopValue(troop), color(col) {}
    virtual int getTroopValue() const;
    virtual void show() {}//= 0;
};

class Infantry : public Token {
public:
    Infantry();
    void show() override;
};

class Cavalry : public Token {
public:
    Cavalry();
    void show() override;
};

class Artillery : public Token {
public:
    Artillery();
    void show() override;
};

#endif
