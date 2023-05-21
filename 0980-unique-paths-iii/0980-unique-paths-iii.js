/**
 * @param {number[][]} grid
 * @return {number}
 */
let dx = [0, 1, 0, -1];
let dy = [1, 0, -1, 0];

var isValid = function(x, y, grid){
        return x>=0 && y>=0 && x<grid.length && y<grid[0].length;
}


var dfs = function(grid, x, y, tx, ty, squares, target) {
    if(x==tx && y==ty && squares == target+1){
        return 1;
    }
    
    ans=0;
    let temp = grid[x][y];
    grid[x][y]=-1;
    
    for(let k=0;k<4;k++){
        let new_x = x + dx[k];
        let new_y = y + dy[k];
        if(isValid(new_x, new_y, grid) && grid[new_x][new_y]!=-1){
            ans += dfs(grid, new_x, new_y, tx, ty, squares+1, target);            
        }
    }
    grid[x][y] = temp;
    return ans;
    
}


var uniquePathsIII = function(grid) {
    // [] => x, y, total non empty square
    let q = [];
    let target=0;
    
    let sx, sy, tx, ty;
    
    for(let i=0;i<grid.length;i++){
        for(let j=0;j<grid[0].length;j++){
            if(grid[i][j] == 0) target+=1;
            else if(grid[i][j] == 1){
                sx=i;
                sy=j;
            } else if(grid[i][j] == 2){
                tx=i;
                ty=j;
            }
                
        }
    }

    grid[sx][sy]=-1;
    return dfs(grid, sx, sy, tx, ty, 0, target);
};