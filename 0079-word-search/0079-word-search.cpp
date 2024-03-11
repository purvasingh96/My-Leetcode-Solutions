class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<char>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
    bool backtrack(string& temp, int pos, int i, int j, string word, vector<vector<char>>& board, vector<vector<bool>>& visited){
        //cout<<temp<<"\n";
        if(temp == word){
            return true;
        }
        
        bool ans=false;
        for(int k=0;k<4;k++){
            int new_x = i+dx[k];
            int new_y = j+dy[k];
            
            if(isValid(new_x, new_y, board) && board[new_x][new_y] == word[pos] && !visited[new_x][new_y]){
                visited[new_x][new_y] = true;
                temp.push_back(word[pos]);
                ans = ans || backtrack(temp, pos+1, new_x, new_y, word, board, visited);
                temp.pop_back();
                visited[new_x][new_y] = false;
            }
        }
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int pos=0, m = board.size(), n = board[0].size();
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                
                if(board[i][j] == word[0]){
                    string temp="";
                    temp += word[0];
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    if(backtrack(temp, 1, i, j, word, board, visited)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};