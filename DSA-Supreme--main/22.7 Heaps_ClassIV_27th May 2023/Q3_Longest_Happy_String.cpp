// https://leetcode.com/problems/longest-happy-string/description/

/*
Approach Used:
---------------
- The problem is to construct the longest string using 'a', 'b', and 'c' such that no three consecutive characters are the same.
- We use a max heap (priority queue) to always pick the character with the highest remaining count.
- At each step, we greedily add up to two of the most frequent character, then up to two of the next most frequent, and so on, making sure not to violate the "no three consecutive" rule.
- We continue this process until no more valid characters can be added.

Better Alternative Approach:
---------------------------
- Instead of using a custom node class, we can use a pair<int, char> for simplicity.
- We can also check the last two characters of the result string to ensure we never add three consecutive same characters.
- This makes the code more readable and less error-prone.

Alternative Code (commented):
-----------------------------
/*
string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>> pq;
    if(a) pq.push({a, 'a'});
    if(b) pq.push({b, 'b'});
    if(c) pq.push({c, 'c'});
    string res = "";
    while(!pq.empty()) {
        auto [cnt1, ch1] = pq.top(); pq.pop();
        if(res.size() >= 2 && res.back() == ch1 && res[res.size()-2] == ch1) {
            if(pq.empty()) break;
            auto [cnt2, ch2] = pq.top(); pq.pop();
            res += ch2;
            if(--cnt2) pq.push({cnt2, ch2});
            pq.push({cnt1, ch1});
        } else {
            res += ch1;
            if(--cnt1) pq.push({cnt1, ch1});
        }
    }
    return res;
}
*/

class node{
    public:
        char data; // character ('a', 'b', or 'c')
        int count; // remaining count of this character
        node(char d,int c){
            data = d;
            count = c;
        }
};
// Comparator for max heap: higher count comes first
class compare{
    public:
        bool operator()(node a,node b){
            return a.count < b.count;
        }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Create a max heap to always get the character with the highest count
        priority_queue<node,vector<node>,compare>maxHeap;

        // Insert available characters into the heap if their count > 0
        if(a > 0){
            node temp('a',a);
            maxHeap.push(temp);
        }
        if(b > 0){
            node temp('b',b);
            maxHeap.push(temp);
        }
        if(c > 0){
            node temp('c',c);
            maxHeap.push(temp);
        }

        string ans = ""; // Resultant string

        // Process until there is more than one type of character left
        while(maxHeap.size()>1){
            node first = maxHeap.top(); // Get the character with highest count
            maxHeap.pop();
            node second = maxHeap.top(); // Get the character with second highest count
            maxHeap.pop();

            // Try to add up to 2 of the first character, but not more than needed
            int useFirst = min(2, first.count);
            // If last two characters are same as first.data, only add one
            if(ans.size() >= 2 && ans[ans.size()-1] == first.data && ans[ans.size()-2] == first.data)
                useFirst = 1;

            for(int i=0; i<useFirst; ++i) ans += first.data;
            first.count -= useFirst;

            // Try to add up to 2 of the second character, but not more than needed
            int useSecond = min(2, second.count);
            // If last two characters are same as second.data, only add one
            if(ans.size() >= 2 && ans[ans.size()-1] == second.data && ans[ans.size()-2] == second.data)
                useSecond = 1;

            // Only add second character if it is still available
            if(second.count > 0) {
                for(int i=0; i<useSecond; ++i) ans += second.data;
                second.count -= useSecond;
            }

            // Push back to heap if there are still some left
            if(first.count > 0){
                maxHeap.push(first);
            }
            if(second.count > 0){
                maxHeap.push(second);
            }
        }

        // If one character left, add up to 2 of it (but not 3 in a row)
        if(maxHeap.size() == 1){
            node temp = maxHeap.top();
            maxHeap.pop();
            int useTemp = min(2, temp.count);
            if(ans.size() >= 2 && ans[ans.size()-1] == temp.data && ans[ans.size()-2] == temp.data)
                useTemp = 0; // Can't add any more of this character
            for(int i=0; i<useTemp; ++i) ans += temp.data;
        }
        return ans;
    }
};

/*
Dry Run Example:
----------------
Input: a=1, b=1, c=7

Heap: [('c',7), ('b',1), ('a',1)]
ans = ""

1. Pop 'c'(7), 'b'(1)
   - Add 'cc' (since 7>=2), ans="cc", c=5
   - Add 'b' (since 1<2), ans="ccb", b=0
   - Push back 'c'(5), 'a'(1)

2. Pop 'c'(5), 'a'(1)
   - Add 'cc', ans="ccbcc", c=3
   - Add 'a', ans="ccbcca", a=0
   - Push back 'c'(3)

3. Only 'c'(3) left
   - Add 'cc', ans="ccbccacc", c=1

Final ans: "ccbccacc"
No three consecutive same characters.

Time Complexity: O((a+b+c) * log 3) ~ O(a+b+c)
Space Complexity: O(1) (since only 3 types of characters)
*/