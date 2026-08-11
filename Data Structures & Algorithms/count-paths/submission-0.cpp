class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i , int j , int  m , int  n){
        if (i >= m || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int down =  rec(i+1 , j , m , n);
        int right =  rec(i , j+1 , m , n);
        return dp[i][j] = down + right ;

    }
    int uniquePaths(int m, int n) {
        dp.assign(m , vector<int>(n , -1));
        return rec(0 , 0 , m , n);
    }
};
