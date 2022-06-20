class TrieNode{
public:
    vector<TrieNode*> children;
    string word;
    int len;
    bool iseow;
    
    TrieNode(){
        children.resize(26, NULL);
        word="";
        len=0;
        iseow=false;
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
        int cur_word_len=s.length();
        
        bool isSmall=false;
        
        for(int i=0;i<s.length();i++){
            
            if(node->children[s[i]-'a']==NULL){
                node->children[s[i]-'a'] = new TrieNode();
            }
            
            node = node->children[s[i]-'a'];
            
        }
        
        bool isSubstring=false;
        
        for(int i=0;i<26;i++){
            if(node->children[i]!=NULL){
                isSubstring = true;
                break;
            }
        }
        
        if(!isSubstring){
            node->word=s;
            node->iseow=true;
        }
        
    }
    
    void getEOW(TrieNode* node, int& res){
        
        if(node->iseow){
            res += (node->word.length()+1);
            return;
        }
        
        for(int i=0;i<26;i++){
            if(node->children[i]!=NULL){
                getEOW(node->children[i], res);
            }
        }
        
        
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
           return a.length() > b.length(); 
        });
        
        Trie* trie = new Trie();
        TrieNode* node = trie->root;
        
        
        for(auto word:words){
            reverse(word.begin(), word.end());
            trie->insert(word);
        }
        
        int res=0;
        trie->getEOW(node, res);
        return res;
    }
};