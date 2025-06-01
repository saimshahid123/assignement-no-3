#include <iostream>
using namespace std;

const int CANDIDATES = 4;
const int STATIONS = 6;

void inputVotes(int votes[STATIONS][CANDIDATES]) {
    for (int s = 0; s < STATIONS; s++) {
        cout << "Enter votes from Polling Station " << s + 1 << " for " << CANDIDATES << " candidates:\n";
        for (int c = 0; c < CANDIDATES; c++) {
            cout << " Candidate " << c + 1 << ": ";
            cin >> votes[s][c];
            if (votes[s][c] < 0) votes[s][c] = 0;
          }
  }
  }

void totalVotesPerCandidate(int votes[STATIONS][CANDIDATES], int totalCandidate[CANDIDATES]) {
    for (int c = 0; c < CANDIDATES; c++) {
        totalCandidate[c] = 0;
        for (int s = 0; s < STATIONS; s++) {
            totalCandidate[c] += votes[s][c];
      }
     }
  }

void totalVotesPerStation(int votes[STATIONS][CANDIDATES], int totalStation[STATIONS]) {
    for (int s = 0; s < STATIONS; s++) {
        totalStation[s] = 0;
        for (int c = 0; c < CANDIDATES; c++) {
            totalStation[s] += votes[s][c];
        }
    }
}

void findWinners(int totalCandidate[CANDIDATES]) {
    int maxVotes = totalCandidate[0];
    for (int c = 1; c < CANDIDATES; c++) {
        if (totalCandidate[c] > maxVotes) {
            maxVotes = totalCandidate[c];
        }
    }

    cout << "\nWinner(s) with " << maxVotes << " votes:\n";
    for (int c = 0; c < CANDIDATES; c++) {
        if (totalCandidate[c] == maxVotes) {
            cout << "Candidate " << c + 1 << endl;
        }
    }
}

void checkLowTurnout(int totalStation[STATIONS]) {
    bool found = false;
    cout << "\nPolling stations with turnout less than 100:\n";
    for (int s = 0; s < STATIONS; s++) {
        if (totalStation[s] < 100) {
            cout << "Polling Station " << s + 1 << " with total votes " << totalStation[s] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No polling station had turnout less than 100.\n";
    }
}

int main() {
    int votes[STATIONS][CANDIDATES];
    int totalCandidate[CANDIDATES];
    int totalStation[STATIONS];

    inputVotes(votes);
    totalVotesPerCandidate(votes, totalCandidate);
    totalVotesPerStation(votes, totalStation);

    cout << "\nTotal votes per candidate:\n";
    for (int c = 0; c < CANDIDATES; c++) {
        cout << "Candidate " << c + 1 << ": " << totalCandidate[c] << endl;
    }

    cout << "\nTotal votes per polling station:\n";
    for (int s = 0; s < STATIONS; s++) {
        cout << "Polling Station " << s + 1 << ": " << totalStation[s] << endl;
    }

    findWinners(totalCandidate);
    checkLowTurnout(totalStation);

    return 0;
}
