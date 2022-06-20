class TrieNode{
    
public:
    vector<TrieNode*> children;
    string word;
    TrieNode(){
        children.resize(26, NULL);
        word="";
    }
    
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    TrieNode* insert(string word){
        TrieNode* node = root;
        
        for(int i=0;i<word.length();i++){
            
            if(node->children[word[i]-'a']==NULL){
                
                node->children[word[i]-'a'] = new TrieNode();
                
            }
            
            node = node->children[word[i]-'a'];
            
        }
        
        node->word=word;
        return root;
    }
    
};

class Solution {
private:
    int dx[4] ={0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* node, vector<string>& ans){
        if(r<0 || c<0 || r==board.size() || c==board[0].size() || board[r][c]=='#' || node->children[board[r][c]-'a']==NULL){
            return;
        }
        
        char og = board[r][c];
        board[r][c] = '#';
        
        node = node->children[og-'a'];
        
        if(node->word!=""){
            ans.push_back(node->word);
            node->word="";
        }
        
        for(int i=0;i<4;i++){
            dfs(r+dx[i], c+dy[i], board, node, ans);
        }
        
        board[r][c] = og;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Trie* trie= new Trie();
        TrieNode* node;
        
        for(auto word:words){
            node = trie->insert(word);
        }
        
        cout<<"doj";
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(i, j, board, node, ans);
            }
        }
        
        return ans;
    }
};