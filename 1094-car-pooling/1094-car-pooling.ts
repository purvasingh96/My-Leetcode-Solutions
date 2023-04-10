function carPooling(trips: number[][], capacity: number): boolean {
    let res = new Array<number>(1001);
    for(let i=0;i<=1001;i++) res[i]=0;
    
    for(let t of trips){
        let p:number=t[0];
        let s:number = t[1];
        let e:number = t[2];
        
        res[s]+=p;
        res[e]-=p;
    }
    
    let maxVal = res[0];
    for(let i=1;i<=1001;i++){
        res[i] += res[i-1];
        maxVal = Math.max(maxVal, res[i]);
        if(maxVal>capacity) return false;
    }
    return true;
    
};