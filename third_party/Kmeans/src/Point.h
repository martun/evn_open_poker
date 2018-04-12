#ifndef KMEANS1_POINT_H
#define KMEANS1_POINT_H


#include <iostream>
#include <vector>

using namespace std;

class Point {
private:
    int id_point, id_cluster;
    vector<double> values;
    int total_values;
    string name;

public:
    Point(int id_point, vector<double>& values, string name = "");
    int getID();
    void setCluster(int id_cluster);
    int getCluster();
    double getValue(int index);
    int getTotalValues();
    void addValue(double value);
    string getName();
};


#endif