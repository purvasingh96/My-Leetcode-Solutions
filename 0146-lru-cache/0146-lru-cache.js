/**
 * @param {number} capacity
 */

class Node{
    constructor(key, val, next=null, prev=null){
        this.next=next;
        this.prev=prev;
        this.key = key;
        this.val = val;
    }
}

var LRUCache = function(capacity) {
    this.capacity = capacity;
    this.head = new Node(0, 0);
    this.tail = new Node(0, 0);
    
    this.head.next=this.tail;
    this.tail.prev=this.head;
    this.m = new Map();
};


LRUCache.prototype.removeNode = function(node){
    let temp = node;
    let previousValue = temp.prev;
    let nextValue = temp.next;
    previousValue.next=nextValue;
    nextValue.prev=previousValue;
    this.m.delete(temp.key);
} 

LRUCache.prototype.addNodeToFront = function(node){
    let temp = node;
    let previousValue = this.tail.prev;
    previousValue.next = temp;
    temp.prev = previousValue;
    temp.next = this.tail;
    this.tail.prev = temp;
    this.m.set(temp.key, temp);
}


LRUCache.prototype.get = function(key) {
    if(!this.m.has(key)) return -1;
    let temp = this.m.get(key);
    this.removeNode(temp);
    this.addNodeToFront(temp);
    return temp.val;
};

LRUCache.prototype.put = function(key, value) {
    let temp;
     
    if(this.m.has(key)){
        this.removeNode(this.m.get(key));
    } else {
         if(this.m.size == this.capacity){
        console.log(this.m.size, key, value);
        this.removeNode(this.head.next);
    }
    }
    
        temp = new Node(key, value);
        this.addNodeToFront(temp);
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */