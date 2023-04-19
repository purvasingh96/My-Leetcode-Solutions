type Comparator<T> = (a: T, b:T) => number;

class PQ<T>{
    private pq: T[] = [];
    private comp: Comparator<T>;
    constructor(comp: Comparator<T>){
        this.comp = comp;
    }

    empty(): boolean {
        return this.size()==0;
    }

    left(i: number){
        return 2*i+1;
    }
    
    right(i: number){
        return 2*i+2;
    }

    parent(i: number){
        return Math.floor((i-1)/2);
    }

    size(): number{
        return this.pq.length;
    }
    
    hasLeft(i) : boolean {
        return this.left(i) < this.size();
    }

    hasRight(i) : boolean {
        return this.right(i) < this.size();
    }

    top() : T| undefined{
        if(this.size()==0) return undefined;
        return this.pq[0];
    }

    dequeue() : T | undefined {
        if(this.size()==0) return undefined;
        
        let root = this.pq[0];
        let last = this.pq.pop();
        if(this.size()>0){
            this.pq[0] = last;
            this.heapDown(0);
        }
        
        return root;
    }

    enqueue(val: T) : void {
        this.pq.push(val);
        this.heapUp(this.size()-1);
    }
    
    heapDown(i: number) {
        while(true){
            let l = this.left(i);
            let r = this.right(i);
            let minIndex = i;
            if(this.hasLeft(i) && this.comp(this.pq[l], this.pq[minIndex]) < 0){
                minIndex = l;
            }

            if(this.hasRight(i) && this.comp(this.pq[r], this.pq[minIndex]) < 0){
                minIndex = r;
            } 
            
            if(minIndex == i) break;
            else {
                [this.pq[i], this.pq[minIndex]] = [this.pq[minIndex], this.pq[i]];
                i = minIndex;
            }
        }
    }

    heapUp(i: number) {
        while(i>0){
            let p = this.parent(i);
            if(this.comp(this.pq[i], this.pq[p]) < 0){
                [this.pq[i], this.pq[p]] = [this.pq[p], this.pq[i]];
                i = p;
            } else break;
        }
    }
}

class Pair<T, U>{
    constructor(public first: T, public second:U){}
}


function getSkyline(buildings: number[][]): number[][] {
    let live = new PQ<number>((a, b) => (b-a));
    let dead = new PQ<number>((a, b) =>(b-a));
    let res: number[][] = [];
    let temp = new Array<Pair<number, number>>();
    
    
    for(let b of buildings){
        let ps = new Pair(b[0], b[2]);
        let pe = new Pair(b[1], -b[2]);
        temp.push(ps);
        temp.push(pe);
    }
    
    temp.sort((a: Pair<number, number>, b: Pair<number, number>) => (a.first == b.first) ? (b.second-a.second) : (a.first - b.first));
    
    for(let x of temp){
        if(x.second > 0){
            live.enqueue(x.second);
        } else {
            dead.enqueue(-x.second);
        }
        
        while(!live.empty() && !dead.empty() && live.top() == dead.top()){
            live.dequeue();
            dead.dequeue();
        }
        
        let maxHeight = live.size()==0 ? 0: live.top();
        
        
        if(res.length==0 || res[res.length-1][1] != maxHeight){
            res.push([x.first, maxHeight]);
        }
        
    }
    
    return res;
    
    
    
};