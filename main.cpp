#include <iostream>
#include "KNN_Model.hpp"

using namespace std;

int main() {
    //  Load the dataset
    vector<DataPoint> trainingData = loadCSV("network_data.csv");
    
    if (trainingData.empty()) {
        cout << "Error: Could not find network_data.csv!" << endl;
        return 1;
    }

    double size, interval;
    cout << "========================================" << endl;
    cout << "   AI NETWORK TRAFFIC MONITOR (C++)" << endl;
    cout << "========================================" << endl;

    
    cout << "\nEnter Packet Size (bytes): ";
    cin >> size;
    cout << "Enter Time Interval (ms): ";
    cin >> interval;

    DataPoint query = {{size, interval}, ""};

    // AI Decision
    string result = classify(trainingData, query, 3);

    cout << "\n--- ANALYSIS RESULT ---" << endl;
    if (result == "Attack") {
        cout << "STATUS: [DANGER] Potential DDoS Attack detected!" << endl;
    } else {
        cout << "STATUS: [SAFE] Traffic pattern is normal." << endl;
    }
    cout << "-----------------------" << endl;

    return 0;
}
