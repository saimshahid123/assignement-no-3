#include <iostream>
using namespace std;

int main() {
    const int PATIENTS = 5;
  const int DAYS = 7;
      char status[PATIENTS][DAYS];
   int stableCount = 0, criticalCount = 0, recoveredCount = 0;
     int criticalDays[PATIENTS] = { 0 };

    for (int i = 0; i < PATIENTS; i++) {
   cout << "Enter status for Patient " << i + 1 << " (S=Stable, C=Critical, R=Recovered) for 7 days:\n";
      for (int j = 0; j < DAYS; j++) {
            cout << " Day " << j + 1 << ": ";
            cin >> status[i][j];
         char ch = status[i][j];
               if (ch == 'S' || ch == 's') stableCount++;
          else if (ch == 'C' || ch == 'c') {
                criticalCount++;
                criticalDays[i]++;
            }
            else if (ch == 'R' || ch == 'r') recoveredCount++;
        }
    }

    cout << "\nTotal counts:\n";
    cout << "Stable: " << stableCount << "\n";
    cout << "Critical: " << criticalCount << "\n";
    cout << "Recovered: " << recoveredCount << "\n";

    cout << "\nNumber of days each patient was Critical:\n";
    for (int i = 0; i < PATIENTS; i++) {
        cout << "Patient " << i + 1 << ": " << criticalDays[i] << " days\n";
    }

    return 0;
}
