// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

/*
Approach Used in This Code (Binary Search on Answer Space):
-----------------------------------------------------------
1. The problem is to allocate books (with given number of pages) to M students such that:
   - Each student gets at least one book.
   - Each book is assigned to exactly one student.
   - Books are allocated in contiguous order.
   - The goal is to minimize the maximum number of pages assigned to a student.

2. We use Binary Search on the answer space (the minimum possible value of the maximum pages assigned).
   - The minimum possible value is the maximum number of pages in a single book (since a student must get at least one book).
   - The maximum possible value is the sum of all pages (if only one student gets all books).

3. For each mid value (candidate for the answer), we check if it is possible to allocate books such that no student gets more than mid pages.
   - If possible, try to minimize further (move left).
   - If not possible, increase the allowed pages (move right).

Time Complexity: O(N * log(sum of pages))
Space Complexity: O(1)

-----------------------------------------------------------
Better Alternative Approaches (with code):
------------------------------------------
1. Greedy + Binary Search (Optimal, as above): [This is the approach used]
2. Dynamic Programming (Not optimal for large N, O(N^2 * M)):
   - dp[i][j] = minimum of the maximum pages for first i books and j students.
   - Not shown here due to high time complexity.

Alternative DP code (for reference):
------------------------------------
/*
int dp[1001][51];
int solve(int A[], int n, int m) {
    if (m == 1) return accumulate(A, A+n, 0);
    if (n == 1) return A[0];
    if (dp[n][m] != -1) return dp[n][m];
    int res = INT_MAX;
    for (int i = 1; i < n; i++) {
        res = min(res, max(solve(A, i, m-1), accumulate(A+i, A+n, 0)));
    }
    return dp[n][m] = res;
}
*/

-----------------------------------------------------------
Dry Run Example:
----------------
A = [12, 34, 67, 90], N = 4, M = 2

- start = max(A) = 90, end = sum(A) = 203
- mid = (90+203)/2 = 146
  - Is it possible to allocate with max 146 pages? Yes (Student1: 12+34+67=113, Student2: 90)
  - Try smaller: end = 145
- mid = (90+145)/2 = 117
  - Is it possible? Student1: 12+34+67=113, Student2: 90 (OK)
  - Try smaller: end = 116
- mid = (90+116)/2 = 103
  - Is it possible? Student1: 12+34=46, Student2: 67, 90 (needs 3 students, not possible)
  - Try larger: start = 104
- Continue until start > end. Final answer: 113

-----------------------------------------------------------
*/

#include <numeric> // for accumulate
#include <climits> // for INT_MAX

class Solution 
{
public:
    // Helper function to check if it is possible to allocate books such that
    // no student gets more than 'maxPages' pages.
    bool isPossible(int A[], int N, int M, int maxPages) {
        int studentCount = 1;    // Start with first student
        int pageSum = 0;         // Current sum of pages for the current student

        for (int i = 0; i < N; i++) {
            // If a single book has more pages than maxPages, allocation is not possible
            if (A[i] > maxPages) {
                return false;
            }
            // If adding this book exceeds maxPages, allocate to next student
            if (pageSum + A[i] > maxPages) {
                studentCount++;      // Allocate to next student
                pageSum = A[i];      // Start counting pages for new student
                // If students required exceeds M, allocation not possible
                if (studentCount > M) {
                    return false;
                }
            } else {
                // Otherwise, add book to current student
                pageSum += A[i];
            }
        }
        // If allocation is possible within M students
        return true;
    }

    int findPages(int A[], int N, int M) 
    {
        // Edge case: If students are more than books, allocation not possible
        if (M > N) {
            return -1;
        }

        // The minimum possible value is the largest single book (no student can get less)
        int start = *std::max_element(A, A + N);
        // The maximum possible value is the sum of all pages (one student gets all books)
        int end = std::accumulate(A, A + N, 0);
        int ans = -1; // To store the minimum of the maximum pages

        // Binary search on the answer space
        while (start <= end) {
            int mid = start + (end - start) / 2; // Candidate for max pages

            if (isPossible(A, N, M, mid)) {
                ans = mid;         // Store current answer
                end = mid - 1;     // Try to find a better (smaller) answer
            } else {
                start = mid + 1;   // Increase allowed pages
            }
        }
        return ans;
    }
};

/*
Dry Run Example:
----------------
A = [12, 34, 67, 90], N = 4, M = 2

start = max(A) = 90, end = sum(A) = 203

1st Iteration:
    mid = (90+203)/2 = 146
    isPossible(146): Yes (Student1: 12+34+67=113, Student2: 90)
    -> ans = 146, end = 145

2nd Iteration:
    mid = (90+145)/2 = 117
    isPossible(117): Yes (Student1: 12+34+67=113, Student2: 90)
    -> ans = 117, end = 116

3rd Iteration:
    mid = (90+116)/2 = 103
    isPossible(103): No (needs 3 students)
    -> start = 104

4th Iteration:
    mid = (104+116)/2 = 110
    isPossible(110): No (needs 3 students)
    -> start = 111

5th Iteration:
    mid = (111+116)/2 = 113
    isPossible(113): Yes (Student1: 12+34+67=113, Student2: 90)
    -> ans = 113, end = 112

6th Iteration:
    mid = (111+112)/2 = 111
    isPossible(111): No (needs 3 students)
    -> start = 112

7th Iteration:
    mid = (112+112)/2 = 112
    isPossible(112): No (needs 3 students)
    -> start = 113

Loop ends (start > end). Final answer: 113

So, minimum of the maximum pages = 113.
*/