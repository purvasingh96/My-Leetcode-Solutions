class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> arr((m+n+1));
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                arr[(i+j)].push_back(mat[i][j]);
                
            }
        }
        
        bool flip = true;
        vector<int> res;
        
        for(int i=0;i<arr.size();i++) {
            if(flip) {
                reverse(arr[i].begin(), arr[i].end());
            }
            for(auto x:arr[i]) res.push_back(x);
            flip = !flip;
        }
        
        return res;
    }
    
    
};