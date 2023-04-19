function helper(temp: string, s:string, c: string, m:Map<string, number>, ans: {val: string[]}){
    let valid=0;
    for(let [k, v] of m.entries()){
        if(v>=2){
            m.set(k, m.get(k)-2);
            temp+=k;
            helper(temp, s,c, m, ans);
            temp = temp.slice(0, -1);
            m.set(k, m.get(k)+2);
            valid+=1;
        }
    }
    
    if(valid==0){
        let rs = temp;
        rs = rs.split("").reverse().join("");
        ans.val.push(temp+c+rs);
    }
}

function generatePalindromes(s: string): string[] {
    let m = new Map<string, number>();
    for(let c of s) {
        m.set(c, (m.get(c) ?? 0)+1);
    }
    
    let answer : {val: string[]} = {val: []};
    
    let odd=0;
    let c : string="";
    for(let [k,v] of m.entries()){
        if(v%2!=0){
            odd+=1;
            c = k;
        }
    }
    
    if(odd>1) return answer.val;
    let temp: string = "";
    helper(temp, s, c, m, answer);
    return answer.val;
    
};