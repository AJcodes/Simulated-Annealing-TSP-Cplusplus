#ifndef TSP
#define TSP

#include <QObject>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "city.h"

class Tsp : public QObject {
    Q_OBJECT
    public:
        explicit Tsp(QObject *parent = 0);
        void addCity(City*);
        City* getCity(int);
        int getTotalCities();
        double acptProb(int, int, double);
        void getBest();

    signals:
        void sendToModel(int count, int x, int y);
        void sendToCanvas(bool draw, int x, int y, int x1, int y1);

    public slots:
        void receiveFromQml(int, int, int);
        void receiveFromQml();

    private:
        std::vector<City*> vec_city;
};

#endif // TSP

