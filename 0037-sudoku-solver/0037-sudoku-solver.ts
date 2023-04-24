/**
 Do not return anything, modify board in-place instead.
 */

function boxid(i: number, j:number){
    return Math.floor(i/3)*3 + Math.floor(j/3);
}

function isvalid(val: string, x:number, y:number, board:string[][], boxes: string[][]){
    for(let i=0;i<board.length;i++){
        if(board[i][y]==val) return false;
    }
    
    for(let j=0;j<board[0].length;j++){
        if(board[x][j] == val) return false;
    }
    
    let id = boxid(x, y);
    if(boxes[id].find(z => z==val)!=undefined) return false;
    
    return true;
}


function dfs(idx: number, boxes: string[][], board: string[][], states:number[][]) : boolean{
    if(idx >= states.length) return true;
    
    let x = states[idx][0], y = states[idx][1];
    let id = boxid(x, y);
    
    for(let i=1;i<=9;i++){
        let target = i.toString();
        if(isvalid(target, x, y, board, boxes)){
            board[x][y] = target;
            boxes[id].push(target);
            if(dfs(idx+1, boxes, board, states)) return true;
            boxes[id].pop();
            board[x][y]=".";
        }
    }
    
}

function solveSudoku(board: string[][]): void {

    
    
    let states: number[][] = [];
    let boxes: string[][] = Array.from(Array(9), ()=>new Array());

    
    for(let i=0;i<board.length;i++){
        for(let j=0;j<board[0].length;j++){
            if(board[i][j] == "."){
                let p = [i,j];
                states.push(p);
            } else {
                boxes[boxid(i, j)].push(board[i][j]);
            }
        }
    }
    
    
    
    
    dfs(0, boxes, board, states);
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};