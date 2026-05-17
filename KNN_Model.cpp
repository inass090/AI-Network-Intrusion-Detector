#include "KNN_Model.hpp"
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>

// Euclidean Distance
double calculateDistance(const DataPoint& a, const DataPoint& b) {
    double sum = 0.0;
    for (size_t i = 0; i < a.features.size(); ++i) {
        sum += std::pow(a.features[i] - b.features[i], 2);
    }
    return std::sqrt(sum);
}

// reading the network data
std::vector<DataPoint> loadCSV(std::string filename) {
    std::vector<DataPoint> data;
    std::ifstream file(filename);
    std::string line, val, label;
    
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<double> features;
        for (int i = 0; i < 2; ++i) {
            std::getline(ss, val, ',');
            features.push_back(std::stod(val));
        }
        std::getline(ss, label, ',');
        data.push_back({features, label});
    }
    return data;
}

// The Classifier: Finds the most similar patterns
std::string classify(const std::vector<DataPoint>& trainingData, const DataPoint& query, int k) {
    std::vector<std::pair<double, std::string>> distances;
    for (const auto& train : trainingData) {
        distances.push_back({calculateDistance(train, query), train.label});
    }
    std::sort(distances.begin(), distances.end());
    return distances[0].second; 
}
