#include "route.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

Route::Route(int val, vector<City*> vec_cities) {
    this->cities = vec_cities;
    if (val == 0)
        random_shuffle(this->cities.begin(), this->cities.end());
}

void Route::swap() {
    int pos1 = rand() % getSize();
    int pos2 = rand() % getSize();
    City * ct1 = getCity(pos1);
    City * ct2 = getCity(pos2);
    setCity(pos2, ct1);
    setCity(pos1, ct2);
}

vector<City*> Route::getRoute() {
    return this->cities;
}

City* Route::getCity(int index) {
    return this->cities[index];
}

void Route::setCity(int index, City* city) {
    this->cities[index] = city;
}

int Route::getDistance() {
    //if (this->distance == 0) {
        int routeDist = 0;
        for (int i = 0; i < getSize(); i++) {
            City* from = getCity(i);
            City* to = getCity(0);
            if (i + 1 < getSize())
                to = getCity(i + 1);

            routeDist += from->distance(to);
        }
        this->distance = routeDist;
    //}
    return this->distance;
}

int Route::getSize() {
    return this->cities.size();
}

void Route::print() {
    for (int i = 0; i < getSize(); i++)
        cout << this->cities[i]->getID() << "->";

    cout << this->cities[0]->getID() << endl;
}

