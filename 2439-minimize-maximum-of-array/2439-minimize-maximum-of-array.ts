function isPossible(mid: number, arr: number[]) : boolean {
    if(arr[0] > mid) return false;
    const n = arr.length;
  
    
    for(let i=n-1;i>=1;i--){
        if(arr[i] > mid) 
        {
            const differ = arr[i] - mid;
            arr[i-1] += differ;
        }
    }
    return arr[0] <= mid;
}


function minimizeArrayValue(nums: number[]): number {
    let l = nums[0], r = Math.max(...nums);
    let ans;
    
    while(l<=r){
        let mid: number = (l+r)>>1;
        
        const res: boolean = isPossible(mid, [...nums]);
        
       // for(let i=0;i<nums.length;i++) console.log(nums[i]);
       //  console.log("mid: ", mid, "res: ", res);
        if(res){
            ans = mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    return ans;
};