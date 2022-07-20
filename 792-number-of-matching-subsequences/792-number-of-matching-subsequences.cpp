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

    
    int dfs(int last_idx, TrieNode* node, string& s, vector<int> pos[]){
        
        int res=0;
        for(int i=0;i<26;i++){
            if(node->children[i]){
                int new_idx = upper_bound(pos[i].begin(), pos[i].end(), last_idx) - pos[i].begin();
                if(new_idx == pos[i].size()) continue;
                res += dfs(pos[i][new_idx], node->children[i], s, pos);
            }
        }
        return res + node->end;
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
        
        return trie->dfs(-1, trie->root, s, pos);
    }
};