class Solution {
public:
    int expandcenter(const string& s , int left , int right ){
        int n = s.size();
        int count = 0;
        while(right < n  && left >= 0 && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int total_cnt = 0;
        for(int i = 0 ; i < s.size() ; i++){
            total_cnt += expandcenter( s , i , i );
            total_cnt += expandcenter(s, i , i+1 );
        }
        return total_cnt;
    }
};
