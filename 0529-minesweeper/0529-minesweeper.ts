let dx: number[] = [0, 1, 1, 1, 0, -1, -1, -1];
let dy: number[] = [1, 1, 0, -1, -1, -1, 0, 1];

function isValid(x:number, y:number, board: string[][]): boolean {
    return x>=0 && y>=0 && x<board.length && y<board[0].length;
}

function returnMines(x:number, y:number, board:string[][]): string {
    let mines:number = 0;
    for(let i=0;i<8;i++){
        let newX: number = x+dx[i];
        let newY: number = y+dy[i];
        if(isValid(newX, newY, board) && board[newX][newY]=='M'){
            mines+=1;
        }
    }
    
    //console.log()
    return mines.toString();
}

function dfs(x:number, y:number, board: string[][], visited: boolean[][]){
    if(board[x][y]=='E'){
        let mines:string = returnMines(x, y, board);
        if(returnMines(x, y, board)=="0"){
            board[x][y]='B';
            for(let i=0;i<8;i++){
                let newX: number = x+dx[i];
                let newY: number = y+dy[i];
                
                if(isValid(newX, newY, board) && !visited[newX][newY] && board[newX][newY]=='E'){
                    visited[newX][newY]=true;
                    dfs(newX, newY, board, visited);
                }
            }
        } else {
            board[x][y]=mines;
        }
    }
}


function updateBoard(board: string[][], click: number[]): string[][] {
    let visited=[]
    const m: number = board.length;
    const n: number = board[0].length;
    
    for(let i=0;i<m;i++){
        visited.push(new Array<boolean>(n));
    }
    
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            visited[i][j]=false;
        }
    }
    
    const x:number = click[0];
    const y: number = click[1];
    
    visited[x][y]=true;
    
    if(board[x][y]=='M'){
        board[x][y]='X';
        return board;
    }
    
    dfs(x, y, board, visited);
    //visited.clear();
    
    return board;
    
    
};