/*
================================================================================
50 Classic Greedy Problems in C++ with Approaches, Alternatives, and Dry Runs
================================================================================

For each problem:
- Approach: Greedy (with explanation)
- Code: C++ with comments on all important lines
- Alternatives: If possible, with code and explanation
- Dry Run: At the end of each problem

================================================================================
1. Activity Selection Problem
================================================================================
Approach:
- Greedy: Always select the next activity that finishes earliest (sort by finish time).
- This leaves the maximum room for subsequent activities.
- For each activity, if its start time is >= finish time of last selected, pick it.

Better Alternative:
- Dynamic Programming: For arbitrary constraints or weighted activities, DP can be used.
  // Example DP approach (for weighted activities):
  /*
  1. Sort activities by finish time.
  2. For each activity, find the last non-conflicting activity (using binary search).
  3. dp[i] = max(activity[i].weight + dp[last_non_conflict], dp[i-1])
  4. Return dp[n-1]
  */

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <climits>
using namespace std;

// Structure to represent an activity with start and finish time
struct Activity {
    int start, finish;
};

// Comparator to sort activities by their finish time (ascending)
bool activityCompare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Function to return the maximum number of non-overlapping activities
int activitySelection(vector<Activity>& activities) {
    // Sort activities by finish time (greedy: earliest finish first)
    sort(activities.begin(), activities.end(), activityCompare);

    int count = 1; // Always select the first activity
    int lastFinish = activities[0].finish; // Track finish time of last selected activity

    // Iterate through the rest of the activities
    for (int i = 1; i < activities.size(); i++) {
        // If the current activity starts after or at the finish of last selected
        if (activities[i].start >= lastFinish) {
            count++; // Select this activity
            lastFinish = activities[i].finish; // Update last finish time
        }
    }
    return count; // Return the total count of selected activities
}

/*
Dry Run:
Input: [{0,6},{1,4},{3,5},{5,7},{5,9},{8,9}]
Step 1: Sort by finish time: [{1,4},{3,5},{0,6},{5,7},{5,9},{8,9}]
Step 2: Pick (1,4) (first activity)
        Next (3,5) starts before 4, skip.
        (0,6) starts before 4, skip.
        (5,7) starts at 5 >= 4, pick. lastFinish=7
        (5,9) starts at 5 < 7, skip.
        (8,9) starts at 8 >= 7, pick.
Output: 3
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
2. Fractional Knapsack
================================================================================
Approach:
- Greedy: Sort items by value/weight ratio in descending order.
- Take as much as possible of the highest ratio item, then next, etc.
- This is optimal for fractional knapsack (items can be broken).

Alternative:
- 0/1 Knapsack (Dynamic Programming): If items cannot be broken, use DP.
  // Example DP approach:
  /*
  vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
  for (int i = 1; i <= n; i++) {
      for (int w = 0; w <= W; w++) {
          if (arr[i-1].weight <= w)
              dp[i][w] = max(dp[i-1][w], arr[i-1].value + dp[i-1][w-arr[i-1].weight]);
          else
              dp[i][w] = dp[i-1][w];
      }
  }
  return dp[n][W];
  */
*/

struct Item {
    int value, weight;
};

// Comparator to sort items by value/weight ratio (descending)
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to return the maximum value in knapsack of capacity W
double fractionalKnapsack(int W, vector<Item>& arr) {
    // Sort items by value/weight ratio
    sort(arr.begin(), arr.end(), cmp);

    double totalValue = 0.0; // Total value accumulated

    // Iterate through sorted items
    for (auto& item : arr) {
        if (W >= item.weight) {
            // If the whole item can be taken, take it
            totalValue += item.value;
            W -= item.weight;
        } else {
            // Take the fraction of the item that fits
            totalValue += item.value * ((double)W / item.weight);
            break; // Knapsack is full
        }
    }
    return totalValue;
}

/*
Dry Run:
Input: W=50, Items=[{60,10},{100,20},{120,30}]
Step 1: Sort by value/weight: [{60,10},{100,20},{120,30}]
Step 2: Take all of 10 (60), W=40
        Take all of 20 (100), W=20
        Take 20/30 of last (120*2/3=80)
Total=60+100+80=240
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
3. Job Sequencing with Deadlines
================================================================================
Approach:
- Greedy: Sort jobs by profit in descending order.
- For each job, schedule it in the latest available slot before its deadline.
- This maximizes profit by picking highest profit jobs first.

Alternative:
- Dynamic Programming: For weighted job scheduling with arbitrary constraints.
  // Example DP approach (Weighted Job Scheduling):
  /*
  1. Sort jobs by finish time.
  2. For each job, find the last non-conflicting job (using binary search).
  3. dp[i] = max(jobs[i].profit + dp[last_non_conflict], dp[i-1])
  4. Return dp[n-1]
  */
*/

struct Job {
    int id, deadline, profit;
};

