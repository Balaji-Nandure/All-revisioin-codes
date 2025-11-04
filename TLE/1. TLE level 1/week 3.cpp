#include <bits/stdc++.h>
using namespace std;

/*
Problem: Fair Playoff Tournament (Codeforces 1535A)

Description:
- Four players participate in a playoff tournament.
- Player 1 vs Player 2
- Player 3 vs Player 4
- Winners of these two matches play in the final.

- Each player has a unique skill level s_i (1 <= s_i <= 100)
- Higher skill always wins in a match.
- Tournament is "fair" if the two players with highest skill meet in the final.

Input:
- t: number of test cases (1 <= t <= 10000)
- For each test case: 4 distinct integers s1, s2, s3, s4 (1 <= s_i <= 100)

Output:
- For each test case, print "YES" if tournament is fair, else "NO"

Example:
Input:
4
3 7 9 5
4 5 6 9
5 3 8 1
6 5 3 2

Output:
YES
NO
YES
NO

Approach:
1. Identify the two highest skill levels.
2. Determine winners of the first round:
   - Winner1 = max(s1, s2)
   - Winner2 = max(s3, s4)
3. Check if the two highest skills are Winner1 and Winner2.
   - If yes -> fair tournament -> YES
   - If no  -> unfair tournament -> NO
*/

// Function to solve one test case
void solveFairPlayoff() {
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    int winner1 = (s1 > s2 ? s1 : s2);
    int winner2 = (s3 > s4 ? s3 : s4);

    int skills[4] = {s1, s2, s3, s4};
    sort(skills, skills + 4);   // to get top two players

    int top1 = skills[3];
    int top2 = skills[2];

    if ((winner1 == top1 || winner1 == top2) &&
        (winner2 == top1 || winner2 == top2))
        cout << "YES\n";
    else
        cout << "NO\n";
}

/*
Problem: 320A — Magic Numbers

A “magic number” is a number formed by concatenation of **1**, **14**, and **144** in some order, any number of times.

For example:
- 14144, 141414, 1411 are magic numbers
- 1444, 514, 414 are not magic numbers

You are given a number **n** (1 ≤ n ≤ 10^9), with no leading zeros.
Check whether **n** is a magic number or not.

Input:
    A single integer n (1 ≤ n ≤ 10^9).

Output:
    Print "YES" if n is a magic number, otherwise print "NO".

Example:
    Input: 114114
    Output: YES

    Input: 1111
    Output: YES

    Input: 441231
    Output: NO

Approach / Idea:
- We can treat n as a string (since concatenations of “1”, “14”, “144”).
- Scan from left to right, trying to greedily match the longest possible “magic chunk”:
    - Check if prefix “144” is there, if yes, consume it.
    - Else if prefix “14” is there, consume it.
    - Else if prefix “1” is there, consume it.
    - Otherwise, it’s invalid.
- If at the end we successfully consume the entire string by these chunks, answer is YES; else NO.
  
Time complexity: O(length of string) which is O(log n) digits — trivial.

References: “A magic number is a number formed by concatenation of 1, 14 and 144.” :contentReference[oaicite:0]{index=0}
*/

bool isMagicNumber(const string &s) {
    int i = 0;
    int n = s.size();
    while (i < n) {
        // Try to match "144"
        if (i + 3 <= n && s.substr(i, 3) == "144") {
            i += 3;
        }
        // Else try "14"
        else if (i + 2 <= n && s.substr(i, 2) == "14") {
            i += 2;
        }
        // Else try "1"
        else if (s[i] == '1') {
            i += 1;
        }
        else {
            // None matches
            return false;
        }
    }
    return true;
}

/*
Problem: A. Required Remainder (Codeforces)

You are given three integers x, y and n.
Your task is to find the maximum integer k such that 0 ≤ k ≤ n and k mod x = y,
where mod is modulo operation.

You have to answer t independent test cases. It is guaranteed that such k exists.

Input:
  t               -- number of test cases (1 ≤ t ≤ 5*10^4)
Then t lines, each contains three integers x, y, n:
  2 ≤ x ≤ 10^9
  0 ≤ y < x
  y ≤ n ≤ 10^9

Output:
  For each test case print the maximum integer k (0 ≤ k ≤ n) such that k mod x = y.

Observation / formula:
  Let r = (n - y) % x
  Then the required k = n - r
  (equivalently: k = n - ( (n - y) mod x ) )

Example:
Input:
7
7 5 12345
5 0 4
10 5 15
17 8 54321
499999993 9 1000000000
10 5 187
2 0 999999999

Output:
12341
0
15
54321
9
185
999999999
*/

// Function that solves one test case and returns the answer
long long maxK(long long x, long long y, long long n) {
    long long diff = n - y;
    long long rem = diff % x;     // how far n is past a candidate with remainder y
    return n - rem;               // shift down to the nearest number with remainder y
}


int main() {
    // int t;
    // cin >> t;
    // while (t--) {
    //     solveFairPlayoff();   // call the function for each test case
    // }

    // --------------------------------------------------------------------
    // string x;
    // cin >> x;
    // cout << (isMagicNumber(x) ? "YES" : "NO") << "\n";
    // --------------------------------------------------------------------
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, n;
        cin >> x >> y >> n;
        cout << maxK(x, y, n) << '\n';
    }

    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    // --------------------------------------------------------------------
    return 0;
}