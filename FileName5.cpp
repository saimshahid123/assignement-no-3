#include <iostream>
using namespace std;

const int TEAMS = 6;
const int ROUNDS = 4;

void inputScores(int scores[TEAMS][ROUNDS]) {
    for (int t = 0; t < TEAMS; t++) {
        cout << "Enter scores for Team " << t + 1 << " in " << ROUNDS << " rounds:\n";
        for (int r = 0; r < ROUNDS; r++) {
            cout << " Round " << r + 1 << ": ";
            cin >> scores[t][r];
        }
    }
}

void totalScores(int scores[TEAMS][ROUNDS], int totals[TEAMS]) {
    for (int t = 0; t < TEAMS; t++) {
        totals[t] = 0;
        for (int r = 0; r < ROUNDS; r++) {
            totals[t] += scores[t][r];
        }
    }
}

void findWinnerAndRunnerUp(int totals[TEAMS], int& winner, int& runnerUp) {
    winner = 0;
    runnerUp = -1;

    for (int i = 1; i < TEAMS; i++) {
        if (totals[i] > totals[winner]) {
            runnerUp = winner;
            winner = i;
        }
        else if (runnerUp == -1 || totals[i] > totals[runnerUp]) {
            runnerUp = i;
        }
    }
}

void displayTeamsWithLowScore(int scores[TEAMS][ROUNDS]) {
    cout << "\nTeams that scored 10 or less in any round:\n";
    bool found = false;
    for (int t = 0; t < TEAMS; t++) {
        for (int r = 0; r < ROUNDS; r++) {
            if (scores[t][r] <= 10) {
                cout << "Team " << t + 1 << endl;
                found = true;
                break; // No need to check further rounds for this team
            }
        }
    }
    if (!found) {
        cout << "None\n";
    }
}

int main() {
    int scores[TEAMS][ROUNDS];
    int totals[TEAMS];
    int winner, runnerUp;

    inputScores(scores);
    totalScores(scores, totals);
    findWinnerAndRunnerUp(totals, winner, runnerUp);

    cout << "\nTotal scores of each team:\n";
    for (int t = 0; t < TEAMS; t++) {
        cout << "Team " << t + 1 << ": " << totals[t] << endl;
    }

    cout << "\nWinner: Team " << winner + 1 << endl;
    cout << "Runner-up: Team " << runnerUp + 1 << endl;

    displayTeamsWithLowScore(scores);

    return 0;
}
