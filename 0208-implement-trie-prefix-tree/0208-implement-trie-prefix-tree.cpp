class TrieNode{
 public:
    vector<TrieNode*> dict;
    bool end;
    TrieNode(){
        dict.resize(26, NULL);
        end=false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(node->dict[s[i]-'a']==NULL){
                node->dict[s[i]-'a'] = new TrieNode();
            }
            node = node->dict[s[i]-'a'];
        }
        node->end=true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(node->dict[word[i]-'a'] == NULL) return false;
            node = node->dict[word[i]-'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node= root;
        for(int i=0;i<prefix.length();i++){
            if(node->dict[prefix[i]-'a']==NULL) return false;
            node = node->dict[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */