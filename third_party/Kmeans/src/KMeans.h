#ifndef KMEANS1_KMEANS_H
#define KMEANS1_KMEANS_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Point.h"
#include "Cluster.h"

class KMeans {
private:
    int K; // number of clusters
    int total_values, total_points, max_iterations;
    vector<Cluster> clusters;

    // return ID of nearest center (uses euclidean distance)
    int getIDNearestCenter(Point point);

public:
    KMeans(int K, int total_points, int total_values, int max_iterations);
    void run(vector<Point> & points);

};


#endif