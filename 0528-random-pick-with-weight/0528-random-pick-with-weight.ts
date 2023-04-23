class Solution {
    private w: number[] = [];
    private ps: number[] = [];
    
    binarySearch(target:number){
        let l: number =0;
        let r:number = this.ps.length-1;
        let ans:number=0;
        let idx:number=0;
        while(l<=r){
            let mid: number = l + Math.floor((r-l)/2);
            if(this.ps[mid] > target){
                ans=this.ps[mid];
                idx = mid;
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        
        return idx;
    }
    
    constructor(w: number[]) {
        this.w=w;
        this.ps.push(w[0]);
        for(let i=1;i<w.length;i++){
            this.ps.push(this.ps[this.ps.length-1] + w[i]);
        }
    }

    pickIndex(): number {
        let min: number = 0;
        let max: number = this.ps[this.ps.length-1];
        
        let randIndex = Math.floor(Math.random() * (this.ps[this.ps.length-1]));
        let bs = this.binarySearch(randIndex);
        //console.log(randIndex);
        if(bs == this.ps.length) return this.ps.length-1;
        return bs;
        
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(w)
 * var param_1 = obj.pickIndex()
 */