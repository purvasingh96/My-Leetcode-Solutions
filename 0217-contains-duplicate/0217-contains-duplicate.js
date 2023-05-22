/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let m = new Map();
    for(let x of nums){
        m.set(x, (m.get(x)??0)+1);
        if(m.get(x) >= 2) return true;
    }
    return false;
    
};