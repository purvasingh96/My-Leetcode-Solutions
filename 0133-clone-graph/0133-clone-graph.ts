/**
 * Definition for Node.
 * class Node {
 *     val: number
 *     neighbors: Node[]
 *     constructor(val?: number, neighbors?: Node[]) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.neighbors = (neighbors===undefined ? [] : neighbors)
 *     }
 * }
 */

let m = new Map<Node, Node>();

function dfs(node: Node | null): Node | null {
    if(node==null) return node;
    
    for(let key of m.keys()){
        if(key==node) return m.get(key);
    }
    
    
    let parent = new Node(node.val);
    m.set(node, parent);
    
    for(let child of node.neighbors){
        parent.neighbors.push(dfs(child));
    }
    
    return parent;
}

function cloneGraph(node: Node | null): Node | null {
	return dfs(node);
};