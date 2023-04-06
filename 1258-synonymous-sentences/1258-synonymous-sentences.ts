let m = new Map<string, Set<string>>();
let rank = new Map<string, number>();
let root = new Map<string, string>();

function find(s: string): string{
    if(root.get(s)===s) return s;
    return root.set(root.get(s)!, find(root.get(s)!)).get(s)!;
}

function merge(x:string, y:string){
    m.get(x)?.add(y);
    m.get(y)?.add(x);
    
    let rx: string = find(x);
    let ry: string = find(y);
    if(rx!=ry){
        if(rank.get(rx)!>=rank.get(ry)){
            rank.set(rx, rank.get(rx)!+rank.get(ry));
            root.set(ry, rx);
        } else{
            rank.set(ry, rank.get(ry)!+rank.get(rx));
            root.set(rx, ry);
        }
    }
}

function remove(s:string): string{
    let i=s.length-1;
    while(i>=0 && s[i]!=' '){
        s=s.slice(0, -1);
        i--;
    }
    return s;
}

function dfs(idx:number, s:string[], temp:string, res:string[]){
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
    let neighbors = m.get(s[idx]);
    if(m.get(s[idx])!==undefined){
        for(let next of m.get(s[idx]).values()){
            temp += (next+" ");
            dfs(idx+1, s, temp, res);
            temp = temp.slice(0, -1);
            temp = remove(temp);
        }
    }
    
}


function generateSentences(synonyms: string[][], text: string): string[] {
    for(let s of synonyms){
        const u = s[0];
        const v =s[1];
        root.set(u, u);
        root.set(v, v);
        rank.set(u, 1);
        rank.set(v, 1);
        m.set(u, new Set<string>());
        m.set(v, new Set<string>());
    }
    
    for(let s of synonyms) merge(s[0], s[1]);
    
    for(let [v, u] of root.entries()){
        if(find(u)!==v) m.get(find(u))?.add(v);
    }
    
    for(let [u, v] of m.entries()){
        for(let y of v){
            for(let z of v){
                if(y!=z){
                    m.get(y)?.add(z);
                    m.get(z)?.add(y);
                }
            }
        }
        for(let y of v){
            if(y==u) v.delete(y);
        }
    }
    
    
    
    let s: string[] = text.split(" ");
    let temp: string="";
    let res: string[] = [];
    dfs(0, s, temp, res);
    root.clear();
    rank.clear();
    m.clear();
    res.sort();
    return res;
};