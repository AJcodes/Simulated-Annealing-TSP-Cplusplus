#include "city.h"
#include <iostream>
#include <cmath>

using namespace std;

City::City(int id, int x, int y) {
    this->id = id;
    this->x = x;
    this->y = y;
}

int City::getID() {
    return this->id;
}

int City::getX() {
    return this->x;
}

int City::getY() {
    return this->y;
}

void City::setID(int id) {
    this->id = id;
}

void City::setX(int x) {
    this->x = x;
}

void City::setY(int y) {
    this->y = y;
}

double City::distance(City* city) {
    return sqrt(std::pow(abs(getX()-city->getX()),2) + pow(abs(getY()-city->getY()),2));
}

