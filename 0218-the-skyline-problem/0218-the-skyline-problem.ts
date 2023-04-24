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

class pair<T, U>{
    constructor(public first: T, public second:U){}
}

function getSkyline(buildings: number[][]): number[][] {
    let live = new PQ<number>((a, b) => (b-a));
    let dead = new PQ<number>((a, b) => (b-a));
    let temp = new Array<pair<number, number>>();
    let res: number[][] = [];
    
    for(let b of buildings){
        let x1 = b[0], x2 = b[1], ht = b[2];
        temp.push(new pair(x1, ht));
        temp.push(new pair(x2, -ht));
    }
    
    temp.sort((a: pair<number, number>, b:pair<number, number>) => (a.first == b.first) ? (b.second - a.second) : (a.first - b.first));
    
    
    let ongoingHeight = 0;
    
    for(let t of temp){
        if(t.second > 0) {
            live.enqueue(t.second);
        } else dead.enqueue(-t.second);
        
        while(!live.empty() && !dead.empty() && live.top() == dead.top()){
            live.dequeue();
            dead.dequeue();
        }
        
        ongoingHeight = live.empty() ? 0:live.top();
        
        if(res.length==0 || res[res.length-1][1] != ongoingHeight){
            res.push([t.first, ongoingHeight]);
        }
        
    }
    
    return res;
    
};