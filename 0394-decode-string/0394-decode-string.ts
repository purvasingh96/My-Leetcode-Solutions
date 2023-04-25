let i: number;

function dfs(s: string, t: number){
    let temp: string = "";
    
    while(i<s.length && s[i]!="]"){
        if(!isNaN(parseInt(s[i]))){
               t=t*10 + (s[i].charCodeAt(0) - "0".charCodeAt(0));
        } else if(s[i] == "["){
            i+=1;
            let f = t;
            let res = dfs(s, 0);
            let ans="";
            while(f--){
                ans+=res;
            }
            temp+=ans;
            t=0;
        } else{
            temp+=s[i];
        }
        i+=1;
    }
    
    return temp;
}


function decodeString(s: string): string {
    i=0;
    let t=0;
    return dfs(s, t);
};