class Cell{
 public:
    int x, y, difference; 
    Cell(int x, int y, int difference) {
        this->x=x;
        this->y=y;
        this->difference=difference;
    }
};

struct Compare{
  public:
    bool operator()(const Cell& a, const Cell& b) {
        return a.difference > b.difference;
    }
};

class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool isValid(int r, int c, int m, int n) {
        return r>=0 && c>=0 && r<m && c<n;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n=heights[0].size();
        
        vector<vector<int>> diffMatrix(m, vector<int>(n, INT_MAX));
        
        priority_queue<Cell, vector<Cell>, Compare> pq;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        diffMatrix[0][0] = 0;
        
        pq.push(Cell(0, 0, diffMatrix[0][0]));
        
        
        while(!pq.empty()) {
            
            auto f = pq.top();
            pq.pop();
            
            visited[f.x][f.y] = true;
            
            if(f.x == m-1 && f.y == n-1) return f.difference;
            
            for(int i=0;i<4;i++) {
                int new_x = f.x + dx[i];
                int new_y = f.y + dy[i];
                
                if(isValid(new_x, new_y, m, n) && !visited[new_x][new_y]) {
                    
                    int curr_diff = abs(heights[new_x][new_y] - heights[f.x][f.y]);
                    
                    int max_diff = max(curr_diff, diffMatrix[f.x][f.y]);
                    
                    if(diffMatrix[new_x][new_y] > max_diff) {
                        diffMatrix[new_x][new_y] = max_diff;
                        pq.push(Cell(new_x, new_y, max_diff));
                    }
                    
                }
            }
            
        }
        
        return diffMatrix[m-1][n-1];
        
    }
};