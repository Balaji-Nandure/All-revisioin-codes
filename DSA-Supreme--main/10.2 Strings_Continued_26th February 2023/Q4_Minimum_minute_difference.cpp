/*
Approach (for the code below):
------------------------------
Given a list of time points in "HH:MM" 24-hour format, the goal is to find the minimum difference in minutes between any two time points.

Steps used in this code:
1. Convert each time point to the number of minutes since midnight and store in a vector.
2. Sort the vector of minutes.
3. Iterate through the sorted vector and compute the difference between each pair of adjacent times, keeping track of the minimum difference.
4. Since the clock wraps around at midnight, also compute the difference between the last and first time points (i.e., (1440 - (last - first))).
5. Return the smallest difference found.

Note: This code uses sorting and does not use the boolean array optimization. If the number of time points exceeds 1440, there must be duplicates, and the answer would be 0 (not handled in this code).

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// Function to find the minimum difference in minutes between any two time points
int findMinDifference(vector<string>& timepoints) {
    vector<int> minutes;                      // store converted times
    for(string &t : timepoints) {             // iterate over all times
        int h = stoi(t.substr(0,2));          // extract hours
        int m = stoi(t.substr(3,2));          // extract minutes
        minutes.push_back(h*60 + m);          // convert to total minutes
    }
    
    sort(minutes.begin(), minutes.end());     // sort all times
    int ans = INT_MAX;                        // store min difference
    for(int i = 1; i < minutes.size(); i++)   // check adjacent times
        ans = min(ans, minutes[i]-minutes[i-1]); // update min gap
    
    int lastDiff = 1440 - (minutes.back() - minutes[0]); // wrap-around diff
    return min(ans, lastDiff);                // return smallest difference
}

/*
Alternative (Original) Approach (with sorting):
------------------------------------------------
int findMinDifference(vector<string>& timepoints){
    vector<int> minutes;
    for(const string& curr : timepoints){
        int hours = stoi(curr.substr(0,2));
        int mins = stoi(curr.substr(3,2));
        int totalminutes = hours*60 + mins;
        minutes.push_back(totalminutes);
    }
    sort(minutes.begin(), minutes.end());
    int n = minutes.size();
    int mini = INT_MAX;
    for(int i = 0; i < n-1; i++){
        int diff = minutes[i+1] - minutes[i];
        mini = min(mini, diff);
    }
    // Compare last and first (wrap around)
    int lastdiff = (minutes[0] + 1440) - minutes[n-1];
    mini = min(mini, lastdiff);
    return mini;
}
*/

// Dry Run Example:
// Input: {"23:59", "00:00"}
// "23:59" -> 1439 minutes, "00:00" -> 0 minutes
// seen[0] = true, seen[1439] = true
// first = 0, last = 1439
// minDiff = 1439 (1439-0), but then wrap around: (0+1440)-1439 = 1
// So, minDiff = 1

int main() {
    vector<string> timepoints{"23:59", "00:00"}; // Test case: edge case across midnight
    int ans = findMinDifference(timepoints);
    cout << ans; // Output: 1
    return 0;
}