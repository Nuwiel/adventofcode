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
    
    /* Count the occurence of each number in both vectors */
    vector<int> leftCount {};
    for (const auto& i: leftList) {
        leftCount.push_back(count(rightList.begin(), rightList.end(), i));
    }
    int similarity {0};
    for (size_t i {0}; i < leftList.size(); i++) {
        similarity += leftList.at(i) * leftCount.at(i);
    }
    cout << "Similarity: " << similarity << endl;
    
    return 0;
}