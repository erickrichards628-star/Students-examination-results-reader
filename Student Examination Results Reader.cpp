#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct StudentRecord {
    char name[100];
    char regNumber[50];
    double totalMarks;
};

int main() {
    ifstream inFile("results.dat", ios::binary);

    if (!inFile) {
        cerr << "Error: Could not open results.dat for reading.\n";
        return 1;
    }

    StudentRecord record;

    cout << "--- Student Examination Results ---\n";
    while (inFile.read(reinterpret_cast<char*>(&record), sizeof(StudentRecord))) {
        cout << "Name : " << record.name << " | Marks: " << record.totalMarks << "\n";
    }

    inFile.close();

    return 0;
}