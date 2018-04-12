
#include "Cluster.h"
Cluster::Cluster(int id_cluster, Point point) {
    this->id_cluster = id_cluster;

    int total_values = point.getTotalValues();

    for(int i = 0; i < total_values; i++)
        central_values.push_back(point.getValue(i));

    points.push_back(point);
}


void Cluster::addPoint(Point point) {
    points.push_back(point);
}

bool Cluster::removePoint(int id_point) {
    int total_points = points.size();

    for(int i = 0; i < total_points; i++)
    {
        if(points[i].getID() == id_point)
        {
            points.erase(points.begin() + i);
            return true;
        }
    }
    return false;
}

double Cluster::getCentralValue(int index) {
    return central_values[index];
}

void Cluster::setCentralValue(int index, double value) {
    central_values[index] = value;
}

Point Cluster::getPoint(int index) {
    return points[index];
}

int Cluster::getTotalPoints() {
    return points.size();
}

int Cluster::getID() {
    return id_cluster;
}