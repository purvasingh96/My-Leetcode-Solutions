function maxSlidingWindow(nums: number[], k: number): number[] {
    let q: number[] = [];
    let res: number[] = [];
    
    for(let i=0;i<nums.length;i++){
        let cur = nums[i];
        //console.log(i, q);
        while(q.length!=0 && nums[q[q.length-1]]<cur){
            q.pop();
        }
        
        q.push(i);
        //console.log(i, q);
        // out of bounds
        while(q.length!=0 && q[0] < (i-k+1)){
            q.shift();
        }
        //console.log(i, q);
        if(i>=k-1){
            res.push(nums[q[0]]);
        }
        
        
    }
    
    return res;
    
};