#include <iostream>
using namespace std;

const int SHIFTS = 3;
const int DAYS = 7;

void inputDefects(float defects[SHIFTS][DAYS]) {
    for (int s = 0; s < SHIFTS; s++) {
        cout << "Enter defect percentages for Shift " << s + 1 << " for " << DAYS << " days:\n";
        for (int d = 0; d < DAYS; d++) {
            cout << " Day " << d + 1 << ": ";
            cin >> defects[s][d];
            if (defects[s][d] < 0) defects[s][d] = 0;
            if (defects[s][d] > 100) defects[s][d] = 100;
       }
      }
  }

void averageDefectsPerShift(float defects[SHIFTS][DAYS], float avgShift[SHIFTS]) {
    for (int s = 0; s < SHIFTS; s++) {
        float sum = 0;
        for (int d = 0; d < DAYS; d++) {
            sum += defects[s][d];
        }
        avgShift[s] = sum / DAYS;
    }
}

void averageDefectsPerDay(float defects[SHIFTS][DAYS], float avgDay[DAYS]) {
    for (int d = 0; d < DAYS; d++) {
        float sum = 0;
        for (int s = 0; s < SHIFTS; s++) {
            sum += defects[s][d];
        }
        avgDay[d] = sum / SHIFTS;
    }
}

void identifyCriticalShifts(float avgShift[SHIFTS]) {
    cout << "\nCritical shifts (average defects > 10%):\n";
    bool found = false;
    for (int s = 0; s < SHIFTS; s++) {
        if (avgShift[s] > 10) {
            cout << "Shift " << s + 1 << " with average defect " << avgShift[s] << "%\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No critical shifts found.\n";
    }
}

int main() {
    float defects[SHIFTS][DAYS];
    float avgShift[SHIFTS];
    float avgDay[DAYS];

    inputDefects(defects);
    averageDefectsPerShift(defects, avgShift);
    averageDefectsPerDay(defects, avgDay);

    cout << "\nAverage defect percentage per shift:\n";
    for (int s = 0; s < SHIFTS; s++) {
        cout << "Shift " << s + 1 << ": " << avgShift[s] << "%\n";
    }

    cout << "\nAverage defect percentage per day:\n";
    for (int d = 0; d < DAYS; d++) {
        cout << "Day " << d + 1 << ": " << avgDay[d] << "%\n";
    }

    identifyCriticalShifts(avgShift);

    return 0;
}
