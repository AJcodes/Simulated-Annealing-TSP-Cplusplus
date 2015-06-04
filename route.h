#ifndef ROUTE
#define ROUTE

#include "city.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

class Route {
    public:
        Route(std::vector<City*>);

    public:
        void swap();
        std::vector<City*> getRoute();
        City* getCity(int);
        void setCity(int, City*);
        int getDistance();
        int getSize();
        void print();

    private:
        int n;
        int distance;
        std::vector<City*> cities;
};

#endif // ROUTE

