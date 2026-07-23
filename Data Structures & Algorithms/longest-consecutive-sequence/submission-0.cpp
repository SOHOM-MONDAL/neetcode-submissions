class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ch(nums.begin() , nums.end());
        int n = nums.size();
        int ans = 0;
        for(auto num : ch){
            if(ch.find(num-1) == ch.end()){
                int no = num;
                int streak = 1;
                while(ch.find(no+1) != ch.end()){
                    no++;
                    streak++;
                }
                ans = max(ans , streak );
            }
        }
        return ans ;

    }
};
