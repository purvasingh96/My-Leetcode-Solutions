
let i: number;
function dfs(s: string, d: number, op: string){
    let st: number[] = [];
    while(i<s.length && s[i]!=")"){
        if(s[i]==" "){
            i+=1;
            continue;
        } else if(!isNaN(parseInt(s[i]))){
            // digit
            d = d*10 + (s[i].charCodeAt(0) - "0".charCodeAt(0));
        } else if(s[i]=="("){
            i+=1;
            d=0;
            let temp = dfs(s, d, "+");
            
            if(op == "+") st.push(temp);
            else st.push(-temp);
            
        } else {
            if(op == "+") st.push(d);
            else st.push(-d);
            op = s[i];
            d=0;
        }
        i+=1;
    }
    
    if(op == "+") st.push(d);
    else st.push(-d);
    
    let ans=0;
    for(let x of st) ans+=x;
    return ans;
    
}


function calculate(s: string): number {
    i=0;
    let d=0;
    let op = "+";
    s="("+s+")";
    return dfs(s, d, op);
};