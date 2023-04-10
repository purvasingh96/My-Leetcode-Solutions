function backtrack(l:number, r:number, m:Map<string, number>,temp:string, res:string[]): void {
    
    if(l>=r){
        if(l==r){
            for(let [key, value] of m.entries()){
                if(value==1){
                    temp = temp.slice(0, l) + key + temp.slice(l+1);
                }
            }
        }
        res.push(temp);
        return;
    }
    
    for(let [key, value] of m.entries()){
        if(value>=2){
            temp = temp.slice(0, l) + key + temp.slice(l+1);
            temp = temp.slice(0, r) + key + temp.slice(r+1);
            m.set(key, m.get(key)-2);
            l+=1;
            r-=1;
            backtrack(l, r, m, temp, res);
            r+=1;
            l-=1;
            m.set(key, m.get(key)+2);
        }
    }
    
    
}

function generatePalindromes(s: string): string[] {
const m = new Map<string, number>();
    for (const c of s) {
      m.set(c, (m.get(c) ?? 0) + 1);
    }
    let count = 0;
    for (const value of m.values()) {
      if (value == 1) {
        count += 1;
        if (count > 1) return [];
      }
    }
    const res: string[] = [];
    const n = s.length;
    let temp = '#'.repeat(n);
    backtrack(0, n - 1, m, temp, res);
    return res;
};