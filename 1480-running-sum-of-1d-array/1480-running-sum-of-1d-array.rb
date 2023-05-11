# @param {Integer[]} nums
# @return {Integer[]}
def running_sum(nums)
    nums.map.with_index {|num, i| nums[0..i].sum}
end