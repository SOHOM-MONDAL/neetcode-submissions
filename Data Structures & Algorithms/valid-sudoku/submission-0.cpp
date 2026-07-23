class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {        
        int m = board.size();
        int n = board[0].size();
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool sub[9][9] = {false};
        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j< n ; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';

                    int subindex = (i/3)*3 + (j/3);
                    if(row[i][num] || col[j][num] || sub[subindex][num] ){
                        return false;
                    }
                    row[i][num] = true;
                    col[j][num] = true;
                    sub[subindex][num] = true;
                }
            }
        }

        return true;
    }
};
