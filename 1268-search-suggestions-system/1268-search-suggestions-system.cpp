class Trie{
public:
    bool end;
    vector<Trie*> children;
        
    Trie(){
        children.resize(26, NULL);
        end=false;
    }
    
};


class Solution {
private:
    Trie* root;
    void insert(string& word){
        Trie* node = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(node->children[idx]==NULL){
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->end=true;
    }
    
    void search(Trie* node, string partial, vector<string>& res){
        if(res.size() == 3) return;
        
        if(node->end) res.push_back(partial);
        
        for(int i=0;i<26;i++){
            if(node->children[i]!=NULL){
                char y = (i+'a');
                string x(1, y);
                search(node->children[i], partial+x, res);
                
            }
        }
    }
    
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        root = new Trie();
        for(auto x:products) insert(x);
        string partial = "";
        vector<vector<string>> ans;
        
        for(int i=0;i<s.length();i++){
            if(root->children[s[i]-'a']==NULL){
                while(i<s.length()){
                    ans.push_back({});
                    i+=1;
                } 
                return ans;
            } else{
                root = root->children[s[i]-'a'];
                partial += s[i];
                vector<string> res;
                search(root, partial, res);
                ans.push_back(res);
            }
            
        }
        
        
        return ans;
        
        
        
        
    }
};