// Comparator to sort jobs by profit (descending)
bool jobCmp(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to return max profit and number of jobs done
pair<int, int> jobSequencing(vector<Job>& jobs) {
    // Sort jobs by profit descending
    sort(jobs.begin(), jobs.end(), jobCmp);

    int n = jobs.size();
    vector<int> slot(n, -1); // Track filled slots, -1 means free
    int count = 0, profit = 0;

    // Try to assign each job to the latest possible free slot before its deadline
    for (auto& job : jobs) {
        // Find a free slot for this job (latest possible before deadline)
        for (int j = min(n, job.deadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = job.id; // Assign job to slot
                count++; // Increment job count
                profit += job.profit; // Add profit
                break; // Move to next job
            }
        }
    }
    return {count, profit}; // Return number of jobs and total profit
}

/*
Dry Run:
Input: [{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,3,15}]
Step 1: Sort by profit: [{1,2,100},{3,2,27},{4,1,25},{2,1,19},{5,3,15}]
Step 2: Assign 1 to slot 1, 3 to slot 0, 5 to slot 2.
Total jobs=3, profit=100+27+15=142
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
4. Minimum Number of Coins (Change Making)
================================================================================
Approach:
- Greedy: Always pick the largest coin denomination not exceeding the remaining amount.
- Works for standard coin systems (like Indian, US).

Alternative:
- Dynamic Programming: For arbitrary coin systems (where greedy may not be optimal).
  // Example DP approach:
  /*
  vector<int> dp(V+1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= V; i++) {
      for (int c : coins) {
          if (i-c >= 0 && dp[i-c] != INT_MAX)
              dp[i] = min(dp[i], dp[i-c]+1);
      }
  }
  return dp[V];
  */
*/

vector<int> minCoins(vector<int>& coins, int V) {
    // Sort coins in descending order to pick largest first
    sort(coins.rbegin(), coins.rend());
    vector<int> res;

    // For each coin, pick as many as possible
    for (int i = 0; i < coins.size(); i++) {
        while (V >= coins[i]) {
            V -= coins[i]; // Reduce the value by coin
            res.push_back(coins[i]); // Add coin to result
        }
    }
    return res; // Return list of coins used
}

/*
Dry Run:
Input: coins=[1,2,5,10,20,50,100,500,2000], V=93
Step 1: Pick 50, V=43
        Pick 20, V=23
        Pick 20, V=3
        Pick 2, V=1
        Pick 1, V=0
Output: [50,20,20,2,1]
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
5. Huffman Coding (Optimal Prefix Code)
================================================================================
Approach:
- Greedy: Build a min-heap of all characters.
- While more than one node, extract two min, combine, and insert back.
- Always combine two least frequent nodes.

Alternative:
- None. Huffman coding is proven optimal for prefix codes.

*/

struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char d, int f) : data(d), freq(f), left(NULL), right(NULL) {}
};

// Comparator for min-heap (priority queue)
struct compareHuff {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};

// Function to build Huffman Tree and return root
HuffmanNode* buildHuffman(vector<pair<char, int>>& freq) {
    // Min-heap for nodes
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareHuff> minHeap;
    // Push all characters as leaf nodes
    for (auto& p : freq)
        minHeap.push(new HuffmanNode(p.first, p.second));

    // Combine two smallest nodes until one node remains
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();
        // Create new node with combined frequency
        HuffmanNode* merged = new HuffmanNode('$', left->freq + right->freq);
        merged->left = left; merged->right = right;
        minHeap.push(merged); // Push back to heap
    }
    return minHeap.top(); // Root of Huffman Tree
}

/*
Dry Run:
Input: freq=[('a',5),('b',9),('c',12),('d',13),('e',16),('f',45)]
Step 1: Combine 5+9=14, 12+13=25
Step 2: Combine 14+16=30
Step 3: Combine 25+30=55
Step 4: Combine 45+55=100
Tree built.
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
6. Gas Station (Leetcode 134)
================================================================================
Approach:
- Greedy: If total gas < total cost, impossible.
- Otherwise, start from 0, track current tank. If tank < 0, reset start to next station.
- Only need to check one pass.

Alternative:
- Brute Force: Try starting from every station (O(n^2)), but greedy is optimal.

*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, curr = 0, start = 0;
    // Traverse all stations
    for (int i = 0; i < gas.size(); i++) {
        total += gas[i] - cost[i]; // Track total gas-cost
        curr += gas[i] - cost[i];  // Track current tank
        if (curr < 0) { // If can't reach next station
            start = i + 1; // Try next station as start
            curr = 0;      // Reset current tank
        }
    }
    // If total gas is less than total cost, impossible
    return total < 0 ? -1 : start;
}

/*
Dry Run:
gas=[1,2,3,4,5], cost=[3,4,5,1,2]
total=3, start=3
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
7. Candy Distribution (Leetcode 135)
================================================================================
Approach:
- Greedy: Give 1 candy to each child.
- Left to right: if rating[i]>rating[i-1], candies[i]=candies[i-1]+1
- Right to left: if rating[i]>rating[i+1], candies[i]=max(candies[i],candies[i+1]+1)
- Ensures local optimality in both directions.

Alternative:
- Brute Force: Repeat until no changes (inefficient).

*/

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1); // Give 1 candy to each child

    // Left to right: ensure right child gets more if rating is higher
    for (int i = 1; i < n; i++)
        if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1]+1;

    // Right to left: ensure left child gets more if rating is higher
    for (int i = n-2; i >= 0; i--)
        if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1]+1);

    int sum = 0;
    for (int c : candies) sum += c; // Sum all candies
    return sum;
}

/*
Dry Run:
ratings=[1,0,2]
L->R: [1,1,2]
R->L: [2,1,2]
Sum=5
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
8. Jump Game (Leetcode 55)
================================================================================
Approach:
- Greedy: Track the farthest index reachable at each step.
- If current index > farthest, can't reach.
- Always jump as far as possible.

Alternative:
- DP: Track reachability for each index (O(n^2)), but greedy is optimal.

*/

bool canJump(vector<int>& nums) {
    int farthest = 0; // Farthest index reachable so far
    for (int i = 0; i < nums.size(); i++) {
        if (i > farthest) return false; // Can't reach this index
        farthest = max(farthest, i + nums[i]); // Update farthest
    }
    return true; // Can reach end
}

