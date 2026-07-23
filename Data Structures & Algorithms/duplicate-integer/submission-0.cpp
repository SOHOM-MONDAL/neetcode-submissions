class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int  , int>mp;
        for(int no : nums){
            if(mp.find(no) != mp.end())  return true; 
            mp[no]++;
        }
        return false;
    }
};