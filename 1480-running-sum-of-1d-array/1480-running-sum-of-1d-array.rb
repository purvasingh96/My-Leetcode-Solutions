# @param {Integer[]} nums
# @return {Integer[]}
def running_sum(nums)
    res = []
    n = nums.size
    res << nums[0]
    (1..n-1).each {|i| res << (res.last + nums[i])}
    res
end