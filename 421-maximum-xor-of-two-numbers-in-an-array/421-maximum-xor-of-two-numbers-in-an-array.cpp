class TrieNode {
public:
    TrieNode* child[2];
    
    TrieNode() {
        child[0] = NULL;
        child[1] = NULL;
    }
};


class Solution {
public:
    TrieNode* root;
    
    void insert(int n) {
        TrieNode* curr = root;
        bitset<32> bit_n(n);
        
        for(int i=31;i>=0;i--) {
            
            if(!curr->child[bit_n[i]]) curr->child[bit_n[i]] = new TrieNode();
            curr = curr->child[bit_n[i]];
            
        }
        
    }
    
    
    int maxXOR(int n) {
        
        TrieNode* curr = root;
        bitset<32> bit_n(n);
        int ans=0;
        
        for(int i=31;i>=0;i--) {
            
            if(curr->child[!bit_n[i]]) {
                ans += (1<<i);
                curr = curr->child[!bit_n[i]];
            } else {
                curr = curr->child[bit_n[i]];
            }
            
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        int ans = 0;
        
        for(auto n:nums) {
            insert(n);
        }
        
        
        for(auto n:nums) {
            ans = max(ans, maxXOR(n));
        }
        
        return ans;
        
        
        
        }
};