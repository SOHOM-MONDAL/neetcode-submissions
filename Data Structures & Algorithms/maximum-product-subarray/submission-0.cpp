class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double max_so_far = nums[0];
        double min_so_far = nums[0];
        double result = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            double curr = nums[i];
            if(curr < 0){
                swap(max_so_far , min_so_far);
            }
            max_so_far = max(curr , max_so_far * curr);
            min_so_far = min(curr , min_so_far * curr);

            result = max(result , max_so_far);
        }
        return (int)result;
    }
};
