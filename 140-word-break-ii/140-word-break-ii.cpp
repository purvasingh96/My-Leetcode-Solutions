class TrieNode{
public:
    vector<TrieNode*> children;
    bool iseow;
    TrieNode(){
        children.resize(26, NULL);
        iseow=false;
    }
};


class Trie{
 public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string s){
        
        TrieNode* node = root;
        
        for(int i=0;i<s.length();i++){
            
            if(node->children[s[i]-'a']==NULL){
                
                node->children[s[i]-'a'] = new TrieNode();
                
            }
            
            node = node->children[s[i]-'a'];
            
        }
        node->iseow=true;
    }
    
};


class Solution {
private:
    void dfs(TrieNode* node, TrieNode* root, string s, string temp, int i, vector<string>& res){
        
        if(i>=s.length()){
            if(node->iseow){
                res.push_back(temp);
            }
            return;
        }
        
        if(node->children[s[i]-'a']!=NULL){
            
            dfs(node->children[s[i]-'a'], root, s, temp+s[i], i+1, res);
            
            if(node->children[s[i]-'a']->iseow){
                dfs(root, root, s, temp+s[i]+" ", i+1, res);
            }
            
        }
        
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        
        for(auto word:wordDict){
            trie->insert(word);
        }
        vector<string> res;
        string temp="";
        dfs(trie->root, trie->root, s, temp, 0, res);
        return res;
    }
};