function strSort(s: string){
    let count = new Array<number>(26);
    for(let i=0;i<26;i++) count[i]=0;
    
    for(let i=0;i<s.length;i++){
        let idx: number = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
        count[idx]+=1;
    }
    
    let res: string = "";
    for(let i=0;i<26;i++){
        if(count[i]>0){
            let t: string="";
            let p: string = String.fromCharCode(i+97);
            t = t.padStart(count[i],p);
            res+=t;
        }
    }
    
    return res;
}


function groupAnagrams(strs: string[]): string[][] {
    let m = new Map<string, string[]>();
    
    for(let s of strs){
        let anagram = strSort(s);
        if(m.get(anagram)==undefined){
            m.set(anagram, new Array<string>());
        }
        m.get(anagram)!.push(s);
    }
    
    let res: string[][] = [];
    for(let values of m.values()){
        res.push(values);
    }
    
    return res;
};
