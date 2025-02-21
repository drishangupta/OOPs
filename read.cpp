#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    // Open the file for reading
    fstream file1("abc.txt", ios::in);
    if (!file1) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    int num;
    int sum = 0;

    // Read integers from the file and calculate the sum
    while (file1 >> num) {
        cout << num << endl;
        sum += num;
    }

    file1.close(); // Close the file after reading

    // Open the file for appending
    fstream file2("abc.txt", ios::out | ios::app);
    if (!file2) {
        cerr << "Error opening file for appending!" << endl;
        return 1;
    }

    string sc = "drishan";
    file2 << sc << " " << sum << endl; // Append the string and sum
    file2.close(); // Close the file after writing

    return 0;
}