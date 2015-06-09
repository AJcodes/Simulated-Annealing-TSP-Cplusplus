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
        void Anneal();
        void Anneal2();

    signals:
        void sendToModel(int count, int x, int y);
        void sendToCanvas(int x, int y, int x1, int y1);
        void sendToReset(int x, int y);
        void sendToResults(int dist, int finaldist, int iterations, double extime);
        void sendToText(QString routes);
        void sendToClear();

    public slots:
        void receiveFromQml(int, int, int);
        void receiveFromQmlFile(QString);
        void receiveFromQml1(double, double, double);

    private:
        std::vector<City*> vec_city;
        int nn, succ, over, limit;
        double temp;
        double absTemp;
        double coolRate;
};

#endif // TSP

