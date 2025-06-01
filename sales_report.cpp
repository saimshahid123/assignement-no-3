
#include <iostream>
using namespace std;

const int ITEMS = 4;
const int DAYS = 7;

void inputSales(float sales[DAYS][ITEMS]) {
    for (int d = 0; d < DAYS; d++) {
        cout << "Enter sales for Day " << d + 1 << ":
";
        for (int i = 0; i < ITEMS; i++) {
            cout << "  Item " << i + 1 << ": ";
            cin >> sales[d][i];
        }
    }
}

void totalSalesPerItem(float sales[DAYS][ITEMS], float itemTotals[ITEMS]) {
    for (int i = 0; i < ITEMS; i++) {
        itemTotals[i] = 0;
        for (int d = 0; d < DAYS; d++) {
            itemTotals[i] += sales[d][i];
        }
    }
}

void totalSalesPerDay(float sales[DAYS][ITEMS], float dayTotals[DAYS]) {
    for (int d = 0; d < DAYS; d++) {
        dayTotals[d] = 0;
        for (int i = 0; i < ITEMS; i++) {
            dayTotals[d] += sales[d][i];
        }
    }
}

int dayWithHighestSales(float dayTotals[DAYS]) {
    int maxDay = 0;
    for (int d = 1; d < DAYS; d++) {
        if (dayTotals[d] > dayTotals[maxDay]) {
            maxDay = d;
        }
    }
    return maxDay;
}

int itemSoldMost(float itemTotals[ITEMS]) {
    int maxItem = 0;
    for (int i = 1; i < ITEMS; i++) {
        if (itemTotals[i] > itemTotals[maxItem]) {
            maxItem = i;
        }
    }
    return maxItem;
}

int main() {
    float sales[DAYS][ITEMS];
    float itemTotals[ITEMS];
    float dayTotals[DAYS];

    inputSales(sales);
    totalSalesPerItem(sales, itemTotals);
    totalSalesPerDay(sales, dayTotals);

    int bestDay = dayWithHighestSales(dayTotals);
    int bestItem = itemSoldMost(itemTotals);

    cout << "\nTotal sales per item:\n";
    for (int i = 0; i < ITEMS; i++) {
        cout << "Item " << i + 1 << ": " << itemTotals[i] << endl;
    }

    cout << "\nTotal sales per day:\n";
    for (int d = 0; d < DAYS; d++) {
        cout << "Day " << d + 1 << ": " << dayTotals[d] << endl;
    }

    cout << "\nDay with highest total sales is Day " << bestDay + 1 << ".\n";
    cout << "Item sold the most overall is Item " << bestItem + 1 << ".\n";

    return 0;
}
