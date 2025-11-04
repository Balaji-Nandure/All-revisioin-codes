#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;
        vector<int> counts;
        for (auto& p : freq)
            counts.push_back(p.second);
        return backtrack(counts, quantity, 0);
    }

    bool backtrack(vector<int>& counts, vector<int>& quantity, int k) {
        if (k == quantity.size())
            return true;
        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] >= quantity[k]) {
                counts[i] -= quantity[k];
                if (backtrack(counts, quantity, k + 1))
                    return true;
                counts[i] += quantity[k]; // backtrack
            }
        }
        return false;
    }
};
