class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans ;
        for(auto no : nums){
            auto it = lower_bound(ans.begin() , ans.end() , no);

            if(it == ans.end()){
                ans.push_back(no);
            }
            else{
                *it = no;
            }
        }
        return ans.size();
    }
};
