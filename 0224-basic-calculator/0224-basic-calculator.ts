let i;
function dfs(s: string, d: number, op: string) : number {
    let st: number[] = [];
    
    while(i<s.length && s[i]!=")"){
        //console.log(i, s[i]);
        if(s[i] == " ") {
            i+=1;
            continue;
        }
        else if(s[i] >="0" && s[i]<="9"){
            //console.log("digit");
            d=d*10 + (s[i].charCodeAt(0) - "0".charCodeAt(0));
        } else if(s[i] == "("){
            i+=1;
            if(op == "+") st.push(d);
            else st.push(-d);
            let res = dfs(s, 0, "+");
            if(op == "+") st.push(res);
            else st.push(-res);
            
        } else {
            // operator
            if(op == "+") st.push(d);
            else st.push(-d);
            op = s[i];
            d=0;
        }
        i+=1;
    }
    
    if(op == "+") st.push(d);
    else st.push(-d);
    
    let ans =0;
    for(let i=0;i<st.length;i++){
        ans += st[i];
    }
    
    return ans;
    
}

function calculate(s: string): number {
    s = "("+s+")";
    i = 0;
    return dfs(s, 0, "+");
};