class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> e_board(9, vector<int>(9, 0));

        for(int i = 0;i < 9;i++) {
            for(int j = 0;j < 9;j++) {
                if(board[i][j] == '.') continue;
                else e_board[i][j] = board[i][j] - '0';
            }
        }


        unordered_map<int, bool> rows;
        unordered_map<int, bool> cols;
        unordered_map<int, bool> squas;
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++) {
                int val = e_board[i][j];
                if(val == 0) continue;
                int squa_index = (i / 3) * 3 + (j / 3);

                if(rows.contains(i * 10 + val) || cols.contains(j * 10 + val) || squas.contains(squa_index * 10 + val)) return false;
                rows[i * 10 + val] = true;
                cols[j * 10 + val] = true;
                squas[squa_index * 10 + val] = true;
            }
        }

        return true;
    }
};
