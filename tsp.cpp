#include "tsp.h"
#include "route.h"
#include <iostream>
#include <fstream>
#include <sstream>
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
    //std::cout << ct->getID() << ": " << ct->getX() << ", " << ct->getY() << std::endl;
    //std::cout << "Number of cities: " << getTotalCities() << std::endl;
    sendToModel(ct->getID(), ct->getX(), ct->getY());
}

<<<<<<< HEAD
void Tsp::receiveFromQmlFile(QString string) {
    string.remove(0,8);
    cout << string.toStdString() << endl;
    ifstream in(string.toStdString().c_str());
    int count = 0;
    int id = 0;
    while (in) {
        std::string s;
        std::string test[2];
        if (!getline( in, s )) break;
        istringstream ss( s );
        while (ss) {
            std::string s;
            if (!getline( ss, s, ',' )) break;
            test[count] = s;
            count++;
            if (count == 2) {
                break;
            }
        }
        City *ct = new City(id, atoi(test[0].c_str()), atoi(test[1].c_str()));
        addCity(ct);
        id++;
        sendToModel(ct->getID(), ct->getX(), ct->getY());
        sendToReset(ct->getX(), ct->getY());
        count = 0;
    }
    if (!in.eof()) {
        cerr << "Fooey!\n";
    }
}

void Tsp::receiveFromQml1(double temp, double absTemp, double coolRate) {
    if (this->vec_city.empty())
        return;
=======
void Tsp::receiveFromQml1(double temp, double absTemp, double coolRate) {
>>>>>>> origin/master
    sendToClear();
    this->temp = temp;
    this->absTemp = absTemp;
    this->coolRate = coolRate;
    for (unsigned int i = 0; i < vec_city.size(); i++) {
        sendToReset(vec_city[i]->getX(), vec_city[i]->getY());
    }
    Anneal();
}

void Tsp::Anneal() {
    int it = -1;
    //double temp = 1.0;
    double delta = 0;
    //double coolRate = 0.9992;
    //double absTemp = 0.0001;

    Route curr = Route(vec_city);
    double distance = curr.getDistance();
    double init = distance;
    //cout << "Initial Distance: " << curr.getDistance() << endl;
    //curr.print();

    clock_t time = clock();

    while (temp > absTemp) {
        Route next = Route(curr.getRoute());
        next.swap();
        delta = next.getDistance() - distance;
        if ((delta < 0) || (std::exp(-delta / temp) > (rand() % 1))) {
            curr = Route(next.getRoute());
            distance = delta + distance;
        }
        temp *= coolRate;
        it++;
    }

    time = clock() - time;
    double s = double(time) / CLOCKS_PER_SEC;
    //cout << "Final Distance: " << distance << endl;
    //curr.print();
    //cout << "Number of iterations: " << it << endl;
    //cout << "Execution Time: " << s << " s" << endl;

    for (int i = 0; i < curr.getSize(); i++) {
        if (i + 1 == curr.getSize())
            sendToCanvas(curr.getCity(i)->getX(), curr.getCity(i)->getY(), curr.getCity(0)->getX(), curr.getCity(0)->getY());
        else
            sendToCanvas(curr.getCity(i)->getX(), curr.getCity(i)->getY(), curr.getCity(i+1)->getX(), curr.getCity(i+1)->getY());
    }
    sendToResults(init, distance, it, s);
    sendToText(curr.print());
}

