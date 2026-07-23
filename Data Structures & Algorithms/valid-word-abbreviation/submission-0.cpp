class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        int n = word.size();
        int m = abbr.size();
        string abrr = abbr;
        
        while(i < n && j < m){
            if(word[i] == abbr[j]){
                i++;
                j++;
            }
            else if(abrr[j] == '0'){
                return false;
            }
            else if(abrr[j] >= '1' && abrr[j] <= '9'){
                string s = "";
                while(j < m && (abrr[j] >= '0' && abrr[j] <= '9')){
                    s += abrr[j];
                    j++;
                }
                int num = stoi(s);
                i += num;
            } 
            else {
                return false;
            }
        }
        
        if(i == n && j == m) return true;
        return false;
    }
};