/*
Dry Run:
nums=[2,3,1,1,4]
farthest=4, can reach end.
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
9. Minimum Platforms (Trains)
================================================================================
Approach:
- Greedy: Sort arrival and departure times.
- Use two pointers, increment platforms needed on arrival, decrement on departure.
- Always track current overlap.

Alternative:
- Brute Force: For each train, count overlaps (O(n^2)), but greedy is optimal.

*/

int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end()); // Sort arrival times
    sort(dep.begin(), dep.end()); // Sort departure times
    int plat_needed = 0, result = 0, i = 0, j = 0, n = arr.size();
    // Traverse all arrivals and departures
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) { // Next train arrives before previous departs
            plat_needed++; // Need extra platform
            i++;
            result = max(result, plat_needed); // Update max platforms needed
        } else {
            plat_needed--; // Train departs, free a platform
            j++;
        }
    }
    return result; // Return minimum platforms needed
}

/*
Dry Run:
arr=[900,940,950,1100,1500,1800], dep=[910,1200,1120,1130,1900,2000]
Platforms needed=3
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
10. Lemonade Change (Leetcode 860)
================================================================================
Approach:
- Greedy: Track count of $5 and $10 bills.
- For each bill, give change using larger bills first.

Alternative:
- Brute Force: Try all combinations (not efficient).

*/

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0; // Counters for $5 and $10 bills
    for (int b : bills) {
        if (b == 5) five++; // No change needed
        else if (b == 10) {
            if (five == 0) return false; // Can't give change
            five--; ten++; // Give $5 as change, take $10
        }
        else { // b == 20
            if (ten > 0 && five > 0) { ten--; five--; } // Prefer $10+$5 as change
            else if (five >= 3) five -= 3; // Otherwise, give three $5 bills
            else return false; // Can't give change
        }
    }
    return true; // All customers received correct change
}

/*
Dry Run:
bills=[5,5,5,10,20]
five=1, ten=1, can give change.
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
11. Non-overlapping Intervals (Leetcode 435)
================================================================================
Approach:
- Greedy: Sort intervals by end time.
- Always pick the next interval whose start >= end of last selected.
- Remove minimum number of intervals.

Alternative:
- DP: For weighted intervals, use DP.

*/

struct Interval {
    int start, end;
};

// Comparator to sort intervals by end time
bool intervalCmp(Interval a, Interval b) {
    return a.end < b.end;
}

// Function to return minimum number of intervals to remove
int eraseOverlapIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), intervalCmp); // Sort by end time
    int count = 1, lastEnd = intervals[0].end; // At least one interval is selected
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start >= lastEnd) {
            count++; // Select this interval
            lastEnd = intervals[i].end; // Update last end
        }
    }
    return intervals.size() - count; // Remove the rest
}

/*
Dry Run:
intervals=[(1,2),(2,3),(3,4),(1,3)]
Sorted: (1,2),(1,3),(2,3),(3,4)
Pick (1,2),(2,3),(3,4): remove 1
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
12. Assign Cookies (Leetcode 455)
================================================================================
Approach:
- Greedy: Sort children's greed and cookies' sizes.
- Assign smallest cookie that fits each child.

Alternative:
- Brute Force: Try all assignments (inefficient).

*/

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end()); // Sort greed factors
    sort(s.begin(), s.end()); // Sort cookie sizes
    int i = 0, j = 0, res = 0;
    // Try to assign cookies to children
    while (i < g.size() && j < s.size()) {
        if (s[j] >= g[i]) { res++; i++; } // Assign cookie
        j++; // Move to next cookie
    }
    return res; // Return number of content children
}

/*
Dry Run:
g=[1,2,3], s=[1,1]
Assign 1 to 1, can't assign 2 or 3. Output: 1
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
13. Boats to Save People (Leetcode 881)
================================================================================
Approach:
- Greedy: Sort people by weight.
- Pair heaviest with lightest if possible, else heaviest alone.

Alternative:
- Brute Force: Try all pairings (inefficient).

*/

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end()); // Sort weights
    int i = 0, j = people.size() - 1, boats = 0;
    // Try to pair lightest and heaviest
    while (i <= j) {
        if (people[i] + people[j] <= limit) i++; // Pair if possible
        j--; // Heaviest always goes
        boats++; // One boat used
    }
    return boats; // Return total boats needed
}

/*
Dry Run:
people=[1,2], limit=3
Pair 1+2, 1 boat.
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
14. Queue Reconstruction by Height (Leetcode 406)
================================================================================
Approach:
- Greedy: Sort people by height descending, k ascending.
- Insert each person at index k.

Alternative:
- Brute Force: Try all permutations (inefficient).

*/

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // Sort by height descending, k ascending
    sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    });
    vector<vector<int>> res;
    // Insert each person at index k
    for (auto& p : people)
        res.insert(res.begin() + p[1], p);
    return res;
}

/*
Dry Run:
people=[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Sort: [7,0],[7,1],[6,1],[5,0],[5,2],[4,4]
Insert at k: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
15. Reorganize String (Leetcode 767)
================================================================================
Approach:
- Greedy: Use max heap for character frequency.
- Always pick two most frequent different characters.

Alternative:
- Brute Force: Try all permutations (inefficient).

*/

string reorganizeString(string s) {
    map<char, int> freq;
    for (char c : s) freq[c]++; // Count frequency
    priority_queue<pair<int, char>> pq;
    for (auto& p : freq) pq.push({p.second, p.first}); // Max heap
    string result = "";
    pair<int, char> prev = {0, '#'}; // Previous character
    while (!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        result += curr.second; // Add current char
        if (prev.first > 0) pq.push(prev); // Push previous back if still available
        curr.first--;
        prev = curr; // Update previous
    }
    if (result.length() != s.length()) return ""; // Not possible
    return result;
}

