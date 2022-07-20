struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    int count; // numbers of the same word in the dict
    TrieNode() { isEnd = false; count = 0;}
};

class Trie {
    public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(string s) {
        TrieNode* it = root;
        for(char c : s) {
            if(it->children.count(c) == 0)
                it->children[c] = new TrieNode();
            it = it->children[c];
        }
        it->isEnd = true;
        it->count++; // in case we have repeated words
    }
   
};

class Solution {
    int ans = 0;
    int findIndex(const string &s, int start, char c) {
        for(int i = start; i < s.size(); i++)
            if(s[i] == c) return i;
        return -1;
    }
    
    // DFS on the Trie
    void dfs(const string& s, TrieNode* node, int start) {
        for(auto p : node->children) {
            int idx = findIndex(s, start, p.first);
            if(idx != -1) {
                if(p.second->isEnd) ans+= p.second->count;
                dfs(s, p.second, idx + 1);
            }
                
        }
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie trie;
        for(string w : words)
            trie.insert(w);
        
        dfs(s, trie.root, 0);
        return ans;
    }
};