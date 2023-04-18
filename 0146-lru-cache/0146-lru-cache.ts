class Node{
    public prev;
    public next;
    public key;
    public value;
    constructor(key: number, value: number) {
        this.prev=null;
        this.next=null;
        this.value=value;
        this.key=key;
    }
}

class LRUCache {
    private head: Node = null;
    private tail: Node = null;
    private c: number;
    private m = new Map<number, Node>();

    constructor(capacity: number) {
        this.head = new Node(-1, -1);
        this.tail = new Node(-1, -1);
        this.head.next = this.tail;
        this.tail.prev = this.head;
        this.c = capacity;
    }

    remove(node:Node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
        this.m.delete(node.key);
    }

    
    addToFront(node: Node){
        if(this.m.size == this.c) {
            this.remove(this.head.next);
        }
        let back = this.tail.prev;
        this.tail.prev = node;
        node.prev = back;
        back.next = node;
        node.next=this.tail;
        this.m.set(node.key, node);
    }

    get(key: number): number {
        //console.log("calling get : ", key, "m.size: ", this.m.size, "front: ", this.tail.prev.key);
        if(this.m.get(key)==undefined) return -1;
        let target = this.m.get(key);
        this.remove(target);
        this.addToFront(target);
        return target.value;
    }

    put(key: number, value: number): void {
        //console.log("calling put : ", key, "m.size: ", this.m.size, "front: ", this.tail.prev.key);
        let target: Node = null;
        
        if(this.m.get(key) == undefined){
            target = new Node(key, value);
        }
        else {
           target = this.m.get(key);
            this.remove(target);
            target.value = value;
        }

        this.addToFront(target); 
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */