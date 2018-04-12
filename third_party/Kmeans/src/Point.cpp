
#include "Point.h"

Point::Point(int id_point, vector<double> &values, string name) {
    this->id_point = id_point;
    total_values = values.size();

    for(int i = 0; i < total_values; i++)
        this->values.push_back(values[i]);

    this->name = name;
    id_cluster = -1;
}

int Point::getID() {
    return id_point;
}

void Point::setCluster(int id_cluster) {
    this->id_cluster = id_cluster;
}

int Point::getCluster() {
    return id_cluster;
}

double Point::getValue(int index) {
    return values[index];
}

int Point::getTotalValues() {
    return total_values;
}

void Point::addValue(double value) {
    values.push_back(value);
}

string Point::getName() {
    return name;
}