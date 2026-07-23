typedef long long ll ;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll sum = 1;
        int n = nums.size();
        if(n ==1) return {0};
        vector<ll> prefix(n , 0) , suffix(n , 0);
        for(int i = 0 ; i< n ; i++){
            sum *= nums[i];
            prefix[i] = sum;
        }
        sum = 1;
        for(int i = n-1 ; i >= 0 ; i--){
            sum *= nums[i];
            suffix[i] = sum; 
        }
        vector<int> ans;
        ans.push_back((int)suffix[1]);
        for(int i = 1 ; i < n-1 ; i++){
            ans.push_back((int)prefix[i-1] * (int)suffix[i+1]);
        }
        ans.push_back((int)prefix[n-2]);
        return ans;
    }
};
