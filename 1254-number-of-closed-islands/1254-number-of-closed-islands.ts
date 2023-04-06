const dx: number[] = [0, 1, 0, -1];
const dy: number[] = [1, 0, -1, 0];


function isValid(x: number, y:number, grid:number[][]) : boolean{
    return x>=0 && y>=0 && x<grid.length && y<grid[0].length;
}

function defineFixedArray(row: number, col:number){
    let arr = [];
    for(let i=0;i<row;i++){
        arr.push(new Array<boolean>(col));
    }
    
    for(let i=0;i<row;i++){
        for(let j=0;j<col;j++){
            arr[i][j]=false;
        }
    }
    
    return arr;
}

function dfs(x: number, y:number, grid:number[][], visited:boolean[][]){
    visited[x][y]=true;
    grid[x][y]=1;
    
    for(let i=0;i<4;i++){
        let new_x: number = x+dx[i];
        let new_y: number = y+dy[i];
        
        if(isValid(new_x, new_y, grid) && !visited[new_x][new_y]
          && grid[new_x][new_y]==0){
            dfs(new_x, new_y, grid, visited);
        }
    }
}

function closedIsland(grid: number[][]): number {

    const m: number = grid.length;
    const n: number = grid[0].length;
    
    let visited = defineFixedArray(m, n);
    
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            visited[i][j]=false;
        }
    }
    
    
    for(let i=0;i<m;i++){
        if(grid[i][0]==0) dfs(i, 0, grid, visited);
        if(grid[i][n-1]==0) dfs(i, n-1, grid, visited);
    }
    
    for(let j=0;j<n;j++){
        if(grid[0][j]==0) dfs(0, j, grid, visited);
        if(grid[m-1][j]==0) dfs(m-1, j, grid, visited);
    }
    
    let ans=0;
    for(let i=1;i<m-1;i++){
        for(let j=1;j<n-1;j++){
            if(grid[i][j]==0){
                ans+=1;
                dfs(i, j, grid, visited);
            }
        }
    }
    
    return ans;
};