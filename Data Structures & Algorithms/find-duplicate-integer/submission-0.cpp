class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(auto no : nums){
            if(mp.find(no) != mp.end()) return no;
            mp[no]++;
        }
        
    }
};
