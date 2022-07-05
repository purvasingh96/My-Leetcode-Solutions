class Solution {
private:
    map<int, int> rank;
    map<int, int> root;
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        
        // O(N)
        for(auto x:nums) {
            rank[x] = 1;
            root[x] = x;
        }
        // O(N) as union find takes O(alpha(N)) 
        for(auto x:nums) {
            if(rank.find(x+1)!=rank.end()) {
                union1(x, x+1);
            }
            
            if(rank.find(x-1)!=rank.end()) {
                union1(x, x-1);
            }
        }
        
        int max_length = 0;
        for(auto x:rank) {
            max_length = max(max_length, x.second);
        }
        
        return max_length;
        
    }
    
    int find(int x) {
        if(root[x] == x) return x;
        
        return root[x] = find(root[x]);
    }
    
    void union1(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        
        if(rx!=ry) {
            
            if(rank[rx] >= rank[ry]) {
                root[ry] = rx;
                rank[rx] += rank[ry];
            } else {
                root[rx] = ry;
                rank[ry] += rank[rx];
            }
        }
    }
};