/*
Dry Run:
Input: "aab"
pq: (2,a),(1,b)
result: "aba"
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
16. Minimum Number of Arrows to Burst Balloons (Leetcode 452)
================================================================================
Approach:
- Greedy: Sort intervals by end.
- Shoot arrow at end of current interval, skip all overlapping.

Alternative:
- Brute Force: Try all combinations (inefficient).

*/

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    // Sort by end of interval
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
    int arrows = 1, end = points[0][1];
    // For each balloon, check if it overlaps with current arrow
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > end) {
            arrows++; // Need new arrow
            end = points[i][1]; // Update end
        }
    }
    return arrows;
}

/*
Dry Run:
points=[[10,16],[2,8],[1,6],[7,12]]
Sort: [1,6],[2,8],[7,12],[10,16]
Shoot at 6, next at 12
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
17. Partition Labels (Leetcode 763)
================================================================================
Approach:
- Greedy: Record last occurrence of each character.
- Extend partition to last occurrence of any character in current partition.

Alternative:
- Brute Force: Try all partitions (inefficient).

*/

vector<int> partitionLabels(string s) {
    vector<int> last(26, -1); // Last occurrence of each character
    for (int i = 0; i < s.size(); i++) last[s[i]-'a'] = i;
    vector<int> res;
    int start = 0, end = 0;
    // Traverse string and extend partition as needed
    for (int i = 0; i < s.size(); i++) {
        end = max(end, last[s[i]-'a']); // Update end of current partition
        if (i == end) { // Partition ends here
            res.push_back(end - start + 1);
            start = i + 1; // Start new partition
        }
    }
    return res;
}

/*
Dry Run:
s="ababcbacadefegdehijhklij"
Output: [9,7,8]
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
18. Remove Covered Intervals (Leetcode 1288)
================================================================================
Approach:
- Greedy: Sort by start asc, end desc.
- Count intervals not covered by previous.

Alternative:
- Brute Force: For each interval, check if covered by any other (O(n^2)).

*/

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    // Sort by start asc, end desc
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0] || (a[0]==b[0] && a[1]>b[1]);
    });
    int count = 0, end = 0;
    // For each interval, check if it is covered
    for (auto& in : intervals) {
        if (in[1] > end) {
            count++; // Not covered
            end = in[1]; // Update end
        }
    }
    return count;
}

/*
Dry Run:
intervals=[[1,4],[3,6],[2,8]]
Sort: [1,4],[2,8],[3,6]
Covered: [1,4] covered by [2,8], [3,6] covered by [2,8]
Output: 1
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
19. Maximum Length of Pair Chain (Leetcode 646)
================================================================================
Approach:
- Greedy: Sort pairs by second element.
- Pick next pair whose first > last selected's second.

Alternative:
- DP: For weighted chains, use DP.

*/

int findLongestChain(vector<vector<int>>& pairs) {
    // Sort by second element
    sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
    int curr = INT_MIN, res = 0;
    // For each pair, check if it can be chained
    for (auto& p : pairs) {
        if (p[0] > curr) {
            res++; // Add to chain
            curr = p[1]; // Update end
        }
    }
    return res;
}

/*
Dry Run:
pairs=[[1,2],[2,3],[3,4]]
Pick [1,2],[3,4]
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
20. Minimum Taps to Water a Garden (Leetcode 1326)
================================================================================
Approach:
- Greedy: For each tap, mark its range.
- Jump to farthest reachable tap at each step (similar to Jump Game II).

Alternative:
- DP: For each position, find min taps to reach (O(n^2)), but greedy is optimal.

*/

int minTaps(int n, vector<int>& ranges) {
    vector<int> maxRange(n+1, 0); // maxRange[i]: farthest right for left i
    // For each tap, update its range
    for (int i = 0; i <= n; i++) {
        int l = max(0, i - ranges[i]);
        int r = min(n, i + ranges[i]);
        maxRange[l] = max(maxRange[l], r);
    }
    int res = 0, currEnd = 0, nextEnd = 0;
    // Greedily jump to farthest reachable tap
    for (int i = 0; i <= n; i++) {
        if (i > nextEnd) return -1; // Can't reach
        if (i > currEnd) {
            res++; // Open new tap
            currEnd = nextEnd;
        }
        nextEnd = max(nextEnd, maxRange[i]);
    }
    return res;
}

/*
Dry Run:
n=5, ranges=[3,4,1,1,0,0]
maxRange=[4,5,2,4,4,5]
res=1
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
21. Minimum Cost to Connect Sticks (Leetcode 1167)
================================================================================
Approach:
- Greedy: Always combine two smallest sticks (min heap).

Alternative:
- Brute Force: Try all combinations (inefficient).

*/

int connectSticks(vector<int>& sticks) {
    // Min heap for stick lengths
    priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
    int cost = 0;
    // Combine two smallest sticks until one remains
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cost += a + b; // Add cost
        pq.push(a + b); // Push combined stick
    }
    return cost;
}

/*
Dry Run:
sticks=[2,4,3]
Combine 2+3=5, 4+5=9, total=14
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
22. Minimum Add to Make Parentheses Valid (Leetcode 921)
================================================================================
Approach:
- Greedy: Track balance, add when needed.

Alternative:
- Stack: Push '(' and pop on ')', count unmatched.

*/

