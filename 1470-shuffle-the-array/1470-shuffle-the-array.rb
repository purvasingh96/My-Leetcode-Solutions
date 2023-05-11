# @param {Integer[]} nums
# @param {Integer} n
# @return {Integer[]}
def shuffle(nums, n)
    $i=0
    $j=n
    arr = Array.new
    $k = nums.size
    while $i<n && $j<$k do
        arr.push(nums[$i])
        arr.push(nums[$j])
        $i+=1
        $j+=1
    end
    return arr
end