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

function dfs(x: number, y:number, grid: string[][]){
    
    
    if(grid[x][y] == "E"){
        let mines = returnMines(x, y, grid);
        if(mines > 0){
            grid[x][y] = mines.toString();
        } else {
            grid[x][y] = "B";
            for(let i=0;i<8;i++){
                let new_x = x + dx[i];
                let new_y = y + dy[i];
                
                if(isValid(new_x, new_y, grid) && grid[new_x][new_y]!="B"){
                    dfs(new_x, new_y, grid);
                }
                
            }
        }
    }
    
    
}

function updateBoard(board: string[][], click: number[]): string[][] {
    let x = click[0], y = click[1];
    if(board[x][y] == "M") board[x][y]="X";
    else dfs(x, y, board);
    return board;
};