/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

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



function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
  let pq = new PQ<ListNode>((a, b) => (a.val - b.val));
    
    for(let node of lists){
        if(node) pq.enqueue(node);
    }
    
    let ans = new ListNode(0);
    let res = ans;
    
    while(!pq.empty()){
        let f = pq.top(); pq.dequeue();
        ans.next = f;
        ans = ans.next;
        if(f.next) pq.enqueue(f.next);
    }
    
    return res.next;
};