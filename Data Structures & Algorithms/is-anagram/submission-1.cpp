class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int , int> mps , mpt;
        int n = s.size();
        int m = t.size();
        for(int i = 0 ; i< n ; i++){
            mps[s[i]]++;
        }
        for(int i = 0 ; i < m ; i++){
            mpt[t[i]]++;
        }
        return mps == mpt;
    }
};
