function build(s: string[]){
    let t :string= "";
    for(let word of s){
        t += word;
        t+=" ";
    }
    
    t = t.slice(0, -1);
    return t;
}

function generateSentences(synonyms: string[][], text: string): string[] {
    let q: string[][] = [];
    let splt = text.split(" ");
    q.push(splt);
    let st = new Set<string>();
    st.add(text);
    let m = new Map<string, string[]>();
    
    for(let s of synonyms){
        m.set(s[0], [...m.get(s[0]) || [], s[1]]);
        m.set(s[1], [...m.get(s[1]) || [], s[0]]);
    }
    
    while(q.length!=0){
        let f: string[] = q[0];
        q.shift();
        
        for(let i=0;i<f.length;i++){
            let word = f[i];
            if(m.get(word)!=undefined){
                for(let syno of m.get(word)){
                    f[i] = syno;
                    let temp: string = build(f);
                    if(!st.has(temp)){
                        st.add(temp);
                        q.push([...f]);
                    }
                }
            }
        }
 
    }
    
    let ans :  string[] = [];
    for(let x of st) ans.push(x);
    ans.sort();
    return ans;
    
    
};