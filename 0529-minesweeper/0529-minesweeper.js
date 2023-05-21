/**
 * @param {character[][]} board
 * @param {number[]} click
 * @return {character[][]}
 */


let dx= [0, 1, 1, 1, 0, -1, -1, -1];
let dy = [1, 1, 0, -1, -1, -1, 0, 1];

function isValid(x, y, board) {
    return x>=0 && y>=0 && x<board.length && y<board[0].length;
}

function returnMines(x, y, grid){
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


var dfs = function(x, y, board){
    if(board[x][y] == 'M') {
        board[x][y] = 'X';
        return;
    }
    
    if(board[x][y] == 'E'){
        m = returnMines(x, y, board);
        if(m ==0){
            board[x][y] = 'B';
            for(let k=0;k<8;k++){
                new_x = x + dx[k];
                new_y = y +dy[k];
                if(isValid(new_x, new_y, board) && board[new_x][new_y]=='E'){
                    dfs(new_x, new_y, board);
                }
            }
        }
         else {
                board[x][y] = m.toString();
            }
    }
}

var updateBoard = function(board, click) {
    dfs(click[0], click[1], board);
    return board;
};