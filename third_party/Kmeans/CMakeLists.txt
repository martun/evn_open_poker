cmake_minimum_required(VERSION 3.9)
project(Kmeans)

set(CMAKE_CXX_STANDARD 11)

add_executable(Kmeans src/Cluster.cpp src/Cluster.h src/Point.cpp src/Point.h src/KMeans.cpp src/KMeans.h)