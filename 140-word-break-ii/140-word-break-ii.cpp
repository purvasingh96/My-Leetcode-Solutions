class TrieNode{
public:
    vector<TrieNode*> children;
    bool eow;
    TrieNode(){
        children.resize(26, NULL);
        eow=false;
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
        
        node->eow=true;
        
    }
};

class Solution {
private:
    void dfs(int i, string s, string temp, TrieNode* node, TrieNode* root, vector<string>& ans){
        
        if(i>=s.length()){
            if(node->eow) ans.push_back(temp);
            return;
        }
        
        if(node->children[s[i]-'a']!=NULL){
            
            dfs(i+1, s, temp+s[i], node->children[s[i]-'a'], root, ans);
            
            if(node->children[s[i]-'a']->eow==true){
                
                dfs(i+1, s, temp+s[i]+' ', root, root, ans);
                
            }
            
        }
        
        
    }
    
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        Trie* trie = new Trie();
        
        
        for(auto word:wordDict){
            trie->insert(word);
        }
        
        string temp="";
        dfs(0, s, temp, trie->root, trie->root, ans);
        return ans;
        
    }
};