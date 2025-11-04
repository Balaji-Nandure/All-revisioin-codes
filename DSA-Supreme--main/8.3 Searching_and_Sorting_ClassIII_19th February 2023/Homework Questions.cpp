// 1) Use the two for loops as done in square root to find the division of 2 numbers in decimals (Q2 - Division of 2 numbers using Binary Search) 
// 2) Find pair with difference k in the array
// 3) Find k closest element to a given value in an array
// 4) Exponential Search
// 5) Unbounded binary search
// 6) Book allocation 
// 7) Painter partition
// 8) Aggressive cows
// 9) Roti/paratha SPOJ
// 10) EKO Spoj
 

#include <bits/stdc++.h>
using namespace std;

/*
1) Division of 2 numbers using Binary Search (Decimals)
Problem: Find division of a/b up to certain decimal precision without using '/' operator.
Approach:
- Use binary search between 0 and a.
- Refine answer to decimal places using iterative approximation.
*/
double divideBinarySearch(double a, double b, int precision=6) {
    double low = 0, high = a, mid;
    double ans = 0;
    
    // Integer part
    while(low <= high) {
        mid = low + (high - low)/2;
        if(mid * b <= a) {
            ans = mid;
            low = mid + 1e-9; // small increment
        } else {
            high = mid - 1e-9;
        }
    }

    // Decimal part
    double increment = 0.1;
    for(int i = 0; i < precision; i++) {
        while(ans + increment <= a/b) ans += increment;
        increment /= 10;
    }

    return ans;
}

/*
2) Find pair with difference k in array
Problem: Given an array, find if any two numbers have difference k.
Approach:
- Sort array
- Use two pointers to find pair with difference k
*/
bool pairWithDiffK(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int i = 0, j = 1;
    while(j < arr.size()) {
        int diff = arr[j] - arr[i];
        if(diff == k && i != j) return true;
        else if(diff < k) j++;
        else i++;
    }
    return false;
}

/*
3) Find k closest elements to given value x
Problem: Given array, find k elements closest to x.
Approach:
- Use binary search to find position
- Use two pointers to expand around closest position
*/
vector<int> kClosestElements(vector<int>& arr, int k, int x) {
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - k;
    while(left < right) {
        int mid = (left + right)/2;
        if(x - arr[mid] > arr[mid+k] - x)
            left = mid + 1;
        else
            right = mid;
    }
    return vector<int>(arr.begin() + left, arr.begin() + left + k);
}

