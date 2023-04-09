class MyComp{
 public:
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[2]!=b[2]) return a[2] > b[2];
        else if(a[1]!=b[1]) return a[1] < b[1];
        return a[0]<b[0];
    }
};
class Solution {
private:
    bool isValid(int x, int y, vector<vector<int>>& grid){
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
}
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // x, y, steps
        priority_queue<vector<int>, vector<vector<int>>, MyComp> q;
        
        q.push({0, 0, 1});
        dist[0][0]=1;
        
        while(!q.empty()){
            auto f = q.top();q.pop();
            int i = f[0], j=f[1], steps=f[2];
            
            if(i==m-1 && j==n-1) return steps;
            
            for(int k=j+1;k<=grid[i][j]+j && k<grid[0].size();k++){
                if(isValid(i, k, grid)){
                    if(steps+1 < dist[i][k]){
                        dist[i][k] = steps+1;
                        q.push({i, k, dist[i][k]});
                    }
                } 
            }
            
            for(int k=i+1;k<=grid[i][j]+i && k<grid.size();k++){
                if(isValid(k, j, grid)){
                    if(steps+1 < dist[k][j]){
                        dist[k][j]  =steps+1;
                        q.push({k, j, dist[k][j]});
                    }
                }
            }
            
        }
        
        return -1;
        
    }
};