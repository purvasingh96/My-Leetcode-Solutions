let i: number=0;
function dfs(s:string, temp:number, t:number[], op:string){
    while(i<s.length && s[i]!=')'){
        if(s[i]==" "){
            i+=1;
            continue;
        } else if(s[i]>="0" && s[i]<="9"){
            
            let k:number = (s.charCodeAt(i)-"0".charCodeAt(0));
            temp = temp*10 + (k);
            i+=1;
        } else if(s[i]=="+" || s[i]=="-"){
            if(op == "+") t.push(temp);
            else t.push(-temp);
            
            op = s[i];
            temp=0;
            i+=1;
        } else if(s[i] == "("){
            let newT: number[] = [];
            temp=0;
            i+=1;
            let val: number = dfs(s, temp, newT, "+");
            if(op == "+") t.push(val);
            else t.push(-val);
            i+=1;
        }
    }
    
    if(op == "+") t.push(temp);
    else t.push(-temp);
    
    let sum:number=0;
    for(let num of t){
        sum += num;
    }
    
    return sum;
}

function calculate(s: string): number {
    let temp: number=0;
    let t: number[] = [];
    i=0;
    let newS = "(" + s + ")"
    return dfs(newS, temp, t, "+");
    
};