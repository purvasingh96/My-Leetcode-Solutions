class TrieNode{
public:
    vector<TrieNode*> children;
    bool isWord;
    string word;
    TrieNode(){
        children.resize(26, NULL);
        isWord=false;
        word="";
    }
};

class Solution {
private:
    void insert(TrieNode* root, string word){
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(node->children[idx]==NULL){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isWord=true;
        node->word = word;
    }
    
    void getWords(TrieNode* root, int& k, vector<string>& ans){
        if(k==0) return;
        if(root->isWord) {
            k-=1;
            ans.push_back(root->word);
        }
        
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                getWords(root->children[i], k, ans);
            }
        }
    }
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<TrieNode*> res(n);
        for(int i=0;i<n;i++){
            res[i] = new TrieNode();
        }
        unordered_map<string, int> m;
        for(auto x:words) {
            m[x]+=1;
        }
        
        for(auto it:m){
            insert(res[it.second], it.first);
        }
        vector<string> ans;
        for(int i = n-1;i>=0;i--){
            getWords(res[i], k, ans);
            if(k==0) break;
        }
        return ans;
        
        
    }
};