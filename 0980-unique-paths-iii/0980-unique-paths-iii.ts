const dx: number[] = [0, 1, 0, -1];
const dy: number[] = [1, 0, -1, 0];

function isValid(x:number, y:number, grid:number[][]): boolean{
    return x>=0 && y>=0 && x<grid.length && y<grid[0].length;
}

function dfs(x: number, y: number, tx: number, ty: number, grid:number[][], squares:number, target:number) : number {
    if(x==tx && y==ty && squares == target+1) return 1;
    
    let ans=0;
    for(let k=0;k<4;k++){
        let new_x = x + dx[k];
        let new_y = y + dy[k];
        
        if(isValid(new_x, new_y, grid) && grid[new_x][new_y]!=-1){
            let temp = grid[new_x][new_y]; 
            grid[new_x][new_y] = -1;
            squares+=1;
            ans += dfs(new_x, new_y, tx, ty, grid, squares, target);
            squares-=1;
            grid[new_x][new_y] = temp;   
        }  
    }
    return ans;
}

function uniquePathsIII(grid: number[][]): number {
    let target=0, squares=0;
    let sx, sy, tx, ty;
    
    for(let i=0;i<grid.length;i++){
        for(let j=0;j<grid[0].length;j++){
            if(grid[i][j] == 1){
                [sx, sy] = [i, j];
            } else if(grid[i][j] == 2){
                [tx, ty] = [i, j];
            } else if(grid[i][j] == 0){
                target+=1;
            }
        }
    }
    
    grid[sx][sy]=-1;
    return dfs(sx, sy, tx, ty, grid, squares, target);
    
};