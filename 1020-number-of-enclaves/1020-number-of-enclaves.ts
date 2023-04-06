const dx:number[] = [0, 1, 0, -1];
const dy:number[] = [1, 0, -1, 0];

function isValid(x: number, y:number, grid:number[][]): boolean{
    return x>=0 && y>=0 && x<grid.length && y<grid[0].length;
}

function dfs(x:number, y:number, grid:number[][], visited:boolean[][]){
    grid[x][y]=0;
    visited[x][y]=true;
    
    for(let k=0;k<4;k++){
        let new_x: number = x+dx[k];
        let new_y: number = y+dy[k];
        
        if(isValid(new_x, new_y, grid) && grid[new_x][new_y]==1 && !visited[new_x][new_y]){
            dfs(new_x, new_y, grid, visited);
        }
    }
}

function numEnclaves(grid: number[][]): number {
    let m: number = grid.length;
    let n: number = grid[0].length;
    
    let visited=[];
    
    for(let i=0;i<m;i++){
        visited.push(new Array<boolean>(n));
    }
    
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            visited[i][j]=false;
        }
    }
    
    for(let i=0;i<m;i++){
        if(grid[i][0]==1) dfs(i, 0, grid, visited);
        if(grid[i][n-1]==1) dfs(i, n-1, grid, visited);
    }
    
    for(let j=0;j<n;j++){
        if(grid[0][j]==1) dfs(0, j, grid, visited);
        if(grid[m-1][j]==1) dfs(m-1, j, grid, visited);
    }
    
    let ans: number=0;
    for(let i=1;i<m-1;i++){
        for(let j=1;j<n-1;j++){
            if(grid[i][j]==1) ans+=1;
        }
    }
    return ans;
};