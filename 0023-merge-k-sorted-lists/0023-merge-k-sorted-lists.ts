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
class PQ<T>{
    public pq: T[] = [];
    public comp: Comparator<T>;
    constructor(comp: Comparator<T>) {
        this.comp = comp;
    }

    size() : number {
        return this.pq.length;
    }

    empty() : boolean{
            return this.size()==0;
        }
    
    top(): T | undefined {
        if(this.size()==0) return undefined;
        return this.pq[0];
    }

    left(i: number) : number{
        return 2*i+1;
    }

    right(i: number) : number {
        return 2*i+2;
    }

    parent(i: number) : number {
        return Math.floor((i-1)/2);
    }

    hasLeft(i: number) : boolean {
        return this.left(i) < this.size();
    }

    hasRight(i: number) : boolean {
        return this.right(i) < this.size();
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

    heapUp(i: number) : void{
        while(i>0){
            let p = this.parent(i);
            if(this.comp(this.pq[i], this.pq[p]) < 0) {
                [this.pq[i], this.pq[p]] = [this.pq[p], this.pq[i]];
                i=p;
            } else break;
        }
    }

    heapDown(i: number) : void{
        while(true){
            let l = this.left(i);
            let r = this.right(i);
            let min=i;
            
            if(this.hasLeft(i) && this.comp(this.pq[l], this.pq[min]) < 0){
                min = l;
            }
            
            if(this.hasRight(i) && this.comp(this.pq[r], this.pq[min]) < 0){
                min = r;
            }
            
            if(min == i) break;
            else {
                [this.pq[min], this.pq[i]] = [this.pq[i], this.pq[min]];
                i = min;
            }
        }
    }


    
}

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {

    let pq = new PQ<ListNode>((a: ListNode, b: ListNode) => (a.val - b.val));
    let temp = new ListNode(-1);
    for(let node of lists){
       if(node) pq.enqueue(node); 
    }
    let ans = temp;
    while(!pq.empty()){
        let f = pq.top();
        pq.dequeue();
        if(f){
            temp.next = new ListNode(f.val);
            temp = temp.next;
            if(f.next) pq.enqueue(f.next);
        }
        
    }
    return ans.next;
    
    
};