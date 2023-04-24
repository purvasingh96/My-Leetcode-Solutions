const dx: number[] = [0, 1, 0, -1];
const dy: number[] = [1, 0, -1, 0];

function isValid(x: number, y:number, grid:string[][]): boolean{
    return x>=0 && y>=0 && x<grid.length && y<grid[0].length;
}


function dfs(x: number, y: number, grid:string[][]){
    for(let k=0;k<4;k++){
        let new_x = x + dx[k];
        let new_y = y + dy[k];
        if(isValid(new_x, new_y, grid) && grid[new_x][new_y] == "1"){
            grid[new_x][new_y] = "0";
            dfs(new_x, new_y, grid);
        }
    }
}


function numIslands(grid: string[][]): number {
    let ans=0;
    
    for(let i=0;i<grid.length;i++){
        for(let j=0;j<grid[0].length;j++){
            if(grid[i][j] == "1"){
                ans+=1;
                dfs(i, j, grid);
            }
        }
    }
    
    return ans;
};