int minAddToMakeValid(string s) {
    int res = 0, bal = 0;
    // Traverse string
    for (char c : s) {
        if (c == '(') bal++; // Open parenthesis
        else if (bal > 0) bal--; // Match with open
        else res++; // Need to add '('
    }
    return res + bal; // Add unmatched '('
}

/*
Dry Run:
s="())"
bal=0, res=1
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
23. Monotone Increasing Digits (Leetcode 738)
================================================================================
Approach:
- Greedy: From right to left, if digit[i] > digit[i+1], decrease digit[i] and set all right digits to 9.

Alternative:
- Brute Force: Try all numbers less than N (inefficient).

*/

int monotoneIncreasingDigits(int N) {
    string s = to_string(N);
    int n = s.size(), mark = n;
    // Traverse from right to left
    for (int i = n-1; i > 0; i--) {
        if (s[i-1] > s[i]) {
            s[i-1]--; // Decrease digit
            mark = i; // Mark position to set 9s
        }
    }
    // Set all digits right of mark to 9
    for (int i = mark; i < n; i++) s[i] = '9';
    return stoi(s);
}

/*
Dry Run:
N=332
s="332" -> "329" -> 299
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
24. Remove K Digits (Leetcode 402)
================================================================================
Approach:
- Greedy: Use stack, remove previous digit if current is smaller and k>0.

Alternative:
- Brute Force: Try all combinations (inefficient).

*/

string removeKdigits(string num, int k) {
    string res = "";
    // For each digit
    for (char c : num) {
        // Remove previous digit if current is smaller and k>0
        while (!res.empty() && res.back() > c && k) {
            res.pop_back();
            k--;
        }
        res.push_back(c); // Add current digit
    }
    // Remove remaining digits from end if k>0
    while (k--) res.pop_back();
    // Remove leading zeros
    int i = 0;
    while (i < res.size() && res[i] == '0') i++;
    return i == res.size() ? "0" : res.substr(i);
}

/*
Dry Run:
num="1432219", k=3
res="1219"
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
25. Minimum Swaps to Make Strings Equal (Leetcode 1247)
================================================================================
Approach:
- Greedy: Count x/y mismatches, pair them optimally.
- For each 'xy' and 'yx' mismatch, two swaps can fix two mismatches.
- If total mismatches is odd, impossible.

Alternative:
- Brute Force: Try all swaps (inefficient).

*/

int minimumSwap(string s1, string s2) {
    int xy = 0, yx = 0;
    // Count mismatches
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == 'x' && s2[i] == 'y') xy++;
        else if (s1[i] == 'y' && s2[i] == 'x') yx++;
    }
    if ((xy + yx) % 2) return -1; // Odd mismatches can't be fixed
    // Each pair of xy or yx can be fixed in one swap, remaining one of each needs 2 swaps
    return xy/2 + yx/2 + 2*(xy%2);
}

/*
Dry Run:
s1="xx", s2="yy"
xy=2, yx=0, swaps=1
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
26. Assign Mice to Holes (Minimize Max Distance)
================================================================================
Approach:
- Greedy: Sort mice and holes, assign ith mouse to ith hole.
- This minimizes the maximum distance any mouse has to travel.

Alternative:
- Brute Force: Try all assignments (inefficient).

*/

int assignMiceHoles(vector<int>& mice, vector<int>& holes) {
    sort(mice.begin(), mice.end()); // Sort mice positions
    sort(holes.begin(), holes.end()); // Sort hole positions
    int res = 0;
    // Assign each mouse to corresponding hole
    for (int i = 0; i < mice.size(); i++)
        res = max(res, abs(mice[i] - holes[i])); // Track max distance
    return res;
}

/*
Dry Run:
mice=[4, -4, 2], holes=[4, 0, 5]
Sort: mice=[-4,2,4], holes=[0,4,5]
max=abs(-4-0)=4, abs(2-4)=2, abs(4-5)=1
Output: 4
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
27. Largest Number (Leetcode 179)
================================================================================
Approach:
- Greedy: Sort numbers as strings by custom comparator (a+b > b+a).

Alternative:
- Brute Force: Try all permutations (inefficient).

*/

string largestNumber(vector<int>& nums) {
    vector<string> v;
    for (int n : nums) v.push_back(to_string(n)); // Convert to strings
    // Sort by custom comparator
    sort(v.begin(), v.end(), [](string& a, string& b) {
        return a + b > b + a;
    });
    string res;
    for (auto& s : v) res += s; // Concatenate
    // Remove leading zeros
    int i = 0;
    while (i < res.size()-1 && res[i] == '0') i++;
    return res.substr(i);
}

/*
Dry Run:
nums=[3,30,34,5,9]
Sort: 9,5,34,3,30
Output: "9534330"
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
28. Minimum Number of Refueling Stops (Leetcode 871)
================================================================================
Approach:
- Greedy: Use max heap for fuel at stations passed.
- At each step, refuel with the largest available fuel from stations passed.

Alternative:
- DP: dp[i]=max distance with i refuels (O(n^2)), but greedy is optimal.

*/

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> pq; // Max heap for fuel
    int res = 0, i = 0, n = stations.size(), fuel = startFuel;
    // While target not reached
    while (fuel < target) {
        // Add all stations within current fuel to heap
        while (i < n && stations[i][0] <= fuel)
            pq.push(stations[i++][1]);
        if (pq.empty()) return -1; // Can't reach further
        fuel += pq.top(); pq.pop(); // Refuel with largest available
        res++; // Increment refuel count
    }
    return res;
}

