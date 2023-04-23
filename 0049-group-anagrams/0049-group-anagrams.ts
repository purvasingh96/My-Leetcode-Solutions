
function strSort(s: string) : string{
    let count = new Array(26).fill(0);
    for(let c of s){
        let idx = c.charCodeAt(0) - "a".charCodeAt(0);
        count[idx]+=1;
    }
    let res="";
    for(let i=0;i<26;i++){
        res+="#";
        res+= count[i].toString();
    }
    //console.log(res);
    return res;
    
}

function groupAnagrams(strs: string[]): string[][] {
    let ans: string[][] = [];
    let m = new Map<string, string[]>();
    
    for(let s of strs){
        let sortS = strSort(s);
        if(m.get(sortS) == undefined){
            m.set(sortS, new Array<string>());
        }
        m.get(sortS).push(s);
    }
    
    
    for(let v of m.values()){
        ans.push(v);
    }
        
    return ans;
};