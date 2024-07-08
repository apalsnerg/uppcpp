#include <iostream>

using namespace std;

int timeToSeconds(int hours, int minutes, int seconds) {
    return ((hours * 60) + minutes) * 60 + seconds;
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
        cin >> endHour 
            >> endMin
            >> endSec;

        noOfComps += 1;

        /*
         * If the end time is before the start time, we know that we have passed midnight.
         * Thus, to get the true elapsed hours, we must get the difference between the start time and midnight,
         * and add it to how many hours elapsed after midnight. I.e:
         * To get the hours between the start-time and midnight, as in startTime + x = 24, we simplify to
         * x = 24 - startTime. Then, we just add the hours after
         * midnight to this time, since 0 + x = x. We do the same for minutes and seconds.
         * In this way we make a base accounting for passing the crossover points.
         */
        int curElapsedHours   = (endHour > startHour) ? endHour - startHour : 24 - startHour + endHour;
        int curElapsedMinutes = (endMin > startMin)   ? endMin  - startMin  : 60 - startMin  + endMin;
        int curElapsedSeconds = (endSec > startSec)   ? endSec  - startSec  : 60 - startSec  + endSec;

        /*
         * Now we must do some accounting. Let's list what we know:
         * If the minutes are equal, there must have passed an hour.
         * Same with seconds.
         * 
         */
        if (endSec < startSec || (endSec == 0 && startSec == 0)) {
            curElapsedMinutes -= 1;
        }
        if (endMin < startMin || (endMin == 0 && startMin == 0)) {
            curElapsedHours   -= 1;
        }
        if (curElapsedSeconds == 60) {
            curElapsedMinutes += 1;
            curElapsedSeconds = 0;
        }
        if (curElapsedMinutes == 60) {
            curElapsedHours += 1;
            curElapsedMinutes = 0;
        }
        if (curElapsedHours == 24) {
            curElapsedHours = 0;
        }

        /*
         * Instead of wasting time comparing hours and minutes and seconds,
         * convert to just seconds and see which is bigger
         */
        int curSecs    = timeToSeconds(curElapsedHours, curElapsedMinutes, curElapsedSeconds);
        int curWinSecs = timeToSeconds(elapsedHours, elapsedMinutes, elapsedSeconds);

        if(curSecs < curWinSecs || curWinSecs == 0) {
            elapsedHours   = curElapsedHours;
            elapsedMinutes = curElapsedMinutes;
            elapsedSeconds = curElapsedSeconds;
            winningRunner  = currentRunner;
        }
    }
    if (noOfComps == 0) {
        cout << "No competitors were entered." << "\n";
        cout << "The program ends. Good-bye!" << "\n";
        return 0;
    }

    cout << "Winner is starting number: " << winningRunner << "\n";
    cout << "Time elapsed: " << elapsedHours << " hours, " << elapsedMinutes << " minutes, and " << elapsedSeconds << " seconds." << "\n";
    cout << "Number of competitors: " << noOfComps << "\n";
    cout << "The program ends. Good-bye!" << "\n";
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
