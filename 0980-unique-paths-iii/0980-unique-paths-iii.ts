const dx: number[] = [0, 1, 0, -1];
const dy: number[] = [1, 0, -1, 0];
let answer=0;

function isValid(x:number, y:number, grid:number[][]): boolean{
    return x>=0 && y>=0 && x<grid.length && y<grid[0].length;
}

function backtrack(x:number, y:number, tx:number, ty:number, target: number, grid: number[][], ans: number){
    if(x==tx && y==ty){
        if(target==-1) answer+=1;
        return;
    }
    
    for(let i=0;i<4;i++){
        let new_x = x+dx[i];
        let new_y = y+dy[i];
        
        if(isValid(new_x, new_y, grid) &&  grid[new_x][new_y]!=-1){
            let t: number = grid[new_x][new_y];
            grid[new_x][new_y]=-1;
            target-=1;
            backtrack(new_x, new_y, tx, ty, target, grid, ans);
            target+=1;
            grid[new_x][new_y]=t;
        }
    }
}


function uniquePathsIII(grid: number[][]): number {
    let target: number=0;
    let sx, sy, tx, ty;
    let visited=[];
    let m = grid.length, n = grid[0].length;
    for(let i=0;i<m;i++){
        visited.push(new Array<boolean>(n));
    }
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            
            visited[i][j]=false;
            
            if(grid[i][j]==0) target+=1;
            else if(grid[i][j]==1) {
                sx=i;
                sy=j;
                grid[i][j]=-1;
            } else if(grid[i][j]==2){
                tx=i;
                ty=j;
            }
        }
    }
    
    let ans: number=0;
    backtrack(sx, sy, tx, ty, target, grid, ans);
    let tk = answer;
    answer=0;
    return tk;
};