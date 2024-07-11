#include <iostream>

using namespace std;

/**
 * Converts hours, minutes, and seconds into just seconds.
 * Each hour is turned into 60 minutes, which is added to the already existing minutes,
 * which is then multiplied by 60 to get seconds.
 * 
 * @param hours the hour(s) to convert
 * @param minutes the minute(s) to convert
 * @param seconds the seconds we already have
 * 
 * @return the total number of seconds
 */
int timeToSeconds(int hours, int minutes, int seconds) {
    return ((hours * 60) + minutes) * 60 + seconds;
}

int main() {

    // Variable to store the winning runner.
    int winningRunner;

    //Variable to store the number of competitors.
    int noOfCompetitors;

    //Variables to store the values for the winning runner.
    int elapsedHours, elapsedMinutes, elapsedSeconds;

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

        noOfCompetitors += 1;

        /*
         * If the end time is before the start time, we know that we have passed midnight.
         * Thus, to get the true amount of elapsed hours,
         * we must get the difference between the start time and midnight,
         * and add it to how many hours elapsed after midnight. I.e:
         * To get the hours between the start-time and midnight, as in startTime + x = 24, we simplify to
         * x = 24 - startTime. Then, we just add the hours after
         * midnight to this time, since 0 + x = x. We do the same for minutes and seconds.
         * In this way we make a base accounting for passing the crossover points.
         * If that isn't the case, though, the total elapsed time is just the difference between the start and end.
         */
        int curElapsedHours   = (endHour > startHour) ? endHour - startHour : 24 - startHour + endHour;
        int curElapsedMinutes = (endMin > startMin)   ? endMin  - startMin  : 60 - startMin  + endMin;
        int curElapsedSeconds = (endSec > startSec)   ? endSec  - startSec  : 60 - startSec  + endSec;

        /*
         * Now we must do some maths accounting.
         *
         * If the end seconds are less than the start seconds, we know that a full minute has not passed.
         * For example, there isn't a minute's difference between 00:01:30 and 00:02:20, but
         * the program would think so since the minutes are different. Therefore we must account for that
         * and subtract that assumed minute difference. Same with seconds.
         */
        if (endSec < startSec || (endSec == 0 && startSec == 0)) {
            curElapsedMinutes -= 1;
        }
        if (endMin < startMin || (endMin == 0 && startMin == 0)) {
            curElapsedHours   -= 1;
        }

        /*
         * If the value is at a breakpoint, it must be converted.
         * We also assume that more than 24 hours have not passed.
         */
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

        // There might be a better way of algorithmizing the above, but this way works.

        /*
         * Here we print out information for the current runner.
         * If any of the time-pieces is 00, it'll print as 0, which doesn't look as good.
         * Instead, in such case that any of the pieces == 0, we print "00" instead.
         * We also print a dividing line to make it easier to read in the terminal.
         */
        cout << "Elapsed time for this runner: ";
        if (curElapsedHours != 0) {
            cout << curElapsedHours;
        } else {
            cout << "00";
        }
        
        if (curElapsedMinutes != 0) {
            cout << ":" << curElapsedMinutes;
        } else {
            cout << ":00";
        }
        
        if (curElapsedSeconds != 0) {
            cout << ":" << curElapsedSeconds;
        } else {
            cout << ":00" << endl;
        }

        cout << "\n" << "-----------------------------" << endl;

        /*
         * Instead of comparing hours and minutes and seconds,
         * we can convert to just seconds and see which is bigger.
         */
        int curSecs    = timeToSeconds(curElapsedHours, curElapsedMinutes, curElapsedSeconds);
        int curWinSecs = timeToSeconds(elapsedHours, elapsedMinutes, elapsedSeconds);

        /*
         * If this is the first run, or if the total seconds for the current runner
         * is smaller than the total seconds for the winning runner, set the winner data to this runner.
         */
        if(curSecs < curWinSecs || curWinSecs == 0) {
            elapsedHours   = curElapsedHours;
            elapsedMinutes = curElapsedMinutes;
            elapsedSeconds = curElapsedSeconds;
            winningRunner  = currentRunner;
        }
    }

    // If no competitors were entered, i.e. if the first runner number was less than 1
    if (noOfCompetitors == 0) {
        cout << "No competitors were entered." << "\n";
        cout << "The program ends. Good-bye!" << "\n";
        return 0;
    }

    cout << "Winner is starting number: " << winningRunner << "\n";
    cout << "Time elapsed: " << elapsedHours << " hours, " << elapsedMinutes << " minutes, and " << elapsedSeconds << " seconds." << "\n";
    cout << "Number of competitors: " << noOfCompetitors << "\n";
    cout << "The program ends. Good-bye!" << "\n";
    return 0;
}
