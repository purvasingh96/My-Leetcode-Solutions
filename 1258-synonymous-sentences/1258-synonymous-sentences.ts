let root = new Map<string, string>();
let rank = new Map<string, number>();
let m = new Map<string, Set<string>>();

function find(node: string) : string {
    if(root[node]==node) return node;
    return root[node] = find(root[node]);
}

function merge(x:string, y:string) {
    m.get(y)?.add(x);
    m.get(x)?.add(y);
    
    const rx: string = find(x);
    const ry: string = find(y);
    
    if(rx!=ry){
        if(rank[rx] >= rank[ry]){
            root[ry]=rx;
            rank[rx]+=rank[ry];
        } else {
            root[rx]=ry;
            rank[ry]+=rank[rx];
        }
    }
}

function remove(s:string): string{
    let i = s.length-1;
    while(i>=0 && s[i]!==' '){
        s=s.slice(0, -1);
        i-=1;
    }
    return s;
}

function dfs(idx: number, s:string[], temp:string, res:string[]){
    if(idx>=s.length){
        let t = temp;
        t = t.slice(0, -1);
        res.push(t);
        return;
    }
    
    temp += (s[idx]+" ");
    dfs(idx+1, s, temp, res);
    temp = temp.slice(0, -1);
    temp = remove(temp);
    
    let neighbors: Set<string> = m.get(s[idx]);
    
    if(neighbors!==undefined){
        for(let next of neighbors.values()){
            temp += (next+" ");
            dfs(idx+1, s, temp, res);
            temp = temp.slice(0, -1);
            temp = remove(temp);
        }
    }
}


function generateSentences(synonyms: string[][], text: string): string[] {

    for(let i=0;i<synonyms.length;i++){
        const u=synonyms[i][0];
        const v=synonyms[i][1];
        root[u]=u;
        root[v]=v;
        rank[u]=1;
        rank[v]=1;
        m.set(u, new Set<string>());
        m.set(v, new Set<string>());
    }
    
    for(let s of synonyms){
        merge(s[0], s[1]);
    }
    
    for(let [v, u] of root.entries()){
        if(find(u) !== v){
            m.get(find(u))?.add(v);
        }
    }
    
    for(let [u, v] of m.entries()){
        for(let y of v){
            for(let z of v){
                if(y!=z) {
                    m.get(y)?.add(z);
                    m.get(z)?.add(y);
                }
            }
        }
        for(let y of v){
            if(y==u) v.delete(y);
        }
    }
    
    // for(let [u, v] of m.entries()){
    //     console.log(u, "->");
    //     for(let k of v) console.log(k);
    // }
    
    let tempString: string = "";
    let splitString = text.split(" ");
    let res: string[] = [];
    
    dfs(0, splitString, tempString, res);
    res.sort();
    root.clear();
    rank.clear();
    m.clear();
        
    return res;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
    
    
    
    
};