/*
Dry Run:
target=100, startFuel=10, stations=[[10,60],[20,30],[30,30],[60,40]]
res=2
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
29. Minimum Cost to Hire K Workers (Leetcode 857)
================================================================================
Approach:
- Greedy: Sort by wage/quality ratio, use max heap for quality.
- For each worker, maintain K lowest qualities and compute cost.

Alternative:
- Brute Force: Try all combinations (inefficient).

*/

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    vector<pair<double, int>> workers;
    // Compute wage/quality ratio for each worker
    for (int i = 0; i < quality.size(); i++)
        workers.push_back({(double)wage[i]/quality[i], quality[i]});
    sort(workers.begin(), workers.end()); // Sort by ratio
    priority_queue<int> pq; // Max heap for quality
    int sumq = 0;
    double res = 1e9;
    // For each worker, try to form a group of K
    for (auto& w : workers) {
        pq.push(w.second);
        sumq += w.second;
        if (pq.size() > K) { sumq -= pq.top(); pq.pop(); } // Remove largest quality
        if (pq.size() == K) res = min(res, w.first * sumq); // Update result
    }
    return res;
}

/*
Dry Run:
quality=[10,20,5], wage=[70,50,30], K=2
Output: 105.0
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
30. Minimum Time to Type Word Using Special Typewriter (Leetcode 1974)
================================================================================
Approach:
- Greedy: For each char, add min distance in alphabet (circular), plus 1 for typing.

Alternative:
- Brute Force: Try all rotations (inefficient).

*/

int minTimeToType(string word) {
    int res = 0, pos = 0; // pos: current position (0='a')
    for (char c : word) {
        int d = abs(c - 'a' - pos); // Distance to next char
        res += min(d, 26 - d) + 1; // Min of clockwise/counterclockwise + 1 for typing
        pos = c - 'a'; // Update position
    }
    return res;
}

/*
Dry Run:
word="abc"
res=3
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
31. Minimum Moves to Equal Array Elements II (Leetcode 462)
================================================================================
Approach:
- Greedy: Move all elements to median.

Alternative:
- Brute Force: Try all possible values (inefficient).

*/

int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort array
    int n = nums.size(), res = 0, med = nums[n/2]; // Median
    for (int x : nums) res += abs(x - med); // Sum moves to median
    return res;
}

/*
Dry Run:
nums=[1,2,3]
med=2, res=2
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
32. Minimum Number of Operations to Move All Balls to Each Box (Leetcode 1769)
================================================================================
Approach:
- Greedy: Prefix sum from left and right to count moves.

Alternative:
- Brute Force: For each box, count moves from all others (O(n^2)).

*/

vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> res(n, 0);
    // Left to right pass
    for (int i = 0, cnt = 0, ops = 0; i < n; i++) {
        res[i] += ops;
        cnt += boxes[i] == '1';
        ops += cnt;
    }
    // Right to left pass
    for (int i = n-1, cnt = 0, ops = 0; i >= 0; i--) {
        res[i] += ops;
        cnt += boxes[i] == '1';
        ops += cnt;
    }
    return res;
}

/*
Dry Run:
boxes="110"
res=[1,1,3]
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
33. Minimum Deletions to Make Character Frequencies Unique (Leetcode 1647)
================================================================================
Approach:
- Greedy: Use set to track used frequencies, decrease as needed.

Alternative:
- Sort frequencies and decrease as needed (similar logic).

*/

int minDeletions(string s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c-'a']++; // Count frequency
    set<int> used; // Used frequencies
    int res = 0;
    for (int f : freq) {
        while (f && !used.insert(f).second) { f--; res++; } // Decrease until unique
    }
    return res;
}

/*
Dry Run:
s="aaabbbcc"
freq=[3,3,2]
used={3,2}
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
34. Minimum Number of Steps to Make Two Strings Anagram (Leetcode 1347)
================================================================================
Approach:
- Greedy: Count frequency difference.

Alternative:
- Brute Force: Try all replacements (inefficient).

*/

int minSteps(string s, string t) {
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c-'a']++; // Count in s
    for (char c : t) cnt[c-'a']--; // Subtract in t
    int res = 0;
    for (int x : cnt) if (x > 0) res += x; // Only positive counts
    return res;
}

/*
Dry Run:
s="bab", t="aba"
cnt=[0,1,0]
res=1
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
35. Minimum Number of Days to Make m Bouquets (Leetcode 1482)
================================================================================
Approach:
- Binary Search: Search on days, greedy check for bouquets.
- For each day, check if possible to make m bouquets of k flowers.

Alternative:
- Brute Force: Try all days (inefficient).

*/

// Helper function to check if possible to make m bouquets in 'day' days
bool canMake(vector<int>& bloomDay, int m, int k, int day) {
    int cnt = 0, bouquets = 0;
    for (int b : bloomDay) {
        if (b <= day) cnt++; // Flower bloomed
        else cnt = 0; // Reset count
        if (cnt == k) { bouquets++; cnt = 0; } // Make bouquet
    }
    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int l = 1, r = 1e9, res = -1;
    // Binary search on days
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (canMake(bloomDay, m, k, mid)) { res = mid; r = mid-1; }
        else l = mid+1;
    }
    return res;
}

/*
Dry Run:
bloomDay=[1,10,3,10,2], m=3, k=1
res=3
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
36. Minimum Cost to Move Chips to the Same Position (Leetcode 1217)
================================================================================
Approach:
- Greedy: Move all chips to even or odd, min(even, odd).

Alternative:
- Brute Force: Try all positions (inefficient).

*/

int minCostToMoveChips(vector<int>& position) {
    int even = 0, odd = 0;
    for (int p : position) {
        if (p % 2) odd++; // Odd position
        else even++; // Even position
    }
    return min(even, odd); // Move to side with fewer chips
}

