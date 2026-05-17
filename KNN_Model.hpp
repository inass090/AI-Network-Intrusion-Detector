#ifndef KNN_MODEL_H
#define KNN_MODEL_H

#include <vector>
#include <string>

// Data structure to hold network packet information
struct DataPoint {
    std::vector<double> features; 
    std::string label;            // "Safe" or "Attack"
};

// Function prototypes
double calculateDistance(const DataPoint& a, const DataPoint& b);
std::string classify(const std::vector<DataPoint>& trainingData, const DataPoint& query, int k);
std::vector<DataPoint> loadCSV(std::string filename);

#endif
