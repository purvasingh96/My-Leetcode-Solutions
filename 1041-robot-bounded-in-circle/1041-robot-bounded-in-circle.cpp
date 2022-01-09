class Solution {
public:
    bool isRobotBounded(string instructions) {
        /*
            TC: O(N)
            SC: O(1)
        
        */
        
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        
        int x=0, y=0;
        int north_idx = 0;
        
        for(char c:instructions) {
            
            if(c == 'L') {
                
                north_idx = (north_idx+3)%4;
                
            } else if(c == 'R') {
                
                north_idx = (north_idx + 1) % 4;
                
            } else {
                
                x += dx[north_idx];
                y += dy[north_idx];
                
            }
            
        }
        
        return (x == 0 && y ==0) || (north_idx!=0);
    }
};