function dfs(temp: string, s: string, center: string, m: Map<string, number>, ans:{val: string[]}){
    let valid=true;
    for(let [k,v] of m.entries()){
        if(v>=2){
            m.set(k, m.get(k)-2);
            temp+=k;
            dfs(temp, s, center, m, ans);
            temp = temp.slice(0, -1);
            m.set(k, m.get(k)+2);
            valid=false;
        }
    }
    
    if(valid){
        let rev =temp;
        rev = rev.split("").reverse().join("");
        ans.val.push(temp+center+rev);
    }
    
    
}


function generatePalindromes(s: string): string[] {
    let m = new Map<string, number>();
    let odd=0;
    let center = "";
    let ans : {val: string[]} = {val: []};
    for(let c of s){
        m.set(c, (m.get(c)??0)+1);
    }
    
    for(let [k,v] of m.entries()){
        if(v%2!=0) {
            odd+=1;
            center = k;
        }
        if(odd>1) return ans.val;
        
    }
    let temp="";
    dfs(temp, s, center, m, ans);
    return ans.val;
    
};