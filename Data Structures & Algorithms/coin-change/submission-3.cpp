class Solution {
public:
    vector<int> nums;
    int n ;
    vector<vector<int>> dp;
    int rec(int idx , int t){
        if(t == 0) return dp[idx][t] = 0;
        if(idx == 0){
            if(t % nums[idx] == 0){
                return dp[idx][t] = t / nums[idx];
            }
            return dp[idx][t] = 1e9;
        }
        if(dp[idx][t] != -1) return dp[idx][t];
        int pick = 1e9;
        if(t >= nums[idx]){
            pick = 1 + rec(idx , t - nums[idx]);
        }
        int not_pick = rec(idx -1 , t);
        return dp[idx][t] = min(pick , not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        nums = coins;
        n = coins.size();
        if(n == 1) return (amount % coins[0] == 0) ? amount/coins[0] : -1;
        dp.assign(n , vector<int>(amount+1, -1));
        int ans = rec(n-1 , amount);
        return ans >= 1e9 ? -1 : ans;
    }
};