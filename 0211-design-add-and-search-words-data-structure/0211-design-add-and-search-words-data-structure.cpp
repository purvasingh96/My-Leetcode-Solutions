class Trie{
public:
    vector<Trie*> children;
    bool isWord;
    Trie(){
        children.resize(26, NULL);
        isWord=false;
    }
};

class WordDictionary {
private:
    Trie* root;
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for(auto c:word){
            int idx = c-'a';
            if(curr->children[idx]==NULL){
                curr->children[idx] = new Trie();
            }
            curr = curr->children[idx];
        }
        curr->isWord=true;
    }
    
    bool searchUtil(Trie* node, int idx, string& word){
        if(node==NULL) return false;
        if(idx== word.length() && node->isWord) return true;
        // we found prefix
        if(idx == word.length()) return false;
        
        bool ans=false;
        if(word[idx]=='.'){
            for(int i=0;i<26;i++){
                if(node->children[i]!=NULL){
                    ans = ans or searchUtil(node->children[i], idx+1, word);
                }
            }
        } else {
            if(node->children[word[idx]-'a']==NULL){
                return false;
            } else {
                ans = searchUtil(node->children[word[idx]-'a'], idx+1, word);
            }
        }
        
        return ans;
    }
    
    bool search(string word) {
        Trie* curr = root;
        return searchUtil(curr, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */