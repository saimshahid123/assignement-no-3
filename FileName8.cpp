#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

void inputBookStatus(char library[ROWS][COLS]) {
    cout << "Enter book status for each shelf (A=Available, I=Issued, M=Missing):\n";
    for (int r = 0; r < ROWS; r++) {
        cout << "Shelf " << r + 1 << ": ";
        for (int c = 0; c < COLS; c++) {
            cin >> library[r][c];
         
            if (library[r][c] >= 'a' && library[r][c] <= 'z') {
                library[r][c] -= 32;
              }
     }
      }
    }

void displayBookStatus(char library[ROWS][COLS]) {
    cout << "\nLibrary Book Status:\n";
    for (int r = 0; r < ROWS; r++) {
        cout << "Shelf " << r + 1 << ": ";
        for (int c = 0; c < COLS; c++) {
            cout << library[r][c] << " ";
          }
        cout << endl;
  }
    }

void countStatus(char library[ROWS][COLS], int& available, int& issued, int& missing) {
    available = issued = missing = 0;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (library[r][c] == 'A') available++;
            else if (library[r][c] == 'I') issued++;
            else if (library[r][c] == 'M') missing++;
      }
      } 
  }

void shelvesWithMostMissing(char library[ROWS][COLS]) {
    int maxMissing = -1;
    int missingCount[ROWS] = { 0 };

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (library[r][c] == 'M') {
                missingCount[r]++;
            }
        }
        if (missingCount[r] > maxMissing) {
            maxMissing = missingCount[r];
        }
    }

    cout << "\nShelf(s) with highest missing books (" << maxMissing << "):\n";
    for (int r = 0; r < ROWS; r++) {
        if (missingCount[r] == maxMissing) {
            cout << "Shelf " << r + 1 << endl;
        }
    }
}

int main() {
    char library[ROWS][COLS];
    int available, issued, missing;

    inputBookStatus(library);
    displayBookStatus(library);

    countStatus(library, available, issued, missing);

    cout << "\nTotal books available: " << available << endl;
    cout << "Total books issued: " << issued << endl;
    cout << "Total books missing: " << missing << endl;

    shelvesWithMostMissing(library);

    return 0;
}
