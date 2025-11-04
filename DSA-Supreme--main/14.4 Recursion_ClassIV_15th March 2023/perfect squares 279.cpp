class Solution {
public:
    int numSquares(int n) {
        // // Approach 1: Pure recursion
        if(n==0) return 0;
        int minCount = INT_MAX;

        // try every perfect square <= n;
        for(int i=1; i*i <=n; i++){
            int sqr = i * i;
            int curr = 1 + numSquares(n - sqr);
            minCount = min(minCount, curr);
        }

        return minCount;
    }
};