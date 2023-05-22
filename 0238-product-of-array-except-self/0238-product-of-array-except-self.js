/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let temp = [];
    temp.push(1);
    let prefix=1;
    
    for(let i=1;i<nums.length;i++){
        prefix = nums[i-1]*prefix;
        temp.push(prefix);
    }
    
    console.log(temp);
    let ps=1;
    for(let i=nums.length-2;i>=0;i--){
        ps = ps*nums[i+1];
        temp[i]= temp[i]*ps;
    }
    
    
    
    
    return temp;
};