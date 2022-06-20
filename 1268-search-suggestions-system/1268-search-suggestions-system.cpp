class TrieNode{
public:
    vector<TrieNode*> children;
    vector<string> suggestions;
    
    TrieNode(){
        children.resize(26, NULL);
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string s){
        TrieNode* node = root;
        
        for(int i=0;i<s.length();i++){
            
            if(node->children[s[i]-'a']==NULL){
                node->children[s[i]-'a']=new TrieNode();
            }
            
            node = node->children[s[i]-'a'];
            if(node->suggestions.size()<3) node->suggestions.push_back(s);            
        }
        
    }
    
    vector<string> dfs(string s){
        vector<string> ans;
        TrieNode* node = root;
        
        for(int i=0;i<s.length();i++){
            if(node->children[s[i]-'a']==NULL){
                return ans;
            }
            node=node->children[s[i]-'a'];
        }
        
        //vector<string> sug = node->suggestions;
        //sort(sug.begin(), sug.end());
        
        // if(sug.size()>3){
        //     ans.insert(ans.end(), sug.begin(), sug.begin()+3);
        // } else{
        //     ans = sug;
        // }
        return node->suggestions;
        
    }
    
    
};



class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        Trie* trie = new Trie();
        
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        
        for(auto product:products){
            trie->insert(product);
        }
        
        for(int i=1;i<=s.length();i++){
            string t = s.substr(0, i);
                
                vector<string> res = trie->dfs(t);
                ans.push_back(res);
            
            
        }
        
        return ans;
    }
};