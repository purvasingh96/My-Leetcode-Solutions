class TrieNode{
public:
    vector<TrieNode*> children;
    int end;
    TrieNode(){
        children.resize(26, NULL);
        end=0;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string s) {
        TrieNode *cur = root;
        for (char ch : s) {
            if (!cur->children[ch - 'a']) cur->children[ch - 'a'] = new TrieNode();
            cur = cur->children[ch - 'a'];
        }
        (cur->end)++;
    }

    
    int dfs(TrieNode *root, string &s, int idx, vector<int>pos[]) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                int newIdx = upper_bound(pos[i].begin(), pos[i].end(), idx) - pos[i].begin();
                if (newIdx == pos[i].size()) continue;
                res += dfs(root->children[i], s, pos[i][newIdx], pos);
            }
        }
        return res + root->end;
    }
        
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie* trie = new Trie();
        for(auto word:words){
            trie->insert(word);
        }
        
        vector<int> pos[26];
        
        for(int i=0;i<s.length();i++){
            pos[s[i]-'a'].push_back(i);
        }
        
        return trie->dfs(trie->root, s, -1, pos);
    }
};