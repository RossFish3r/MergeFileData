/*Includes*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

  /*initialize the arrays to store lists*/
    vector<string> listOne;
    vector<string> listTwo;
    string item;

    // Read items from first data file
    ifstream file1("data1.dat");
    if (file1.is_open()) {
        while (getline(file1, item)) {
        listOne.push_back(item);
        }
        file1.close();
    } else {
        cout << "Unable to open file dat1.dat" << endl;
        return 1;
    }

     // Read items from second file
  ifstream file2("data2.dat");
  if (file2.is_open()) {
    while (getline(file2, item)) {
      listTwo.push_back(item);
    }
    file2.close();
  } else {
    cout << "Unable to open file dat2.dat" << endl;
    return 1;
  }

    std::cout << "Made it processing the list...\r\n" << std::endl;

    // Merge the two lists into a single list
  vector<string> items;
  items.insert(items.end(), listOne.begin(), listOne.end());
  items.insert(items.end(), listTwo.begin(), listTwo.end());

  std::cout << "Merging lists...\r\n" << std::endl;

  // Write the merged list to a file
  ofstream file3("output.dat");
  if (file3.is_open()) {
    for (const auto& item : items) {
      file3 << item << endl;
    }
    file3.close();
  } else {
    cout << "Unable to open file output.dat" << endl;
    return 1;
  }

     std::cout << "***********\r\n**FINI...**\r\n***********" << std::endl;

    return 0;

}