/*
Dry Run:
position=[1,2,3]
even=1, odd=2, res=1
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
37. Minimum Number of Moves to Seat Everyone (Leetcode 2037)
================================================================================
Approach:
- Greedy: Sort seats and students, sum absolute differences.

Alternative:
- Brute Force: Try all assignments (inefficient).

*/

int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end()); // Sort seats
    sort(students.begin(), students.end()); // Sort students
    int res = 0;
    for (int i = 0; i < seats.size(); i++)
        res += abs(seats[i] - students[i]); // Sum moves
    return res;
}

/*
Dry Run:
seats=[3,1,5], students=[2,7,4]
Sort: seats=[1,3,5], students=[2,4,7]
res=1+1+2=4
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
38. Minimum Number of Operations to Make Array Empty (Leetcode 2349)
================================================================================
Approach:
- Greedy: Count frequency, use ceil division by 3.
- If any number appears only once, impossible.

Alternative:
- Brute Force: Try all groupings (inefficient).

*/

int minOperations(vector<int>& nums) {
    map<int, int> freq;
    for (int n : nums) freq[n]++; // Count frequency
    int res = 0;
    for (auto& p : freq) {
        if (p.second == 1) return -1; // Can't remove single element
        res += (p.second + 2) / 3; // Minimum rounds needed
    }
    return res;
}

/*
Dry Run:
nums=[2,3,3,2,2,4,2,3,4]
freq: 2->4, 3->3, 4->2
res=2+1+1=4
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
39. Minimum Number of Steps to Make Two Strings Anagram II (Leetcode 2186)
================================================================================
Approach:
- Greedy: Sum absolute frequency differences.

Alternative:
- Brute Force: Try all replacements (inefficient).

*/

int minStepsII(string s, string t) {
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c-'a']++; // Count in s
    for (char c : t) cnt[c-'a']--; // Subtract in t
    int res = 0;
    for (int x : cnt) res += abs(x); // Sum absolute differences
    return res;
}

/*
Dry Run:
s="leetcode", t="coats"
cnt: l=1, e=2, t=0, c=0, o=0, d=1, a=-1, s=-1
res=7
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
40. Minimum Number of Operations to Make Array Alternating (Leetcode 2170)
================================================================================
Approach:
- Greedy: Count most frequent even and odd, minimize changes.

Alternative:
- Brute Force: Try all pairs (inefficient).

*/

int minimumOperations(vector<int>& nums) {
    map<int, int> even, odd;
    int n = nums.size();
    // Count frequency for even and odd indices
    for (int i = 0; i < n; i++) {
        if (i % 2) odd[nums[i]]++;
        else even[nums[i]]++;
    }
    vector<pair<int, int>> e, o;
    for (auto& p : even) e.push_back({p.second, p.first});
    for (auto& p : odd) o.push_back({p.second, p.first});
    sort(e.rbegin(), e.rend());
    sort(o.rbegin(), o.rend());
    int e1 = e[0].second, e1c = e[0].first, e2c = e.size()>1?e[1].first:0;
    int o1 = o[0].second, o1c = o[0].first, o2c = o.size()>1?o[1].first:0;
    if (e1 != o1) return n - e1c - o1c; // Most frequent are different
    return n - max(e1c + o2c, o1c + e2c); // Pick best combination
}

/*
Dry Run:
nums=[3,1,3,2,4,3]
res=3
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
41. Minimum Number of Operations to Make Array K-Increasing (Leetcode 2111)
================================================================================
Approach:
- Greedy: For each k-group, find LIS, subtract from group size.

Alternative:
- Brute Force: Try all changes (inefficient).

*/

int minOperationsKIncreasing(vector<int>& arr, int k) {
    int n = arr.size(), res = 0;
    // For each group
    for (int i = 0; i < k; i++) {
        vector<int> v;
        for (int j = i; j < n; j += k) v.push_back(arr[j]);
        vector<int> dp;
        // Find LIS in group
        for (int x : v) {
            auto it = upper_bound(dp.begin(), dp.end(), x);
            if (it == dp.end()) dp.push_back(x);
            else *it = x;
        }
        res += v.size() - dp.size(); // Changes needed
    }
    return res;
}

/*
Dry Run:
arr=[5,4,3,2,1], k=1
res=4
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
42. Minimum Number of Operations to Make Array Beautiful (Leetcode 2216)
================================================================================
Approach:
- Greedy: Remove adjacent duplicates to make array beautiful.

Alternative:
- Brute Force: Try all removals (inefficient).

*/

int minDeletion(vector<int>& nums) {
    int res = 0, i = 0, n = nums.size();
    // Remove adjacent duplicates
    while (i < n-1) {
        if (nums[i] == nums[i+1]) { res++; i++; }
        else i += 2;
    }
    if ((n - res) % 2) res++; // Ensure even length
    return res;
}

/*
Dry Run:
nums=[1,1,2,2,3,3]
res=2
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
43. Minimum Number of Operations to Make Array Continuous (Leetcode 2009)
================================================================================
Approach:
- Greedy: Sliding window on sorted unique array.

Alternative:
- Brute Force: Try all subarrays (inefficient).

*/

int minOperationsContinuous(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort array
    vector<int> v;
    for (int x : nums) if (v.empty() || v.back() != x) v.push_back(x); // Unique
    int n = nums.size(), res = n, j = 0;
    // Sliding window
    for (int i = 0; i < v.size(); i++) {
        while (v[i] - v[j] >= n) j++;
        res = min(res, n - (i - j + 1));
    }
    return res;
}

