#include <iostream>

using namespace std;

int timeToSeconds(int hours, int minutes, int seconds) {
return ((hours × 60) + minutes) × 60 + seconds;
}

int main() {

    int winningRunner;

    int noOfComps;

    int elapsedHours;
    int elapsedMinutes;
    int elapsedSeconds;

    while (true) {
        cout << "Enter a runner number: " << "\n" << ">> ";
        int currentRunner;
        cin >> currentRunner;
        if (currentRunner < 1) {
            break;
        }

        int startHour, startMin, startSec;
        cout << "Enter the time they started: " << "\n" << ">> ";
        cin >> startHour >> startMin >> startSec;

        int endHour, endMin, endSec;
        cout << "Enter the time they finished: " << "\n" << ">> ";
        cin >> endHour >> endMin >> endSec;

        noOfComps += 1;

        int curElapsedHours = (endHour > startHour) ? endHour - startHour : 24 - endHour + startHour;

        int curElapsedMinutes = (endMin > startMin) ? endMin - startMin : 60 - startMin + endMin;

        int curElapsedSeconds = (endSec > startSec) ? endSec - startSec : 60 - startSec + endSec;

        /*
         * Instead of wasting time comparing hours and minutes and seconds, convert to just seconds and see which is bigger
         */
        curSecs = timeToSeconds(curElapsedHours, curElapsedMinutes, curElapsedSeconds);
        curWinSecs = timeToSeconds(elapsedHours, elapsedMinutes, elapsedSeconds);

        if(curSecs < curWinSecs) {
            elapsedHours = curElapsedHours;
            elapsedMinutes = curElapsedMinutes;
            elapsedSeconds = curElapsedSeconds;
            winningRunner = currentRunner;
        }
    }
    if (noOfComps == 0) {
        cout << "No competitors were entered." << "\n";
        return 0;
    }

    cout << "Winner is starting number: " << winningRunner << "\n";
    cout << "Time elapsed: " << elapsedHours << ":" << elapsedMinutes << ":" << elapsedSeconds << "\n";
    cout << "Number of competitors: " << noOfComps << "\n";
    return 0;
}

/*
Start number? 33
Start time? 17 30 15
End time? 18 22 35
Start number? 14
Start time? 23 35 00
End time? 0 12 24
Starting number? 26
Start time? 10 11 12
End time? 20 21 22
Starting number? -1
Winner is starting number: 14 
Hour: 0 Min: 37 Sec: 24 
Number of competitors: 3 
The program ends
*/