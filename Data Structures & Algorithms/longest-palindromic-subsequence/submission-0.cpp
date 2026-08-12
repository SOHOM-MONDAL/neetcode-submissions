class Solution {
public:
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string s) {
        
        int m = s.size();
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        dp.assign(m+1 , vector<int>(n+1 , -1));
        for(int i = 0 ; i <= m ; i++) dp[i][0] = 0;
        for(int j= 0 ; j <= n ; j++)  dp[0][j] = 0;


        for(int i = 1 ; i <= m ; i++){
            for(int j = 1; j <= n ; j++){
                dp[i][j] = (s[i-1] == t[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};