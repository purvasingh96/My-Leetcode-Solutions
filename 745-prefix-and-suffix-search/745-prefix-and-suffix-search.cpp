class TrieNode{
public:
    vector<TrieNode*> children;
    int weight;

    TrieNode(){
        children.resize(27, NULL);
        weight=0;
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string s, int idx){
        TrieNode* node = root;
        
        for(int i=0;i<s.length();i++){
            if(node->children[s[i]-'a'] == NULL){
                node->children[s[i]-'a'] = new TrieNode();
            }    
            node = node->children[s[i]-'a'];
            node->weight=idx;
        }
        
    }
    
    int search(string s){
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(node->children[s[i]-'a']==NULL){
                return -1;
            }
            node = node->children[s[i]-'a'];
        }
        
        return node->weight;
    }
};
    


class WordFilter {
private:
    Trie* front;
public:
    WordFilter(vector<string>& words) {
        front = new Trie();
        
        for(int i=0;i<words.size();i++){
            string word = words[i];
            
            for(int j=0;j<=word.length();j++){
                string left  = word.substr(j);
                string temp = left+"{"+word;
                
                front->insert(temp, i);
            }
            
        }
    }
    
    int f(string prefix, string suffix) {
        string temp = suffix + "{" + prefix;
        
        return front->search(temp);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */