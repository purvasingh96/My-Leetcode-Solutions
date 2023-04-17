/**
 Do not return anything, modify board in-place instead.
 */
function boxId(i: number, j:number){
    let z:number = Math.floor(i/3);
    return z*3 + Math.floor(j/3);
}

function isValid(x: number, y:number, val:string, boxes:string[][], grid: string[][]): boolean {
    // row valid
    for(let i=0;i<grid.length;i++){
        if(grid[i][y] == val) return false;
    }
    
    // col valid
    for(let j=0;j<grid[0].length;j++){
        if(grid[x][j]==val) return false;
    }
    
    // box valid
    let id: number = boxId(x, y);
    if(boxes[id].find((z)=>z==val) != undefined) return false;
    return true;
}


function dfs(k: number, total: number, boxes: string[][], grid: string[][], coords:number[][]) : boolean{
    if(k>=coords.length) return true;
    
    let x = coords[k][0];
    let y = coords[k][1];
    
    for(let i=1;i<=9;i++){
        let target: string = i.toString();
        
        if(isValid(x, y, target, boxes, grid)){
            grid[x][y]  =target;
            total-=1;
            let id: number = boxId(x, y);
            boxes[id].push(target);
            
            if(dfs(k+1, total, boxes, grid, coords)) return true;
            
            boxes[id].pop();
            total+=1;
            grid[x][y]="."
             
        }
    }
    
    return false;
    
}

function solveSudoku(board: string[][]): void {
    let boxes: string[][] = [];
    let total: number=0;
    let coords: number[][] = [];


    for(let i=0;i<9;i++) boxes.push(new Array<string>());

    for(let i=0;i<board.length;i++){
        for(let j=0;j<board[0].length;j++){
            if(board[i][j] == "."){
                total+=1;
                let c = new Array<number>();
                c.push(i);
                c.push(j);
                coords.push(c);
            } else {
                
                boxes[boxId(i, j)].push(board[i][j]);
            }
        }
    }

    dfs(0, total, boxes, board, coords);
    


};