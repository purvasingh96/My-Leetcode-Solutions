function boxId(x:number, y:number): number{
    let z:number = x/3;
    z = Math.floor(z);
    return (z*3 + Math.floor(y/3));
}

function isValid(x:number, y:number, grid:string[][], boxes:string[][]){
    let m: number = grid.length;
    let n: number = grid[0].length;
    
    for(let i=0;i<m;i++){
        if(grid[i][y]==grid[x][y] && i!=x) return false;
    }
    
    for(let j=0;j<m;j++){
        if(grid[x][j]==grid[x][y] && j!=y) return false;
    }
    
    let id: number = boxId(x, y);
    
    if(boxes[id].find(z => (z==grid[x][y])) != undefined) return false;
    boxes[id].push(grid[x][y]);
    return true;
}

function isValidSudoku(grid: string[][]): boolean {
    let m: number = grid.length;
    let n: number = grid[0].length;
    
    let boxes = [];
    for(let i=0;i<9;i++) boxes.push(new Array<string>());
    
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            if(grid[i][j]!="." && !isValid(i, j, grid, boxes)) return false;        
        }
    }
    
    return true;
    
};