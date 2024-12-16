#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

bool isSafeReport(const std::vector<int>& levels)
{
    /* A single level or empty report is trivially safe. */
    if (levels.size() < 2) {
        return true;
    }

    /* Determine the trend: increasing or decreasing. */
    bool increasing = levels[1] > levels[0];
    bool consistentTrend = true;

    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = levels[i] - levels[i - 1];

        /* Check if the difference is within the range [1, 3]. */
        if ((abs(diff) < 1) || (abs(diff) > 3)) {
            return false;
        }

        /* Check if the trend is consistent. */
        if ((increasing && (diff < 0)) || (!increasing && (diff > 0))) {
            consistentTrend = false;
            break;
        }
    }

    return consistentTrend;
}

int main() {
    using std::vector;
    using std::ifstream;
    using std::string;
    using std::cout;
    using std::endl;

    int number_of_safe_levels {0};

    /* Open the file */
    ifstream file {".\\input.txt"};
    vector<vector<int>> levels {0};
    string str {};
    while (getline(file, str)) {
        std::istringstream stream(str);
        vector<int> temp {};
        int number {};

        while (stream >> number) {
            temp.push_back(number);
        }

        /* Check safety of level */
        if (isSafeReport(temp)) {
            number_of_safe_levels++;
        }

        levels.push_back(temp);
    }
 
    cout << "Number of safe levels: " << number_of_safe_levels << endl;

    return 0;
}