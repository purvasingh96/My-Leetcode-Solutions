class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        /*
        m: trust.size()
        TC: O(n) + O(m) => O(m)
        SC: O(m)
        */
        
        unordered_map<int, int> out_degree;
        unordered_map<int, int> in_degree;
        
        for(auto t:trust) {
            
            out_degree[t[0]] += 1;
            in_degree[t[1]] += 1;
            
        }
        
        for(int i=1;i<=n;i++) {
            if(out_degree[i] == 0 && in_degree[i]==n-1) return i;
        }
        
        return -1;
    }
};