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


class pair<T, U> {
    constructor(public first: T, public second:U){}
}

function maxSlidingWindow(nums: number[], k: number): number[] {
    //let pq = new PQ<pair<number, number>>((a: pair<number, number>, b:pair<number, number>) => (b.second - a.second));
    let pq = new PQ<pair<number, number>>((a: pair<number, number>, b:pair<number, number>) => (b.second - a.second));
    
    for(let i=0;i<k;i++){
        let p = new pair(i, nums[i]);
        pq.enqueue(p);
    }
    
    let res: number[] = [];
    res.push(pq.top().second);
    
    for(let i=k;i<nums.length;i++){
        while(pq.size()!=0 && i - pq.top().first+1 > k){
            pq.dequeue();
        }
        let p = new pair(i, nums[i]);
        pq.enqueue(p);
        res.push(pq.top().second);
    }
    
    return res;
    
    
};