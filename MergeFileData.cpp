#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<int> data1;
    vector<int> data2;
    vector<int> result;

    // Open data1.dat for reading
    ifstream file1("data1.dat");
    if (!file1.is_open()) {
        cout << "Unable to open file data1.dat" << endl;
        return 1;
    }

    // Read integers from data1.dat and store them in data1 vector
    int x;
    while (file1 >> x) {
        data1.push_back(x);
    }

    // Close data1.dat
    file1.close();

    // Open data2.dat for reading
    ifstream file2("data2.dat");
    if (!file2.is_open()) {
        cout << "Unable to open file data2.dat" << endl;
        return 1;
    }

    // Read integers from data2.dat and store them in data2 vector
    while (file2 >> x) {
        data2.push_back(x);
    }

    // Close data2.dat
    file2.close();

    // Combine data1 and data2 into result vector
    int i = 0, j = 0;
    while (i < data1.size() && j < data2.size()) {
        result.push_back(data1[i++]);
        result.push_back(data2[j++]);
    }

    // If one file has more lines than the other, add the remaining elements to result
    while (i < data1.size()) {
        result.push_back(data1[i++]);
    }
    while (j < data2.size()) {
        result.push_back(data2[j++]);
    }

    // Open output.dat for writing
    ofstream output("output.dat");
    if (!output.is_open()) {
        cout << "Unable to open file output.dat for writing" << endl;
        return 1;
    }

    // Write result vector to output.dat
    for (int num : result) {
        output << num << endl;
    }

    // Close output.dat
    output.close();

    // Print result vector to console
    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
