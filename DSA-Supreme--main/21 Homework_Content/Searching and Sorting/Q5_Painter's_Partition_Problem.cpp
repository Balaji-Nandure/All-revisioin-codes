// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

/*
Approach Used:
---------------
This is a classic Binary Search on Answer problem. The goal is to partition the boards among k painters such that the maximum time taken by any painter is minimized.
- Each painter can only paint contiguous boards.
- The time taken to paint a board is proportional to its length (arr[i]).
- We use binary search to find the minimum possible maximum time.

Steps:
1. The minimum possible answer is the maximum board length (since at least one painter must paint the largest board).
2. The maximum possible answer is the sum of all board lengths (if only one painter paints all boards).
3. We perform binary search between these two values to find the minimum maximum time such that all boards can be painted by at most k painters.

isPossible() checks if it is possible to paint all boards within the given maximum time using at most k painters.

Better Alternatives:
--------------------
- DP Solution: O(n^2 * k) time, but not efficient for large n.
- Greedy + Binary Search (used here): O(n*log(sum of arr)), which is optimal for this problem.

Alternative DP code (for reference):
/*
long long dp[501][501];
long long sum(int arr[], int i, int j) {
    long long s = 0;
    for(int k = i; k <= j; k++) s += arr[k];
    return s;
}
long long solve(int arr[], int n, int k) {
    if(k == 1) return sum(arr, 0, n-1);
    if(n == 1) return arr[0];
    long long best = LLONG_MAX;
    for(int i = 1; i < n; i++) {
        best = min(best, max(solve(arr, i, k-1), sum(arr, i, n-1)));
    }
    return best;
}
*/

class Solution
{
  public:
    // Helper function to check if it is possible to paint all boards within 'maxTime' using at most k painters
    bool isPossible(int arr[], int n, int k, long long maxTime){
        long long timeSum = 0;      // Current painter's total time
        int painterCount = 1;       // Start with first painter

        for(int i = 0; i < n; i++){
            // If a single board is larger than maxTime, it's not possible
            if(arr[i] > maxTime){
                return false;
            }
            // If adding this board exceeds maxTime, assign to next painter
            if(timeSum + arr[i] > maxTime){
                painterCount++;     // Need one more painter
                timeSum = arr[i];   // Start new painter's sum
                // If painters exceed k, not possible
                if(painterCount > k){
                    return false;
                }
            }
            else{
                timeSum += arr[i];  // Add board to current painter
            }
        }
        return true; // All boards assigned within maxTime and k painters
    }

    // Main function to find the minimum time to paint all boards
    long long minTime(int arr[], int n, int k)
    {
        // The minimum possible time is the largest single board
        long long start = *max_element(arr, arr + n); // Optimization: start from max(arr)
        // The maximum possible time is the sum of all boards
        long long end = 0;
        for(int i = 0; i < n; i++){
            end += arr[i];
        }
        long long ans = end; // Initialize answer with the maximum possible time

        // Binary search to find the minimum maximum time
        while(start <= end){
            long long mid = start + (end - start) / 2; // Candidate for minimum time

            if(isPossible(arr, n, k, mid)){
                ans = mid;         // Store current answer
                end = mid - 1;     // Try to find a smaller maximum time
            }
            else{
                start = mid + 1;   // Increase the allowed maximum time
            }
        }
        return ans;
    }
};

/*
Dry Run Example:
----------------
arr = [10, 20, 30, 40], n = 4, k = 2

- start = max(arr) = 40
- end = sum(arr) = 100

Binary Search Steps:
1. mid = (40+100)/2 = 70
   isPossible(arr, 4, 2, 70) => true (Painter 1: 10+20+30=60, Painter 2: 40)
   ans = 70, end = 69

2. mid = (40+69)/2 = 54
   isPossible(arr, 4, 2, 54) => false (Painter 1: 10+20=30, Painter 2: 30, need 3rd painter for 40)
   start = 55

3. mid = (55+69)/2 = 62
   isPossible(arr, 4, 2, 62) => true (Painter 1: 10+20+30=60, Painter 2: 40)
   ans = 62, end = 61

4. mid = (55+61)/2 = 58
   isPossible(arr, 4, 2, 58) => false
   start = 59

5. mid = (59+61)/2 = 60
   isPossible(arr, 4, 2, 60) => true (Painter 1: 10+20+30=60, Painter 2: 40)
   ans = 60, end = 59

6. mid = (59+59)/2 = 59
   isPossible(arr, 4, 2, 59) => false
   start = 60

Loop ends. Final answer = 60.

Thus, minimum time to paint all boards with 2 painters is 60.
*/