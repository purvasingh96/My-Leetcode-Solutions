class pair<T, U>{
    constructor(public first: T, public second: U){}
}
type Comparator<T> = (a: T, b: T) => number;

class PQ<T>{
    private items: T[] = [];
    private comp: Comparator<T>;

    constructor(comp: Comparator<T>){
        this.comp = comp;
    }
    
    size() : number{
        return this.items.length;
    }
    
    top(): T | undefined{
        if(this.size()==0) return undefined;
        return this.items[0];
    }
    
    parent(i: number): number{
        return Math.floor((i-1)/2);
    }
    
    left(i: number): number {
        return 2*i+1;
    }

    right(i: number): number{
        return 2*i+2;
    }

    hasLeft(i: number): boolean {
        return this.left(i) < this.size();
    }

    hasRight(i: number): boolean {
        return this.right(i) < this.size();
    }

    enqueue(val: T){
        this.items.push(val);
        this.heapUp(this.size()-1);
    }

    dequeue() : T|undefined {
        if(this.size()==0) return undefined;
        let root = this.items[0];
        let last = this.items.pop();
        if(this.size()>0){
            this.items[0] = last;
            this.heapDown(0);
        }
        return root;
    }

    heapUp(i: number) {
        while(i>0){
            let p = this.parent(i);
            if(this.comp(this.items[i], this.items[p]) < 0){
                [this.items[i], this.items[p]] = [this.items[p], this.items[i]];
                i = p;
            } else break;
        }
    }

    heapDown(i: number){
        while(true){
            let l = this.left(i);
            let r = this.right(i);
            let minIndex = i;
            
            if(this.hasLeft(i) && this.comp(this.items[l], this.items[minIndex]) < 0){
                minIndex = l;
            }
            
            if(this.hasRight(i) && this.comp(this.items[r], this.items[minIndex]) < 0){
                minIndex = r;
            }
            
            if(minIndex==i) break;
            else {
                [this.items[i], this.items[minIndex]] = [this.items[minIndex], this.items[i]];
                i = minIndex;
            }
            
        }
    }
    
}



function leastInterval(tasks: string[], n: number): number {
    
    let live = new PQ<number>((a, b) => b-a);
    let dead = new Array<pair<number, number>>();
    
    let m = new Map<string, number>();
    
    for(let task of tasks){
        m.set(task, (m.get(task)??0)+1);
    }
    
    for(let [k,v] of m.entries()){
        live.enqueue(v);
    }
    
    let t=1;
    
    while(true){
        if(dead.length!=0 && dead[0].second==t) {
            live.enqueue(dead[0].first);
            dead.shift();
        }
        
        if(live.size()!=0){
            let count = live.top();
            live.dequeue();
            if(count-1 > 0) dead.push(new pair(count-1, t+n+1));
        }
        
        if(live.size()==0 && dead.length==0) return t;
        
        t+=1;
    }
    
    return t;
};