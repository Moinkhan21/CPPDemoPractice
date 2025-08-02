#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Function to find the minimum time difference in minutes
int findMinDifference(vector<string>& timePoints) {
    // Step 1: Convert time strings into total minutes from 00:00
    vector<int> minutes;
    for(int i = 0; i < timePoints.size(); i++) {
        string curr = timePoints[i];

        int hours = stoi(curr.substr(0, 2));     // Extract hours
        int mins = stoi(curr.substr(3, 2));      // Extract minutes
        int totalMinutes = hours * 60 + mins;    // Convert to minutes
        minutes.push_back(totalMinutes);
    }

    // Step 2: Sort the minutes vector in ascending order
    sort(minutes.begin(), minutes.end());

    // Step 3: Calculate the minimum difference between adjacent times
    int mini = INT_MAX;
    int n = minutes.size();

    for(int i = 0; i < n - 1; i++) {
        int diff = minutes[i + 1] - minutes[i];
        mini = min(mini, diff);  // Store the smallest difference
    }

    // Step 4: Handle the wrap-around case (e.g., 23:59 and 00:01)
    int wrapAroundDiff1 = (minutes[0] + 1440) - minutes[n - 1]; // 1440 mins = 24 hours
    int wrapAroundDiff2 = minutes[n - 1] - minutes[0];
    int wrapAroundDiff = min(wrapAroundDiff1, wrapAroundDiff2);// Smaller wrap-around difference
    mini = min(mini, wrapAroundDiff);

    return mini;
}

int main () {
    // Step A: Initialize the time points
    vector<string> timePoints = {"12:10", "10:15", "13:15", "17:20", "18:00", "19:47", "23:50"};

    // Step B: Call the function and output the result
    int result = findMinDifference(timePoints);
    cout << "Minimum Time Difference: " << result << " minutes" << endl;

    return 0; // Return 0 to indicate successful program execution
}
