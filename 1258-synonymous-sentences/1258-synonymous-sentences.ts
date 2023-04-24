class queue<T>{
    private q: T[] = [];
    constructor(){}

    empty() : boolean {
        return this.size()==0;
    }
    
    size() : number {
        return this.q.length;
    }

    push(val: T) : void {
        this.q.push(val);
    }
    
    pop() : void {
        this.q.shift();
    }
    
    front() : T | undefined {
        if(this.size()==0) return undefined;
        return this.q[0];
    }

}

function buildUtil(s: string[]){
    let res = s.join(" ");
    return res;
}

function generateSentences(synonyms: string[][], text: string): string[] {
    let q= new queue<string[]>();
    let s = text.split(" ");
    let ans: string[] = [];
    let ansSet = new Set<string>();
   
    q.push(s);
    ansSet.add(text);
    
    let m = new Map<string, string[]>();
    for(let syno of synonyms){
        let u = syno[0], v = syno[1];
        
        m.set(u, [...m.get(u)||[], v]);
        m.set(v, [...m.get(v)||[], u]);
        
    }
    
    //console.log(m);
   
    while(!q.empty()){
        let f = q.front();
        q.pop();
        for(let i=0;i<f.length;i++){
            let word = f[i];
            if(m.get(word)!=undefined){
                for(let syno of m.get(word)){
                    f[i] = syno;
                    let next = buildUtil([...f]);
                    if(!ansSet.has(next)){
                        q.push([...f]);
                        ansSet.add(next);
                    }
                    
                }
            }
        }
    }
    
    for(let words of ansSet) ans.push(words);
    ans.sort();
    return ans;
    
    
};