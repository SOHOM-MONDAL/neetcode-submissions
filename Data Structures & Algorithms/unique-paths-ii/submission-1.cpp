class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> nums ;
    int m ;
    int n ;
    int rec(int i , int j){

        if(i >= m  || j >= n) return 0;
        if(nums[i][j] ==1 ) return 0;

        if(i == m-1 && j == n-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];

        int down = rec(i+1 , j );
        int right = rec(i , j+1);

        return dp[i][j] = down + right ;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        nums = obstacleGrid ;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        dp.assign(m , vector<int>(n , -1));

        return rec(0 , 0);

    }
};