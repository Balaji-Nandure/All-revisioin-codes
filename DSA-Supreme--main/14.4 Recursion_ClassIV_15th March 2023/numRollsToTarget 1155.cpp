// // this is recursive solution best approach is in DP Sol.
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int solve(int n, int k, int target) {
        if(n == 0 && target == 0) return 1;
        if(n == 0 || target < 0) return 0;

        int ways = 0;
        for(int face = 1; face <= k; ++face) {
            ways = (ways + solve(n - 1, k, target - face)) % MOD;
        }
        return ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};