/*
4) Exponential Search
Problem: Search element in sorted array in O(log i) where i is position of element
Approach:
- Find range by exponentially increasing index
- Then do binary search in found range
*/
int binarySearch(vector<int>& arr, int l, int r, int x) {
    while(l <= r) {
        int m = l + (r-l)/2;
        if(arr[m] == x) return m;
        else if(arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int exponentialSearch(vector<int>& arr, int x) {
    if(arr[0] == x) return 0;
    int i = 1;
    while(i < arr.size() && arr[i] <= x) i *= 2;
    return binarySearch(arr, i/2, min((int)arr.size()-1, i), x);
}

/*
5) Unbounded Binary Search
Problem: Find element in an infinite sorted array (or very large)
Approach:
- Exponentially find bounds
- Binary search inside bounds
*/
int unboundedBinarySearch(vector<int>& arr, int x) {
    int l = 0, r = 1;
    while(r < arr.size() && arr[r] < x) {
        l = r;
        r *= 2;
    }
    return binarySearch(arr, l, min(r, (int)arr.size()-1), x);
}

/*
6) Book Allocation Problem
Problem: Allocate books to students such that maximum pages assigned to a student is minimized
Approach:
- Binary search on answer space
- Check feasibility with given max pages
*/
/*
Book Allocation Problem - Approach (Short Explanation):

We use binary search on the answer space (the minimum possible value of the maximum pages assigned to any student).
- The lowest possible value is the largest single book (since a student must get at least that much).
- The highest possible value is the sum of all pages (if one student gets all books).
- For each mid value, we check if it's possible to allocate books so that no student gets more than mid pages (using a helper function).
- If possible, we try for a smaller value (move left); otherwise, we try for a larger value (move right).
- The helper function simulates allocation: it counts how many students are needed if no one gets more than mid pages.

Code:
*/
bool isPossibleBookAllocation(vector<int>& arr, int n, int m, int maxPages) {
    int students = 1, sum = 0; // start with 1 student and 0 pages assigned
    for(int i=0;i<n;i++) { // iterate through all books
        if(arr[i] > maxPages) return false; // if a book has more pages than allowed, not possible
        if(sum + arr[i] > maxPages) { // if adding this book exceeds maxPages
            students++; // allocate to next student
            sum = arr[i]; // start sum for new student
        } else sum += arr[i]; // else add book to current student's sum
    }
    return students <= m; // return true if students used are within limit
}

int bookAllocation(vector<int>& arr, int n, int m) {
    int low = *max_element(arr.begin(), arr.end()); // minimum possible maxPages is largest book
    int high = accumulate(arr.begin(), arr.end(), 0); // maximum possible maxPages is sum of all pages
    int res = high; // initialize result with upper bound

    while(low <= high) { // binary search for minimum maxPages
        int mid = low + (high - low)/2; // calculate mid value
        if(isPossibleBookAllocation(arr, n, m, mid)) { // check if allocation possible with mid as maxPages
            res = mid; // update result to current mid
            high = mid - 1; // try to find smaller maxPages
        } else low = mid + 1; // else try with larger maxPages
    }
    return res; // return the minimum possible maxPages
}

/*
7) Painter Partition Problem
Problem: Partition boards among painters to minimize max time
Approach:
- Binary search on answer space
- Check feasibility with given max time
*/
/*
Painter Partition Problem - Approach (Short Explanation):

We use binary search on the answer space (the minimum possible value of the maximum time taken by any painter).
- The lowest possible value is the largest single board (since at least one painter must paint the largest board).
- The highest possible value is the sum of all board lengths (if only one painter paints all boards).
- For each mid value, we check if it's possible to paint all boards with at most k painters (using a helper function).
- If possible, we try for a smaller value (move left); otherwise, we try for a larger value (move right).
- The helper function simulates painting: it counts how many painters are needed if no one gets more than mid time.

Code:
*/
bool isPossiblePainter(vector<int>& arr, int n, int k, long long maxTime) {
    long long painters = 1, sum = 0; // start with 1 painter and 0 painted length
    for(int i=0;i<n;i++) { // iterate through all boards
        if(arr[i] > maxTime) return false; // if a board is longer than maxTime, not possible
        if(sum + arr[i] > maxTime) { // if adding this board exceeds maxTime for current painter
            painters++; // assign to next painter
            sum = arr[i]; // start sum for new painter
        } else sum += arr[i]; // else add board to current painter's sum
    }
    return painters <= k; // return true if painters used are within limit
}

long long painterPartition(vector<int>& arr, int n, int k) {
    long long low = *max_element(arr.begin(), arr.end()); // minimum possible maxTime is largest board
    long long high = accumulate(arr.begin(), arr.end(), 0LL); // maximum possible maxTime is sum of all boards
    long long res = high; // initialize result with upper bound

    while(low <= high) { // binary search for minimum maxTime
        long long mid = low + (high - low)/2; // calculate mid value
        if(isPossiblePainter(arr, n, k, mid)) { // check if allocation possible with mid as maxTime
            res = mid; // update result to current mid
            high = mid - 1; // try to find smaller maxTime
        } else low = mid + 1; // else try with larger maxTime
    }
    return res; // return the minimum possible maxTime
}

/*
8) Aggressive Cows
Problem: Place cows in stalls such that minimum distance between cows is maximized
Approach:
- Binary search on distance
- Check if placing cows with min distance is possible
*/
bool isPossibleCows(vector<int>& stalls, int n, int cows, int dist) {
    int lastPos = stalls[0];
    cows--;
    for(int i=1;i<n;i++) {
        if(stalls[i]-lastPos >= dist) {
            lastPos = stalls[i];
            cows--;
        }
    }
    return cows <= 0;
}

int aggressiveCows(vector<int>& stalls, int n, int cows) {
    sort(stalls.begin(), stalls.end());
    int low = 0, high = stalls[n-1]-stalls[0];
    int res = 0;

    while(low <= high) {
        int mid = (low + high)/2;
        if(isPossibleCows(stalls, n, cows, mid)) {
            res = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return res;
}

/*
9) Roti/Paratha SPOJ
Problem: Minimum time to cook P parathas using L cooks with different ranks
Approach:
- Binary search on time
- Check feasibility for given time
*/
bool isPossibleParatha(vector<int>& ranks, int cooks, int P, long long time) {
    int total = 0;
    for(int i=0;i<cooks;i++) {
        int t = 1, cnt = 0;
        while((long long)ranks[i]*t*(t+1)/2 <= time) {
            cnt++;
            t++;
        }
        total += cnt;
    }
    return total >= P;
}

long long parathaSPOJ(vector<int>& ranks, int cooks, int P) {
    long long low = 0, high = 1e8, res = high;
    while(low <= high) {
        long long mid = low + (high - low)/2;
        if(isPossibleParatha(ranks, cooks, P, mid)) {
            res = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return res;
}

/*
10) EKO SPOJ
Problem: Cut trees at height H such that sum of wood >= M
Approach:
- Binary search on height H
- Check if sum of wood >= M
*/
bool isPossibleEKO(vector<int>& trees, int n, long long M, int H) {
    long long wood = 0;
    for(int i=0;i<n;i++) {
        if(trees[i] > H) wood += trees[i]-H;
    }
    return wood >= M;
}

int EKO(vector<int>& trees, int n, long long M) {
    int low = 0, high = *max_element(trees.begin(), trees.end()), res = 0;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(isPossibleEKO(trees, n, M, mid)) {
            res = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    return res;
}

int main() {
    // You can test each function here
    vector<int> arr = {1,2,3,4,5};
    cout << "Division 10/3: " << divideBinarySearch(10, 3) << endl;
    cout << "Pair with diff 2 exists? " << pairWithDiffK(arr, 2) << endl;
    
    vector<int> arr2 = {1,3,5,7,9};
    vector<int> res = kClosestElements(arr2, 3, 6);
    cout << "3 closest to 6: ";
    for(int x: res) cout << x << " ";
    cout << endl;

    vector<int> arr3 = {1,2,3,4,5,6,7,8,9};
    cout << "Exponential search 5: " << exponentialSearch(arr3, 5) << endl;

    vector<int> arr4 = {1,2,3,4,5,6,7};
    cout << "Unbounded search 6: " << unboundedBinarySearch(arr4, 6) << endl;

    vector<int> books = {10,20,30,40};
    cout << "Book allocation for 2 students: " << bookAllocation(books, books.size(), 2) << endl;

    vector<int> boards = {10,20,30,40};
    cout << "Painter partition 2 painters: " << painterPartition(boards, boards.size(), 2) << endl;

    vector<int> stalls = {1,2,4,8,9};
    cout << "Aggressive cows: " << aggressiveCows(stalls, stalls.size(), 3) << endl;

    vector<int> ranks = {1,2,3};
    cout << "Paratha SPOJ min time: " << parathaSPOJ(ranks, 3, 6) << endl;

    vector<int> trees = {20,15,10,17};
    cout << "EKO SPOJ max height: " << EKO(trees, trees.size(), 7) << endl;

    return 0;
}
