class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans ;
        vector<vector<int>> anagram;
        int n = strs.size();
        for(int i = 0 ;  i < n ; i++){
            string s = strs[i];
            vector<int> ch(26 , 0);
            bool match = false;
            for(int  j = 0 ; j < s.size() ; j++){
                ch[s[j] - 'a']++;
            }

            for( int j = 0 ; j < anagram.size() ; j++){
                if(ch == anagram[j]){
                    match = true;
                    ans[j].push_back(s);
                    break;
                }
            }
            if(!match){
                ans.push_back({s});
                anagram.push_back(ch);
            }
        }
        return ans ;
    }
};
