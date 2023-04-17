class TrieNode{
    public eow: boolean;
    public children: TrieNode[];
    constructor(){
        this.eow=false;
        this.children=[];
        for(let i=0;i<26;i++){
            this.children.push(null);
        }
    }
}

class Trie {
    private root;
    constructor() {
        this.root = new TrieNode();
    }

    insert(word: string): void {
        let node = this.root;
        for(let i=0;i<word.length;i++){
            let idx: number = word[i].charCodeAt(0)-"a".charCodeAt(0);
            if(node.children[idx]==null){
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
        }
        node.eow=true;
        
    }

    search(word: string): boolean {
        let node = this.root;
        for(let i=0;i<word.length;i++){
            let idx = word[i].charCodeAt(0) - "a".charCodeAt(0);
            if(node.children[idx]==null) return false;
            node = node.children[idx];
        }
        
        return node.eow;
    }

    startsWith(prefix: string): boolean {
        let node = this.root;
        for(let i=0;i<prefix.length;i++){
            let idx: number = prefix[i].charCodeAt(0) - "a".charCodeAt(0);
            if(node.children[idx]==null) return false;
            node = node.children[idx];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */