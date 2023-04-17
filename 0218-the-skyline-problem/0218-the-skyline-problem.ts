type Comparator<T> = (a:T, b:T) => number;

class PQ<T> {
    private pq: T[] = [];
    private comp: Comparator<T>;
    constructor(comp: Comparator<T>) {
        this.comp = comp;
    }
    
    hasLeft(i:number) : boolean{
        return this.left(i) < this.size();
    }

    hasRight(i: number): boolean{
        return this.right(i) < this.size();
    }
    
    top(): T | undefined {
        return this.pq[0];
    }
    

    left(i: number) : number {
        return 2*i+1;
    }
    
    right(i: number): number {
        return 2*i+2;
    }
    
    parent(i: number) : number {
        return Math.floor((i-1)/2);
    }

    size(): number {
        return this.pq.length;
    }
    
    empty(): boolean {
        return this.size()==0;
    }

    enqueue(val: T) : void {
        this.pq.push(val);
        this.heapUp(this.size()-1);
    }

    dequeue() : T | undefined {
        if(this.size()==0) return undefined;
        let root = this.pq[0];
        let last = this.pq.pop();
        if(this.size() > 0){
            this.pq[0] = last;
            this.heapDown(0);
        }
        return root;
    }

    heapUp(i: number): void {
        while(i>0){
            let p = this.parent(i);
            if(this.comp(this.pq[i], this.pq[p]) < 0){
                [this.pq[i], this.pq[p]] = [this.pq[p], this.pq[i]];
                i =p;
            } else break;
        }
    }

    heapDown(i: number) : void {
        
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
            
            if(minIndex!=i){
                [this.pq[i], this.pq[minIndex]] = [this.pq[minIndex], this.pq[i]];
                i = minIndex;
            } else break;
            
        }
        
    }
}
class Pair<T, U>{
public constructor(public first:T, public second:U){};
}



function getSkyline(buildings: number[][]): number[][] {
    let live = new PQ<number>((a, b) => (b-a));
    let dead  = new PQ<number>((a, b) => (b-a));
    
    let res = new Array<Pair<number,number>>();
    for(let b of buildings){
        let start = new Pair(b[0], b[2]);
        let end = new Pair(b[1], -b[2]);
        res.push(start);
        res.push(end);
    }
    
    res.sort((a:Pair<number, number>, b:Pair<number, number>) => a.first==b.first?b.second -a.second:a.first-b.first);
    
    let ans: number[][]=[];
    
    // for(let x of res){
    //     console.log(x.first, ", ", x.second);
    // }
    
    //let maxHeight: number=0;
    for(let r of res){
        let pos = r.first;
        let ht = r.second;
        
        if(ht > 0){
            live.enqueue(ht);
        } else {
            dead.enqueue(-ht);
        }
        
        // if(live.size()>0) console.log("live top: ", live.top());
        // if(dead.size()>0) console.log("dead top: ", dead.top());
        
        while(live.size()!=0 && dead.size()!=0 && live.top() == dead.top()){
            live.dequeue();
            dead.dequeue();
        }
        
        let maxHeight: number = live.size()==0?0:live.top();
        
        if(ans.length == 0 || ans[ans.length-1][1]!=maxHeight){
            let pNew = new Array<number>();
            pNew.push(pos);
            pNew.push(maxHeight);
            ans.push(pNew);
        } 
        
        
    }
    
    return ans;
    
    
    
    
    
    
    
    
};