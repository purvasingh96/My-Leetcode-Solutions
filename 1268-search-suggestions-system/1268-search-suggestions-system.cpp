class TrieNode{
public:
    vector<string> startsWith;
    vector<TrieNode*> children; 
    TrieNode(){
        children.resize(26, NULL);
    }
};


class Solution {
private:
    TrieNode* root;
    
    
    void insert(string& s){
        TrieNode* node = root;
        
        for(int i=0;i<s.length();i++){
            if(node->children[s[i] - 'a'] == NULL){
                node->children[s[i]-'a'] = new TrieNode();
            }
            node = node->children[s[i]-'a'];
            if(node->startsWith.size() < 3) node->startsWith.push_back(s);
        }
    }
    
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        sort(products.begin(), products.end());
        root = new TrieNode();
        
        int n = products.size();
        
        int sz = s.length();
        vector<vector<string>> res(sz, vector<string>());
        
        
        for(int i=0;i<products.size();i++){
            insert(products[i]);
        }
        
        TrieNode* node = root;
        
        for(int i=0;i<s.length();i++){
            if(node->children[s[i]-'a'] == NULL) {
                break;
            }
            
            node= node->children[s[i]-'a'];
            
            res[i] = node->startsWith;
        }
        
        return res;
        
    }
};