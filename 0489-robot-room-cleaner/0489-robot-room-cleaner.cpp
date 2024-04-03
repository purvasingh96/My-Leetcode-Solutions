/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(int row, int col, int d, Robot& robot, unordered_set<string>& visited){
        for(int k=0;k<4;k++){
            int j = (k+d)%4;
            
            int new_x = row + dir[j][0];
            int new_y = col + dir[j][1];
            
            string pos = to_string(new_x) + "#"+to_string(new_y);
            if(visited.count(pos)==0 && robot.move()){
                visited.insert(pos);
                robot.clean();
                dfs(new_x, new_y, j, robot, visited);
                backtrack(robot);
            }
            robot.turnRight();
            
        }
        
    }
    
    void backtrack(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        visited.insert("0#0");
        robot.clean();
        dfs(0, 0, 0, robot, visited);
    }
};