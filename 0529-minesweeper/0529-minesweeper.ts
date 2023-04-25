let dx: number[] = [0, 1, 1, 1, 0, -1, -1, -1];
let dy: number[] = [1, 1, 0, -1, -1, -1, 0, 1];

function isValid(x:number, y:number, board: string[][]): boolean {
    return x>=0 && y>=0 && x<board.length && y<board[0].length;
}

function returnMines(x:number, y:number, grid:string[][]){
    let c=0;
    for(let k=0;k<8;k++){
        let new_x = x+dx[k];
        let new_y = y+dy[k];
        if(isValid(new_x, new_y, grid) && grid[new_x][new_y]=="M"){
            c+=1;
        }
    }
    return c;
}



function dfs(x: number, y: number, board: string[][]){
    if(board[x][y] == "M"){
        board[x][y] == "X";
        return;
    }
    else if(board[x][y] == "E"){
        let m = returnMines(x, y, board)
        if(m!=0){
            board[x][y] = m.toString();
        } else {
            board[x][y] = "B";
            
            for(let k=0;k<8;k++){
                let new_x = x + dx[k];
                let new_y = y+dy[k];
                
                if(isValid(new_x, new_y, board) && board[new_x][new_y]!="B"){
                    dfs(new_x, new_y, board);
                }
            }
        }
    }
    
    
}


function updateBoard(board: string[][], click: number[]): string[][] {
    let x = click[0], y = click[1];
    if(board[x][y]=="M") {
        board[x][y] = "X";
        return board;
    }
    
    dfs(x, y, board);
    return board;
};