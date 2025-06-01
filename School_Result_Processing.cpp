
#include <iostream>
using namespace std;

int main() {
    int marks[10][5];
    int total[10];
    float average[10];

    for (int i = 0; i < 10; i++) {
        cout << "Enter marks for Student " << i + 1 << ":
";
        total[i] = 0;
        for (int j = 0; j < 5; j++) {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
            total[i] += marks[i][j];
        }
        average[i] = total[i] / 5.0;
    }

    int top = 0;
    for (int i = 1; i < 10; i++) {
        if (total[i] > total[top]) {
            top = i;
        }
    }

    cout << "\nTop scorer is Student " << top + 1 << " with total marks " << total[top] << ".\n";

    cout << "\nGrades for each student:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Student " << i + 1 << ": Average = " << (int)(average[i] + 0.5) << " - Grade: ";
        if (average[i] >= 85)
            cout << "A";
        else if (average[i] >= 70)
            cout << "B";
        else if (average[i] >= 50)
            cout << "C";
        else
            cout << "F";
        cout << endl;
    }

    return 0;
}
