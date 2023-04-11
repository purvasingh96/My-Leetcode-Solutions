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

// O(logN) based implementation
class PQ<T> {
    private pq: T[] = [];
    private comp: Comparator<T>;
    constructor(comp: Comparator<T>){
        this.comp = comp;
    }

    size(): number {
        return this.pq.length;
    }
    
    parent(i: number): number {
        return Math.floor((i - 1)/2);
    }
    
    left(i: number) : number {
        return 2*i+1;
    }
    
    right(i:number) : number {
        return 2*i+2;
    }    
    
    hasLeft(i: number) : boolean {
        return this.left(i) < this.pq.length;
    }
    
    hasRight(i:number) : boolean {
        return this.right(i) < this.pq.length;
    }

    top() : T | undefined {
        return this.pq[0];
    }

   

    heapUp(i: number): void {
        while(i>0){
            let p: number = this.parent(i);
            if(this.comp(this.pq[i], this.pq[p]) < 0){
                [this.pq[i], this.pq[p]] = [this.pq[p], this.pq[i]];
                i=p;
            } else break;
        }
    }

    heapDown(i: number): void {
        while(true){
            let leftChild: number = this.left(i);
            let rightChild: number = this.right(i);
            let minIndex = i;
            
            if(this.hasLeft(i) && this.comp(this.pq[leftChild], this.pq[minIndex])<0){
                minIndex = leftChild;
            } 
            
            if(this.hasRight(i) && this.comp(this.pq[rightChild], this.pq[minIndex])<0){
                minIndex = rightChild;
            }
            
            if(minIndex!=i){
                [this.pq[minIndex], this.pq[i]] = [this.pq[i], this.pq[minIndex]];
                i = minIndex;
            } else break;
        }
    }

    enqueue(val: T) : void {
        this.pq.push(val);
        this.heapUp(this.pq.length-1);
    }
    
    dequeue() : T | undefined {
        if(this.pq.length==0) return undefined;
        const root = this.pq[0];
        const last = this.pq.pop();
        if(this.pq.length > 0){
            this.pq[0] = last;
            this.heapDown(0);
        }
        
        return root;
    }
}

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    let pq = new PQ<ListNode>((a, b) => (a.val - b.val));
    for(let node of lists){
       if(node) pq.enqueue(node);
    }
    
    let ans = new ListNode(0);
    let res = ans;
    
    while(pq.size()!=0){
        let f = pq.top();
        pq.dequeue();
        ans.next = f;
        ans=ans.next;
        if(f.next) pq.enqueue(f.next);
    }
    
    return res.next;
};