#include <iostream>
using namespace std;

   const int ROWS = 5;
 const int COLS = 5;

  void inputTemperature(float temp[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
         cout << "Enter temperatures for Zone " << i + 1 << " (" << COLS << " locations):\n";
      for (int j = 0; j < COLS; j++) {
              cout << " Location " << j + 1 << ": ";
             cin >> temp[i][j];
          }
  }

  }

void averageTemperaturePerRow(float temp[ROWS][COLS], float avg[ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        float sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += temp[i][j];
        }
        avg[i] = sum / COLS;
    }
}

void detectExtremeSpots(float temp[ROWS][COLS], float hotThreshold, float coldThreshold) {
    cout << "\nExtreme hot spots (above " << hotThreshold << " degrees):\n";
    bool hotFound = false;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (temp[i][j] > hotThreshold) {
                cout << " Zone " << i + 1 << ", Location " << j + 1 << ": " << temp[i][j] << endl;
                hotFound = true;
            }
        }
    }
    if (!hotFound)
        cout << " None\n";

    cout << "\nExtreme cold spots (below " << coldThreshold << " degrees):\n";
    bool coldFound = false;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (temp[i][j] < coldThreshold) {
                cout << " Zone " << i + 1 << ", Location " << j + 1 << ": " << temp[i][j] << endl;
                coldFound = true;
            }
        }
    }
    if (!coldFound)
        cout << " None\n";
}

int main() {
    float temperature[ROWS][COLS];
    float averages[ROWS];

    inputTemperature(temperature);
    averageTemperaturePerRow(temperature, averages);

    cout << "\nAverage temperature per zone:\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Zone " << i + 1 << ": " << averages[i] << endl;
    }

    float hotLimit = 40.0;
    float coldLimit = 10.0;

    detectExtremeSpots(temperature, hotLimit, coldLimit);

    return 0;
}
