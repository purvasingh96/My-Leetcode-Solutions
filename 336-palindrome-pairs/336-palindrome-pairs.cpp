struct TrieNode{
    TrieNode* children[26]={};
    int idx=-1;
    vector<int> palindromIndices;
};


class Solution {
private:
    TrieNode root;
    
    bool isPalindrome(string& s, int start, int end){
        while(start<end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void insert(string& s, int idx){
        TrieNode* node = &root;
        
        for(int j=s.length()-1;j>=0;j--){
            if(isPalindrome(s, 0, j)) node->palindromIndices.push_back(idx);
            int k = s[j]-'a';
            
            if(!node->children[k]) node->children[k] = new TrieNode();
            node = node->children[k];
        }
        node->idx=idx;
        node->palindromIndices.push_back(idx);
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>> res;
        
        for(int i=0;i<n;i++) insert(words[i], i);
        
        for(int i=0;i<n;i++){
            
            TrieNode* node = &root;
            string s = words[i];
            
            
            for(int j=0;j<s.length() && node;j++){
                
                // case w1.len > w2.len => check Rev(w1) + pal(remaining w1)
                if(node->idx!=-1 && node->idx!=i && isPalindrome(s, j, s.length()-1)){
                    res.push_back({i, node->idx});
                }
                node = node->children[s[j]-'a'];
                
            }
            
            // case 1
            if(!node) continue;
            
            for(auto j:node->palindromIndices){
                if(j!=i) res.push_back({i, j});
            }
            
        }
        
        return res;
        
    }
};