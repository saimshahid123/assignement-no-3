#include <iostream>
using namespace std;

const int PRODUCTS = 5;
const int USERS = 10;

void inputRatings(int ratings[PRODUCTS][USERS]) {
    for (int p = 0; p < PRODUCTS; p++) {
        cout << "Enter ratings for Product " << p + 1 << " from " << USERS << " users (1 to 5):\n";
       for (int u = 0; u < USERS; u++) {
             cout << " User " << u + 1 << ": ";
          cin >> ratings[p][u];
               if (ratings[p][u] < 1) ratings[p][u] = 1;
            else if (ratings[p][u] > 5) ratings[p][u] = 5;
         }
      }} 

void averageRatings(int ratings[PRODUCTS][USERS], float averages[PRODUCTS]) {
    for (int p = 0; p < PRODUCTS; p++) {
        int sum = 0;
        for (int u = 0; u < USERS; u++) {
            sum += ratings[p][u];
         }
        averages[p] = float(sum) / USERS;
  }
 }

void countPerfectRatings(int ratings[PRODUCTS][USERS], int perfectCount[PRODUCTS]) {
    for (int p = 0; p < PRODUCTS; p++) {
        perfectCount[p] = 0;
        for (int u = 0; u < USERS; u++) {
            if (ratings[p][u] == 5) {
                perfectCount[p]++;
            }
        }
    }
}

void displayWorstProducts(float averages[PRODUCTS]) {
    float worstScore = averages[0];
    for (int p = 1; p < PRODUCTS; p++) {
        if (averages[p] < worstScore) {
            worstScore = averages[p];
        }
    }
    cout << "\nProduct(s) with the worst average rating (" << worstScore << "):\n";
    for (int p = 0; p < PRODUCTS; p++) {
        if (averages[p] == worstScore) {
            cout << " Product " << p + 1 << endl;
        }
    }
}

int main() {
    int ratings[PRODUCTS][USERS];
    float averages[PRODUCTS];
    int perfectCount[PRODUCTS];

    inputRatings(ratings);
    averageRatings(ratings, averages);
    countPerfectRatings(ratings, perfectCount);

    cout << "\nAverage ratings per product:\n";
    for (int p = 0; p < PRODUCTS; p++) {
        cout << "Product " << p + 1 << ": " << averages[p] << endl;
    }

    cout << "\nNumber of perfect ratings (5) per product:\n";
    for (int p = 0; p < PRODUCTS; p++) {
        cout << "Product " << p + 1 << ": " << perfectCount[p] << endl;
    }

    displayWorstProducts(averages);

    return 0;
}
