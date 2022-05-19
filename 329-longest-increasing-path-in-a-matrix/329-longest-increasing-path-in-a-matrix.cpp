class Solution {
private:
    int xd[4] = {0, 1, 0, -1};
    int yd[4] = {1, 0, -1, 0};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        int longest = 0;
        queue<pair<int, int>> q;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                int x = i;
                int y = j;
                
                for(int k=0;k<4;k++) {
                    
                    int new_x = x + xd[k];
                    int new_y = y + yd[k];
                    // find coords that are surrounded by only larger elements
                    if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && matrix[new_x][new_y] < matrix[x][y]) {
                        indegree[x][y] += 1;
                    }
                    
                }
                
                if(indegree[x][y] == 0) {
                    q.push({x, y});
                }
                
            }
        }
        
        while(!q.empty()) {
            
            int size=q.size();
            
            while(size--) {
                
                auto f = q.front();
                q.pop();
                
                int x = f.first;
                int y = f.second;
                
                for(int i=0;i<4;i++) {
                    
                    int new_x = x + xd[i];
                    int new_y = y + yd[i];
                    
                    if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && matrix[new_x][new_y] > matrix[x][y] 
                      && --indegree[new_x][new_y] == 0) {
                        q.push({new_x, new_y});
                    }
                
                    
                } 
                
            }
            longest+=1;
            
        }
        
        return longest;
        
    }
};