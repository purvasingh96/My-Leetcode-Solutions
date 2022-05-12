class Solution {
private:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>> q;
        int longest=0;
        
        vector<vector<int>> indegree(m, vector<int>(n));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                for(auto d:directions) {
                    int x = i+d[0];
                    int y = j+d[1];
                    
                    if(x>=0 && y>=0 && x<m && y<n && matrix[i][j] > matrix[x][y]) {
                        indegree[i][j] += 1;
                    }
                }
                
                if(indegree[i][j] == 0) q.push({i,j});
                
            }
        }
        
        // BFS
        while(!q.empty()){
            
            int size = q.size();
            
            while(size--) {
                
                auto f = q.front();
                q.pop();
                
                int x = f.first;
                int y = f.second;
                
                for(auto d:directions){
                    
                    int new_x = x+d[0];
                    int new_y = y+d[1];
                    
                    if(new_x>=0 && new_y>=0 && new_x<m && new_y<n 
                       && matrix[new_x][new_y] > matrix[x][y] && --indegree[new_x][new_y]==0){
                        
                        q.push({new_x, new_y});
                    }
                    
                }
                
            }
            
            longest += 1;
            
        }
        
        return longest;
        
    }
};