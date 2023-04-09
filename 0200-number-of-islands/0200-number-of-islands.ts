const dx: number[] = [0, 1, 0, -1];
const dy: number[] = [1, 0, -1, 0];

function isValid(x: number, y:number, grid:string[][]): boolean{
    return x>=0 && y>=0 && x<grid.length && y<grid[0].length;
}

class queue<T>{
private items: T[] = [];

 pop() : T | undefined {
    return this.items.shift();
}

 push(val: T) : void {
    this.items.push(val);
}

 front(): T {
    return this.items[0];
}

 isEmpty() : boolean {
    return this.items.length == 0;
}

 size(): number {
    return this.items.length;
}

}


class pair<T, U> {
  constructor(public first: T, public second: U) {}
}

function bfs(i:number, j:number, grid:string[][]): void{
    let q = new queue<pair<number, number>>(); 
    let p = new pair<number, number>(i,j);
    q.push(p);
    
    while(!q.isEmpty()){
        let f = q.front();q.pop();
        let x:number = f.first;
        let y:number = f.second;
        
        for(let k=0;k<4;k++){
            let new_x=x+dx[k];
            let new_y = y + dy[k];
            if(isValid(new_x, new_y, grid) && grid[new_x][new_y]=="1"){
                grid[new_x][new_y]="0";
                let p_new = new pair<number, number>(new_x, new_y);
                q.push(p_new);
            }
        }
    }

}

function numIslands(grid: string[][]): number {
    let m:number = grid.length;
    let n:number = grid[0].length;
    let ans: number = 0;
    
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            if(grid[i][j]=="1"){
                ans+=1;
                bfs(i, j, grid);
            }
        }
    }
    
    
    
    return ans;
    
    
    
    
    
};