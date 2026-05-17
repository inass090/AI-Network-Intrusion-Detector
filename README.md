# AI-Network-Intrusion-Detector
A modular C++ machine learning classifier built from scratch to detect DDoS attack patterns in network traffic using KNN


This is a simple machine learning project built from scratch using C++. It uses the K-Nearest Neighbors (KNN) algorithm to look at network packet data and decide if the traffic is safe or a potential DDoS attack.

I decided to create this project using C++ because I wanted to understand how machine learning math works, and to create the logic by myself instead of just importing libraries in Python.

## How it Works
The program is split into a few files to keep the code organized:
- `main.cpp`: Handles the user input and console interface.
- `KNN_Model.cpp` / `KNN_Model.h`: Contains the logic for the file reader and the math engine.

It reads a file called `network_data.csv` which has 50 examples of network logs. The logic uses the Euclidean Distance formula to calculate how close the user's input is to the safe or attack patterns in the file.

## Dataset Logic
The data features are based on basic network behaviors:
1. **Packet Size:** Large packets (around 1500 bytes) are usually normal data transfer. Small packets (30-50 bytes) are usually just ping requests.
2. **Interval:** If tiny packets are sent continuously at a very high frequency (low millisecond intervals), the model flags it as an attack pattern.

## Setup and Running
1. Make sure `network_data.csv` is placed in the same folder as the code files.
2. Compile all the files together using a C++ compiler (like Dev C++ or g++).
3. Run the executable, input a packet size and time interval when prompted, and see the prediction.
