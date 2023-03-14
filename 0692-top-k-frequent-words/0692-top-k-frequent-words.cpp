class TrieNode{
public:
    bool isWord;
    vector<TrieNode*> children;
    string word;
    TrieNode(){
        children.resize(26, NULL);
        isWord = false;
        word="";
    }
};


class Solution {
private:
    void insert(TrieNode* root, string word){
        TrieNode* node = root;
        for(auto c:word){
            int idx=c-'a';
            if(node->children[idx]==NULL){
                node->children[idx] = new TrieNode();
            }
            node =node->children[idx];
        }
        node->isWord=true;
        node->word = word;
    }
    
    void getWords(TrieNode* root, int& k, vector<string>& ans){
        if(k==0) return;
        if(root->isWord){
            ans.push_back(root->word);
            k-=1;
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
        unordered_map<string, int> m;        
        vector<TrieNode*> count(n);
        vector<string> ans;
        
        for(auto x:words) m[x]+=1;
        for(int i=0;i<n;i++) count[i] = new TrieNode();
        for(auto it:m) insert(count[it.second], it.first);
        
        
        for(int i=n-1;i>=0;i--){
            getWords(count[i], k, ans);
            if(k==0) break;
        }
        
        return ans;
        
        
    }
};