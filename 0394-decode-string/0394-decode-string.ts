let i: number;
let t: number;
function dfs(s: string){
    
    let temp: string = "";
    
    while(i<s.length && s[i]!="]"){
        // digit
        if(!isNaN(parseInt(s[i]))){
            let t=0;
            while(!isNaN(parseInt(s[i]))){
                t=t*10 + parseInt(s[i]) - parseInt("0");
                i+=1;
            }
            
            // skip ]
            i+=1;
            let res = dfs(s);
            i+=1;
            while(t--) temp+=res;
        } else {
            temp += s[i++];
        }
    }
    
    return temp;
}

function decodeString(s: string): string {
    i=0;
    //console.log(isDigit("["));
    t=0;
    return dfs(s);
};