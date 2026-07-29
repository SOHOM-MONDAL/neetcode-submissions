class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> nums = intervals;
        sort(nums.begin() , nums.end());
        int prevend = nums[0][1];
        int removal = 0;
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i][0] < prevend){
                removal++;
                prevend = min(prevend , nums[i][1]);
            }
            else{
                prevend = nums[i][1];
            }
        }
        return removal ;
    }
};
