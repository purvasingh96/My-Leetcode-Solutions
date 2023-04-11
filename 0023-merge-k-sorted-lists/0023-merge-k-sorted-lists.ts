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
    private queue: T[] = [];
    private comp: Comparator<T>;
    constructor(comp:Comparator<T>){
        this.comp = comp;
    }
    
    enqueue(x:T): void {
        let insert: boolean = false;
        
        for(let i=0;i<this.queue.length;i++){
            if(this.comp(this.queue[i], x) < 0){
                this.queue.splice(i, 0, x);
                insert=true;
                break;
            }
        }
        
        if(!insert){
            this.queue.push(x);
        }
    }
    
    top() : T | undefined {
        return this.queue[0];
    }

    pop() : T | undefined {
        return this.queue.shift();
    }

    size(): number {
        return this.queue.length;
    }
    
    isEmpty(): boolean {
        return this.size()==0;
    }
}


function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    let pq = new PQ<ListNode>((a, b) => (b.val-a.val));
    
    for(let node of lists){
        if(node) pq.enqueue(node);
    }
    
    let ans = new ListNode(0);
    let res = ans;
    
    while(!pq.isEmpty()){
        let f = pq.top(); pq.pop();
        ans.next = f;
        ans = ans.next;
        if(f.next) pq.enqueue(f.next);
    }
    
    return res.next;
        
};