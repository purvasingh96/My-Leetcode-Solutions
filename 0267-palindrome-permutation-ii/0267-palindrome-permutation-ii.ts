function backtrack(l: number, r:number, m:Map<string, number>, s: string, temp: string, res:{val: string[]}){
    if(l >= r){
        if(l == r){
             for(let [k,v] of m.entries()){
                 if(v==1) {
                     temp = temp.slice(0, l) + k + temp.slice(l+1);
                     break;
                 }
             }
        }
        
        res.val.push(temp);
        return;
    }
    
    for(let  [k, v] of m.entries()){
        if(v>=2){
            let og = temp;
            temp = temp.slice(0, l) + k + temp.slice(l+1);
            temp = temp.slice(0, r) + k + temp.slice(r+1);
            l+=1;
            r-=1;
            m.set(k, m.get(k)-2);
            backtrack(l, r, m, s, temp, res);
            m.set(k, m.get(k)+2);
            r+=1;
            l-=1;
            temp = og;
        }
    }
    
    
}

function generatePalindromes(s: string): string[] {
    let m = new Map<string, number>();
    for(let c of s){
        m.set(c, (m.get(c) ?? 0)+1);
    }
    
    let res: {val: string[]} = {val: []};
    let n = s.length;
    let l=0, r = n-1;
    let temp = "#".repeat(n);
    
    backtrack(l, r, m, s, temp, res)
    return res.val;
};