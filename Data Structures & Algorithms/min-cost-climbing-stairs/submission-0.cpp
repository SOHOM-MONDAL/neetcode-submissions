class Solution {
public:
    vector<int>dp;
    int n ;
    vector<int> nums;
    int rec(int idx){
        if(idx == 0) return nums[idx];
        if(idx == 1) return nums[idx];

        if (dp[idx] != -1) return dp[idx];
        int one = nums[idx] + rec(idx -1);
        int  two = nums[idx] + rec(idx -2);
        return dp[idx] = min(one , two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        nums = cost;
        dp.assign(n, -1);
        return min(rec(n - 1), rec(n - 2));
    }
};
