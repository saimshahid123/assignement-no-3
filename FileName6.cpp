#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 4;

void displaySeats(char seats[ROWS][COLS]) {
    cout << "\nSeat Layout:\n  ";
    for (int c = 0; c < COLS; c++) {
        cout << "Seat" << c + 1 << " ";
    }
    cout << "\n";
    for (int r = 0; r < ROWS; r++) {
        cout << "Row " << r + 1 << " ";
        for (int c = 0; c < COLS; c++) {
            cout << "  " << seats[r][c] << "  ";
        }
        cout << endl;
    }
}

void bookSeat(char seats[ROWS][COLS], int row, int seat) {
    if (row < 1 || row > ROWS || seat < 1 || seat > COLS) {
        cout << "Invalid seat selection.\n";
        return;
    }
    if (seats[row - 1][seat - 1] == 'E' || seats[row - 1][seat - 1] == 'e') {
        seats[row - 1][seat - 1] = 'B';
        cout << "Seat booked successfully.\n";
    }
    else {
        cout << "Seat already booked.\n";
    }
}

int countAvailableSeats(char seats[ROWS][COLS]) {
    int count = 0;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (seats[r][c] == 'E' || seats[r][c] == 'e') {
                count++;
            }
        }
    }
    return count;
}

int rowWithMaxEmptySeats(char seats[ROWS][COLS]) {
    int maxEmpty = -1;
    int maxRow = -1;
    for (int r = 0; r < ROWS; r++) {
        int emptyCount = 0;
        for (int c = 0; c < COLS; c++) {
            if (seats[r][c] == 'E' || seats[r][c] == 'e') {
                emptyCount++;
            }
        }
        if (emptyCount > maxEmpty) {
            maxEmpty = emptyCount;
            maxRow = r;
        }
    }
    return maxRow;
}

int main() {
    char seats[ROWS][COLS];
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            seats[r][c] = 'E';
        }
    }

    displaySeats(seats);

    int choice;
    do {
        cout << "\nMenu:\n1. Book a seat\n2. Show available seats count\n3. Show row with maximum empty seats\n4. Display seat layout\n5. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            int row, seat;
            cout << "Enter row number (1 to " << ROWS << "): ";
            cin >> row;
            cout << "Enter seat number (1 to " << COLS << "): ";
            cin >> seat;
            bookSeat(seats, row, seat);
        }
        else if (choice == 2) {
            cout << "Available seats: " << countAvailableSeats(seats) << endl;
        }
        else if (choice == 3) {
            int maxRow = rowWithMaxEmptySeats(seats);
            if (maxRow != -1) {
                cout << "Row with maximum empty seats: Row " << maxRow + 1 << endl;
            }
            else {
                cout << "No seats available.\n";
            }
        }
        else if (choice == 4) {
            displaySeats(seats);
        }
        else if (choice == 5) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
