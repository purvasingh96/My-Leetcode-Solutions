let dx : number[] = [0, 1, 0, -1];
let dy : number[] = [1, 0, -1, 0];

function isValid(x: number, y: number, grid:string[][]){
    return x>=0 && y>=0 && x<grid.length && y<grid[0].length;
}

function dfs(idx: number, x: number, y: number, board: string[][], word: string) : boolean {
    if(idx >= word.length) return true;
    
    let ans: boolean =false;
    for(let k=0;k<4;k++){
        let new_x = x + dx[k];
        let new_y = y + dy[k];
        
        if(isValid(new_x, new_y, board) && board[new_x][new_y]!="#" && board[new_x][new_y] == word[idx]){
            let temp = board[new_x][new_y]; 
            board[new_x][new_y] = "#";
            ans = ans || dfs(idx+1, new_x, new_y, board, word);
            board[new_x][new_y] = temp;
        }
    }
    
    return ans;
}

function exist(board: string[][], word: string): boolean {
    for(let i=0;i<board.length;i++){
        for(let j=0;j<board[0].length;j++){
            if(board[i][j] == word[0]){
                let temp = board[i][j];
                board[i][j] = "#";
                if(dfs(1, i, j, board, word)) return true;
                board[i][j]=temp;
            }
        }
    }
    
    return false;
};