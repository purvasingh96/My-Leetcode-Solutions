# @param {Integer[]} nums
# @param {Integer} n
# @return {Integer[]}
def shuffle(nums, n)
    i,j,k = 0, n, nums.size
    arr = Array.new
    while i<n && j<k do
        arr << nums[i]
        arr << nums[j]
        i+=1
        j+=1
    end
    return arr
end