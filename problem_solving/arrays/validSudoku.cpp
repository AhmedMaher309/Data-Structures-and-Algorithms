class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int current = 9;
        bool row[current][current] = {false};
        bool col[current][current] = {false};
        bool sub[current][current] = {false};
        
        for(int r = 0; r < current; r++){
            for(int c = 0; c < current; c++){
                if(board[r][c] == '.')
                    continue; 
                
                int idx = board[r][c] - '0' - 1; //convert the char to int
                int area = (r/3) * 3 + (c/3);
                
                if(row[r][idx] || col[c][idx] || sub[area][idx]){
                    return false;
                }
                
                row[r][idx] = true;
                col[c][idx] = true;
                sub[area][idx] = true;
            }
        }
        return true;
    }
};
