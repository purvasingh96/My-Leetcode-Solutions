class TrieNode{
public:
    vector<TrieNode*> children;
    string word;
    bool isWord;
    TrieNode(){
        children.resize(26, NULL);
        isWord=false;
    }
};


class Solution {
private:
    TrieNode* root;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<char>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    void insert(string word){
        TrieNode* head = root;
        for(int i=0;i<word.length();i++){
            if(head->children[word[i]-'a']== NULL){
                head->children[word[i]-'a'] = new TrieNode();
            }
            head= head->children[word[i]-'a'];
        }
        head->word = word;
        head->isWord = true;
    }
    
    void backtrack(int i, int j, vector<vector<char>>& board, TrieNode* root, unordered_set<string>& ans){
        
        if(root->isWord){
            ans.insert(root->word);
        }
        
        for(int k=0;k<4;k++){
            int new_x = i + dx[k];
            int new_y = j + dy[k];
            
            if(isValid(new_x, new_y, board) && board[new_x][new_y]!='#'){
                int idx = board[new_x][new_y] - 'a';
                if(root->children[idx]!=NULL){
                    TrieNode* tempRoot = root;
                    auto tempChar = board[new_x][new_y];
                    
                    root =root->children[idx];
                    board[new_x][new_y]='#';
                    backtrack(new_x, new_y, board, root, ans);
                    board[new_x][new_y] = tempChar;
                    root = tempRoot;
                    
                }
            }
            
        }
        
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for(auto word:words){
            insert(word);
        }
        unordered_set<string> ans;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(root->children[board[i][j] - 'a'] != NULL){
                    int idx = board[i][j] - 'a';
                    TrieNode* tempRoot = root;
                    auto tempChar = board[i][j];
                    
                    root =root->children[idx];
                    board[i][j]='#';
                    
                    backtrack(i, j, board, root, ans);
                    
                    board[i][j] = tempChar;
                    root = tempRoot;
                    
                }        
            }
        }
        vector<string> res(ans.begin(), ans.end());
        return res;
        
    }
};