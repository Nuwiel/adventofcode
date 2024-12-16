#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<int> leftList {};
    vector<int> rightList {};
    
    /* Read the input from text file and print */
    ifstream file {".\\input.txt"};
    int a {0};
    int b {0};
    while (file >> a >> b) {
        leftList.push_back(a);
        rightList.push_back(b);
    }

    /* Sort both list */
    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());
    
    /* Count the distance */
    int totalDistance {0};
    for (size_t i {0}; i < leftList.size(); i++) {
        totalDistance += abs(leftList.at(i) - rightList.at(i));
    }
    cout << totalDistance << endl;
    
    return 0;
}