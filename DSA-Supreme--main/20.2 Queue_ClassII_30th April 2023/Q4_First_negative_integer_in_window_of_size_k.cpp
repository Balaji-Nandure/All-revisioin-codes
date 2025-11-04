/*
Approach Used:
---------------
This code finds the first negative integer in every window of size k in a given array using a deque (double-ended queue). The deque stores indices of negative numbers in the current window. For each window, the front of the deque gives the index of the first negative integer. If there is no negative integer in the window, 0 is returned for that window.

Key Points:
- Efficient O(n) solution using deque to keep track of relevant negative numbers.
- Only indices of negative numbers are stored, making it easy to remove out-of-window elements.

Better Alternatives:
--------------------
1. **Brute Force (O(n*k)):**
   For each window, scan all k elements and find the first negative. This is slow for large n and k.

   // Brute force code:
   /*
   void firstNegativeBruteForce(int arr[], int n, int k) {
       for(int i=0; i<=n-k; i++) {
           bool found = false;
           for(int j=i; j<i+k; j++) {
               if(arr[j] < 0) {
                   cout << arr[j] << " ";
                   found = true;
                   break;
               }
           }
           if(!found) cout << "0 ";
       }
   }
   */

2. **Using Queue (std::queue) instead of deque:**
   Since we only pop from the front and push at the back, a queue can also be used.

3. **Store values instead of indices:**
   You can store the actual negative values, but then you need to check if the value is out of the window, which is less efficient than using indices.

4. **Sliding Window with Two Pointers:**
   Not as clean as the deque approach for this problem.

-----------------------------------
Code with detailed comments and improvements:
-----------------------------------
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// Function to print first negative integer in every window of size k
void solve(int arr[], int size, int k)
{
    vector<int> ans;              // Stores the result for each window
    deque<int> q;                 // Stores indices of negative numbers in the current window

    // Process the first window of size k
    for (int i = 0; i < k; i++)
    {
        // If current element is negative, store its index
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    // Process all remaining windows
    for (int i = k; i < size; i++)
    {
        // For the previous window, the answer is at the front of the deque (if any negative exists)
        if (!q.empty())
        {
            ans.push_back(arr[q.front()]); // First negative integer in the window
        }
        else
        {
            ans.push_back(0); // No negative integer in the window
        }

        // Remove indices that are out of the current window
        while (!q.empty() && q.front() <= i - k)
        {
            q.pop_front();
        }

        // If current element is negative, add its index to the deque
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    // Handle the last window (as it is not handled in the loop)
    if (!q.empty())
    {
        ans.push_back(arr[q.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // Print the result
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*
Dry Run:
--------
Input: arr[] = {12, -1, -7, 8, -15, 30, 16, 28}, size = 8, k = 3

Step-by-step windows:
Window 1: [12, -1, -7]   => First negative: -1
Window 2: [-1, -7, 8]    => First negative: -1
Window 3: [-7, 8, -15]   => First negative: -7
Window 4: [8, -15, 30]   => First negative: -15
Window 5: [-15, 30, 16]  => First negative: -15
Window 6: [30, 16, 28]   => No negative: 0

Output: -1 -1 -7 -15 -15 0

Deque status at each step:
- After first window: q = [1, 2]
- After window 2: q = [1, 2]
- After window 3: q = [2, 4]
- After window 4: q = [4]
- After window 5: q = [4]
- After window 6: q = []

*/

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = 8;
    int k = 3;
    solve(arr, size, k);
    return 0;
}