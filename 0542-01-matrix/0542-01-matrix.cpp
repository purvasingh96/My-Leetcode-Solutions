class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int m = mat.size(), n =mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                { 
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        
        while(!q.empty()){
            
                auto f = q.front();
                q.pop();
                int x = f.first, y = f.second;
                
                for(int i=0;i<4;i++){
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    
                    if(isValid(new_x, new_y, mat) && dist[new_x][new_y]==-1){
                        q.push({new_x, new_y});
                        dist[new_x][new_y] = dist[x][y] + 1;
                    }
                    
                }
                
            
        }
        
        return dist;
    }
};