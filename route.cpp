#include "route.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

Route::Route(vector<City*> vec_cities) {
    this->cities = vec_cities;
}

void Route::swap() {
    int pos1 = rand() % getSize();
    int pos2 = rand() % getSize();
    iter_swap(this->cities.begin() + pos1, this->cities.begin() + pos2);
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
    int routeDist = 0;
    for (int i = 0; i < getSize(); i++) {
        City* from = getCity(i);
        City* to = getCity(0);
        if (i + 1 < getSize())
            to = getCity(i + 1);
        routeDist += from->distance(to);
    }
    this->distance = routeDist;
    return this->distance;
}

int Route::getSize() {
    return this->cities.size();
}

double Route::transportCost(int n[]) {
    int size = getSize();
    double delta;
    n[4] = 1 + (n[3] % size);
    n[5] = 1 + ((n[1] + size - 3) % size);
    n[6] = 1 + (n[2] % size);
    City* ct1 = getCity(n[1]);
    City* ct2 = getCity(n[2]);
    City* ct3 = getCity(n[3]);
    City* ct4 = getCity(n[4]);
    City* ct5 = getCity(n[5]);
    City* ct6 = getCity(n[6]);
    delta = -(ct2->distance(ct6));
    delta -= ct1->distance(ct5);
    delta -= ct3->distance(ct4);
    delta += ct1->distance(ct3);
    delta += ct2->distance(ct4);
    delta += ct5->distance(ct6);
    return delta;
}

double Route::reverseCost(int n[]) {
    int size = getSize();
    double delta;
    n[3] = 1 + ((n[1]+size-2) % size);
    n[4] = 1 + (n[2] % size);
    cout << n[3] << endl;
    cout << n[4] << endl;
    City* ct1 = getCity(n[1]);
    City* ct2 = getCity(n[2]);
    City* ct3 = getCity(n[3]);
    City* ct4 = getCity(n[4]);
    delta = -(ct1->distance(ct3));
    delta -= ct2->distance(ct4);
    delta += ct1->distance(ct4);
    delta += ct2->distance(ct3);
    return delta;
}

void Route::transport(int n[]) {
    int m1, m2, m3, nn, ii;
    int size = getSize();
    m1 = 1 + ((n[2] - n[1] + size) % size);
    m2 = 1 + ((n[5] - n[4] + size) % size);
    m3 = 1 + ((n[3] - n[6] + size) % size);
    nn = 1;
    for (int i = 1; i <= m1; i++) {
        ii = 1 + ((i + n[1] - 2) % size);
        iter_swap(this->cities.begin() + nn++, this->cities.begin() + ii);
    }
    for (int i = 1; i <= m2; i++) {
        ii = 1 + ((i + n[4] - 2) % size);
        iter_swap(this->cities.begin() + nn++, this->cities.begin() + ii);
    }
    for (int i = 1; i <= m3; i++) {
        ii = 1 + ((i + n[6] - 2) % size);
        iter_swap(this->cities.begin() + nn++, this->cities.begin() + ii);
    }
}

void Route::reverse(int n[]) {
    int nn, k, l;
    int size = getSize();
    nn = (1 + ((n[2] - n[1] + size) % size)) / 2;
    for (int i = 1; i <= nn; i++) {
        k = 1 + ((n[1] + i - 2) % size);
        l = 1 + ((n[2] - i + size) % size);
        iter_swap(this->cities.begin() + k, this->cities.begin() + l);
    }
}

QString Route::print() {
    QString result;
    for (int i = 0; i < getSize(); i++) {
        //cout << this->cities[i]->getID() << "->";
        result.append(QString::number(this->cities[i]->getID()));
        result.append(" -> ");
    }
    result.append(QString::number(this->cities[0]->getID()));
    return result;

    //cout << this->cities[0]->getID() << endl;
}

