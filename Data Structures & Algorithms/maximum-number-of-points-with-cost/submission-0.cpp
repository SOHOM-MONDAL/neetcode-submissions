typedef long long ll;
class Solution {
public:
    vector<vector<ll>> dp;
    int m , n ;

    ll rec(ll i , ll j ,vector<vector<int>>& points){
        if(i <0 || i >= m || j < 0 || j >= n) return -1e9;

        if(i == m-1) return points[i][j];

        if(dp[i][j] != -1) return dp[i][j] ;
        ll r = i ; 
        ll c = j;
        ll mmax = -1e9;
        for(int z = 0 ; z < n ; z++){
            mmax = max( mmax  ,(ll)points[r][c] + (ll)rec(r+1 , z , points) - (ll)abs(z-c));
        }
        return dp[r][c] = mmax;
    }
    long long maxPoints(vector<vector<int>>& points) {
        m = points.size();
        n = points[0].size();
        dp.assign(m , vector<ll>(n , -1));
        ll ans = -1e9;
        for(int z = 0 ; z < n ; z++){
            ans = max(ans , rec(0 , z , points));
        }
        return ans; 
    }
};