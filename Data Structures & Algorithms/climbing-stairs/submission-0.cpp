class Solution {
public:
    vector<int>dp;
    int rec(int idx ){
        if(idx == 0){
            return 1;
        }
        if(dp[idx] != -1) return dp[idx];
        int one = rec(idx-1);
        int two = 0;
        if(idx > 1)two = rec(idx - 2);
        return dp[idx]= one + two;
    }
    int climbStairs(int n) {
        dp.assign(n+1 , -1 );
        int  ans =  rec(n);
        return ans;        
    }
};