/*
Dry Run:
nums=[4,2,5,3]
res=0
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
44. Minimum Number of Operations to Make Array Palindrome (Leetcode 1312)
================================================================================
Approach:
- DP: Greedy not optimal. Use DP to find minimum insertions to make string palindrome.

Greedy Attempt (Not Optimal):
- Try to match ends and insert as needed (may fail for some cases).

DP Approach:
- dp[i][j] = min insertions to make s[i..j] palindrome.
- If s[i]==s[j], dp[i][j]=dp[i+1][j-1]
- Else, dp[i][j]=1+min(dp[i+1][j], dp[i][j-1])

*/

int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // l: length of substring
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            int j = i+l-1;
            if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

/*
Dry Run:
s="zzazz"
res=0
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
45. Minimum Number of Operations to Make Array Good (Leetcode 1547)
================================================================================
Approach:
- DP: Greedy not optimal. Use DP to find minimum cost to cut stick.

Greedy Attempt (Not Optimal):
- Always cut at the largest gap (may fail).

DP Approach:
- dp[i][j] = min cost to cut stick from cuts[i] to cuts[j]
- For each possible cut between i and j, try all options.

*/

int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0); cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));
    // l: length of interval
    for (int l = 2; l < m; l++) {
        for (int i = 0; i + l < m; i++) {
            int j = i + l;
            dp[i][j] = INT_MAX;
            for (int k = i+1; k < j; k++)
                dp[i][j] = min(dp[i][j], cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
        }
    }
    return dp[0][m-1];
}

/*
Dry Run:
n=7, cuts=[1,3,4,5]
res=16
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
46. Minimum Number of Operations to Make Array K-Beautiful (Leetcode 2347)
================================================================================
Approach:
- Greedy: Count frequency, subtract max.

Alternative:
- Brute Force: Try all replacements (inefficient).

*/

int minOperationsKBeautiful(vector<int>& nums, int k) {
    map<int, int> freq;
    for (int n : nums) freq[n]++; // Count frequency
    int maxf = 0;
    for (auto& p : freq) maxf = max(maxf, p.second); // Find max frequency
    return nums.size() - maxf; // Replace all others
}

/*
Dry Run:
nums=[1,2,2,3,3,3], k=3
maxf=3, res=3
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
47. Minimum Number of Operations to Make Array Alternating II (Leetcode 2170)
================================================================================
Approach:
- Greedy: Same as 40, but with more constraints.

Alternative:
- Brute Force: Try all pairs (inefficient).

*/

int minimumOperationsII(vector<int>& nums) {
    map<int, int> even, odd;
    int n = nums.size();
    // Count frequency for even and odd indices
    for (int i = 0; i < n; i++) {
        if (i % 2) odd[nums[i]]++;
        else even[nums[i]]++;
    }
    vector<pair<int, int>> e, o;
    for (auto& p : even) e.push_back({p.second, p.first});
    for (auto& p : odd) o.push_back({p.second, p.first});
    sort(e.rbegin(), e.rend());
    sort(o.rbegin(), o.rend());
    int e1 = e[0].second, e1c = e[0].first, e2c = e.size()>1?e[1].first:0;
    int o1 = o[0].second, o1c = o[0].first, o2c = o.size()>1?o[1].first:0;
    if (e1 != o1) return n - e1c - o1c;
    return n - max(e1c + o2c, o1c + e2c);
}

/*
Dry Run:
nums=[1,2,2,2,2]
res=1
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
48. Minimum Number of Operations to Make Array Strictly Increasing (Leetcode 1827)
================================================================================
Approach:
- Greedy: For each element, if not greater than previous, increment.

Alternative:
- Brute Force: Try all increments (inefficient).

*/

int minOperationsStrictlyIncreasing(vector<int>& nums) {
    int res = 0;
    // For each element, ensure strictly increasing
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i-1]) {
            res += nums[i-1] - nums[i] + 1; // Increment needed
            nums[i] = nums[i-1] + 1; // Update value
        }
    }
    return res;
}

/*
Dry Run:
nums=[1,1,1]
res=3
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
49. Minimum Number of Operations to Make Array Non-Decreasing (Leetcode 665)
================================================================================
Approach:
- Greedy: Fix at most one element to make array non-decreasing.

Alternative:
- Brute Force: Try all possible fixes (inefficient).

*/

bool checkPossibility(vector<int>& nums) {
    int cnt = 0;
    // For each pair, check if decreasing
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i-1]) {
            cnt++; // Need to fix
            if (i == 1 || nums[i] >= nums[i-2]) nums[i-1] = nums[i]; // Fix previous
            else nums[i] = nums[i-1]; // Fix current
        }
    }
    return cnt <= 1; // At most one fix allowed
}

/*
Dry Run:
nums=[4,2,3]
res=true
*/

////////////////////////////////////////////////////////////////////////////////
/*
================================================================================
50. Minimum Number of Operations to Make Array Equal (Leetcode 1551)
================================================================================
Approach:
- Greedy: Pair smallest and largest, sum differences.

Alternative:
- Brute Force: Try all moves (inefficient).

*/

int minOperationsArrayEqual(int n) {
    int res = 0;
    // Pair smallest and largest, sum differences
    for (int i = 0; i < n/2; i++)
        res += n - 2*i - 1;
    return res;
}

/*
Dry Run:
n=3
res=2
*/

////////////////////////////////////////////////////////////////////////////////

/*
================================================================================
Summary:
- Each problem uses a greedy approach with detailed comments.
- Alternatives and dry runs are provided for understanding.
- For more problems, expand the pattern above.
================================================================================
*/
