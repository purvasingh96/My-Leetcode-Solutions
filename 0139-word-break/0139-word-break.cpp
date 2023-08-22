class TrieNode{
public:
    vector<TrieNode*> children;
    bool eow;
    TrieNode(){
        this->children.resize(26, NULL);
        this->eow= false;
    }
};

class Solution {
private:
    TrieNode* head;
    void insert(TrieNode* root, string& word){
        TrieNode* temp = root;
        
        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(temp->children[idx]==NULL){
                temp->children[idx] = new TrieNode();
            }
            temp =temp->children[idx];
        }
        temp->eow=true;
    }
    
    bool dfs(int pos, TrieNode* root, string& s, map<pair<int, TrieNode*>, bool>& dp){
        int idx = s[pos] - 'a';
        
        if(dp.find({pos,root})!=dp.end()) return dp[{pos,root}];
        
        if(pos == s.length()) {
            return dp[{pos,root}] = root->eow;
        }
        
        if(root->children[idx] == NULL) {
            if(root->eow){
                return dp[{pos,root}] = dfs(pos, head, s, dp);
            }
            return dp[{pos,root}] = false;
        }
        
        bool beginAgain = false, nextWord=false;
        if(root->eow){
            // can explore a diff word
            beginAgain= dfs(pos, head, s, dp);
        }
        
        nextWord = dfs(pos+1, root->children[idx], s, dp);
        return dp[{pos,root}] = beginAgain || nextWord;
        
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<pair<int, TrieNode*>, bool> dp;
        head = new TrieNode();
        TrieNode* root = head;
        for(auto word:wordDict) insert(root, word);
        
        return dfs(0, root, s, dp);
        
    }
};