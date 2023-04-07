
class Node{
prev: Node;
 next: Node;
 key: number;
 val: number;

    constructor(key: number, val:number){
        this.prev=null;
        this.next=null;
        this.key=key;
        this.val=val;
    }
}

class LRUCache {

m = new Map<number, Node>();
 c: number;
 capacity: number;
 h: Node;  
 t: Node; 

    constructor(capacity: number) {
        this.c=0;
        this.capacity = capacity;
        this.h = new Node(-1, -1);
        this.t = new Node(-1, -1);
        this.h.next=this.t;
        this.t.prev=this.h;
    }
    
     removeNode(node: Node){
        let prev: Node = node.prev;
        let next: Node = node.next;
        prev.next=next;
        next.prev=prev;
        this.c-=1;
        this.m.delete(node.key);
    }
    
 addNodeFront(node: Node){
        let prev: Node = this.t.prev;
        prev.next=node;
        node.prev=prev;
        node.next=this.t;
        this.t.prev=node;
        this.m.set(node.key, node);
        this.c+=1;
    }

    get(key: number): number {
        let found: boolean =false;
        if(this.m.get(key)==undefined) return -1;
        let node: Node = this.m.get(key);
        this.removeNode(node);
        this.addNodeFront(node);
        return node.val;
    }

    put(key: number, value: number): void {
        if(this.m.get(key)!=undefined){
            let node: Node = this.m.get(key);
            this.removeNode(node);
            node.val = value;
            this.addNodeFront(node);
        } else {
            if(this.c==this.capacity) {
                this.removeNode(this.h.next);
            }
            let node: Node = new Node(key, value);
            this.addNodeFront(node);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */