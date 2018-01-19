class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] == 'X')
                    findBoard(board, i, j);
            }
        }
        return count;
    }

    void findBoard(vector<vector<char>> &board, int i, int j){

        cout << i << ", " << j << endl;
        for(int v = i+1; v < board.size() && board[v][j]=='X'; ++v)
            board[v][j] = '.';
        for(int h = j+1; h < board[i].size() && board[i][h]=='X'; ++h)
            board[i][h] = '.';
        ++count;
    }
private:
    int count = 0;

};