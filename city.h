#ifndef CITY
#define CITY

class City {
    public:
        City(int, int, int);

    public:
        int getID();
        int getX();
        int getY();
        void setID(int);
        void setX(int);
        void setY(int);
        double distance(City*);

    private:
        int id;
        int x;
        int y;
};

#endif // CITY

