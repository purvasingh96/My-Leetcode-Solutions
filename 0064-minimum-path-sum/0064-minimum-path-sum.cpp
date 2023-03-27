class MyComp{
 public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[2] > b[2];
    }
};

class Solution {
private:
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};

    bool isValid(int x, int y, vector<vector<int>>& grid){
            return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        // general BFS
        // x, y, sum so far
        priority_queue<vector<int>, vector<vector<int>>, MyComp> q;
        
        int m = grid.size(), n= grid[0].size();
        q.push({0, 0, grid[0][0]});
        int mincost = INT_MAX;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        while(!q.empty()){
            int sz=q.size();
            
                auto f = q.top();
                q.pop();
                int x = f[0], y = f[1], cost=f[2];
                if(x==m-1 && y==n-1) return cost;
                
                for(int i=0;i<2;i++){
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];
                    if(isValid(new_x, new_y, grid) && cost+grid[new_x][new_y] < dist[new_x][new_y]){
                        dist[new_x][new_y] = cost+grid[new_x][new_y];
                        q.push({new_x, new_y, dist[new_x][new_y]});
                    }
                }  
            
            
            
        }
        
        return mincost;
        
    }
};