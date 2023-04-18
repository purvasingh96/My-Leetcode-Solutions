const dx: number[] = [0, 1, 0, -1];
const dy: number[] = [1, 0, -1, 0];

function isValid(x:number, y:number, grid:number[][]): boolean{
    return x>=0 && y>=0 && x<grid.length && y<grid[0].length;
}

function backtrack(x: number, y: number, tx: number, ty: number, grid:number[][], tnb: number, target: number, count:{val:number}) : void {
    
    if(x==tx && y==ty) {
        if(tnb==target+1) count.val+=1;
        return;
    }
    
    let ans = 0;
    for(let k=0;k<4;k++){
        let newX = x+dx[k];
        let newY = y+dy[k];
        
        if(isValid(newX,newY, grid) && grid[newX][newY]!=-1){
            let temp = grid[newX][newY]
            grid[newX][newY]=-1;
            tnb+=1;
            backtrack(newX, newY, tx, ty, grid, tnb, target, count);
            tnb-=1;
            grid[newX][newY]=temp;
        }
    }
 
}

function uniquePathsIII(grid: number[][]): number {
    let target=0;
    let tx=0, ty=0, sx=0, sy=0;
    
    let m = grid.length;
    let n = grid[0].length;
    
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            if(grid[i][j]==1){
                sx=i;
                sy=j;
                grid[i][j]=-1;
            } else if(grid[i][j]==0){
                target+=1;
            } else if(grid[i][j]==2) {
                tx=i;
                ty=j;
            }
        }
    }
    
    let tnb=0;
    let count = {val:0};
    backtrack(sx, sy, tx, ty, grid, tnb, target, count);
    return count.val;
    
};