#include "tsp.h"
#include "route.h"
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

Tsp::Tsp(QObject *parent) : QObject(parent) {

}

void Tsp::addCity(City* ct) {
    this->vec_city.push_back(ct);
}

City* Tsp::getCity(int index) {
    return this->vec_city[index];
}

int Tsp::getTotalCities() {
    return this->vec_city.size();
}

void Tsp::receiveFromQml(int count, int x, int y) {
    City *ct = new City(count, x, y);
    addCity(ct);
    //list.push_back(ct);
    std::cout << ct->getID() << ": " << ct->getX() << ", " << ct->getY() << std::endl;
    std::cout << "Number of cities: " << getTotalCities() << std::endl;
    sendToModel(ct->getID(), ct->getX(), ct->getY());
}

void Tsp::receiveFromQml() {
    getBest();
}

void Tsp::getBest() {
    int it = -1;
    double temp = 1.0;
    double delta = 0;
    double coolRate = 0.9992;
    double absTemp = 0.0001;

    Route curr = Route(1, vec_city);
    double distance = curr.getDistance();
    cout << "Initial Distance: " << curr.getDistance() << endl;
    curr.print();

    clock_t time = clock();

    while (temp > absTemp) {
        Route next = Route(0,curr.getRoute());
        delta = next.getDistance() - distance;
        if ((delta < 0) || (std::exp(-delta / temp) > rand())) {
            curr = Route(1,next.getRoute());
            distance = delta + distance;
        }
        temp *= coolRate;
        it++;
    }

    time = clock() - time;
    double ms = double(time) / CLOCKS_PER_SEC;
    cout << "Final Distance: " << distance << endl;
    curr.print();
    cout << "Number of iterations: " << it << endl;
    cout << "Execution Time: " << ms << " s" << endl;

    for (int i = 0; i < curr.getSize(); i++) {
        if (i + 1 == curr.getSize())
            sendToCanvas(true, curr.getCity(i)->getX(), curr.getCity(i)->getY(), curr.getCity(0)->getX(), curr.getCity(0)->getY());
        else
            sendToCanvas(true, curr.getCity(i)->getX(), curr.getCity(i)->getY(), curr.getCity(i+1)->getX(), curr.getCity(i+1)->getY());
    }
}

