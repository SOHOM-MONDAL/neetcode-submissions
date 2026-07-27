class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , 0);
        vector<int> nums2;
        vector<int> dp2(n , -1);
        for(int i = 1 ; i<n ; i++) nums2.push_back(nums[i]);


        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0] , nums[1]);

        dp[0] = nums[0];
        dp[1] = max(nums[1] , nums[0]);
        dp2[0] =nums2[0];
        dp2[1] = max(nums2[0]  , nums2[1]);

        for(int i = 2 ; i <n-1 ;i++){
            int pick = nums[i] + dp[i-2];
            int not_pick = dp[i-1];
            dp[i] = max(not_pick , pick); 
        }
        for(int i = 2 ; i <n-1 ;i++){
            int pick = nums2[i] + dp2[i-2];
            int not_pick = dp2[i-1];
            dp2[i] = max(not_pick , pick); 
        }
        return max(dp[n-2] , dp2[n-2]);
    }
};
