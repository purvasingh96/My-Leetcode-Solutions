class Node{
    public next;
    public prev;
    public key;
    public val;
    constructor(key: number, val:number){
        this.key = key;
        this.val = val;
        this.prev=null;
        this.next=null;
    }
}

class LRUCache {
    private head;
    private tail;
    private m;
    private c;
    constructor(capacity: number) {
        this.c = capacity;
        this.m = new Map<number, Node>();
        this.head = new Node(-1, -1);
        this.tail = new Node(-1, -1);
        
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }
    
    remove(node: Node) : void {
        let back = node.prev;
        back.next = node.next;
        node.next.prev = back;
        this.m.delete(node.key);
    }

    addToFront(node: Node) : void {
        //console.log(this.m.size);
        if(this.m.size == this.c){
            // remove LRU
            this.remove(this.head.next);
        }
        
        let back = this.tail.prev;
        back.next = node;
        node.prev = back;
        node.next = this.tail;
        this.tail.prev = node;
        
        this.m.set(node.key, node);
    }
    

    get(key: number): number {
        if(this.m.get(key) == undefined) return -1;
        let targetNode = this.m.get(key);
        this.remove(targetNode);
        this.addToFront(targetNode);
        return this.m.get(key).val;
    }

    put(key: number, value: number): void {
        let targetNode=null;
        if(this.m.get(key) == undefined){
            targetNode = new Node(key, value);
        } else {
            let temp = this.m.get(key);
            this.remove(temp);
            temp.val = value;
            targetNode = temp;
        }
        
        this.addToFront(targetNode);
        
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */