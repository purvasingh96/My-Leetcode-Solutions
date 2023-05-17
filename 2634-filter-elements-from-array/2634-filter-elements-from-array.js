/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let idx=0;
    for(let i=0;i<arr.length;i++){
        if(fn(arr[i], i)){
            arr[idx++] = arr[i];
        } 
    }
    
    while(arr.length > idx) arr.pop();
    
    return arr;
};