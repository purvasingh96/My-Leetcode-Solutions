class TrieNode{
 public:
    vector<TrieNode*> children;
    bool isWord;
    string word;
    TrieNode(){
        isWord = false;
        children.resize(26, NULL);
        word="";
    }
};
class Solution {
private:
    void addWord(TrieNode* root, string s){
        
        TrieNode* curr = root;
        for(int i=0;i<s.length();i++){
            if(curr->children[s[i]-'a']==NULL){
                curr->children[s[i]-'a'] = new TrieNode();
            }
            curr = curr->children[s[i]-'a'];
        }
        curr->isWord=true;
        curr->word = s;
    }
    
    void getWords(TrieNode* root, vector<string>& res, int& k){
        if(k==0) return;
        if(root->isWord) {
            k--;
            res.push_back(root->word);
        }
        
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                getWords(root->children[i], res,k);
            }
        }
    }
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<TrieNode*> res(500);
        for(int i=0;i<res.size();i++){
            res[i] = new TrieNode();
        }
        unordered_map<string, int> m;
        int maxCount=0;
        for(auto x:words){
            m[x]+=1;
            maxCount = max(maxCount, m[x]);
        }
        
        for(auto x:m){
            addWord(res[x.second], x.first);
        }
        
        vector<string> ans;
        for(int i=maxCount;i>=0;i--){
            getWords(res[i], ans, k);
        }
        
        return ans;
        
    }
};