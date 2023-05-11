# @param {Integer[]} nums
# @return {Integer[][]}

def helper(idx, temp=[], res, nums)
    if(idx >= nums.size)
        res << temp
        return
    end
    
    # dont chose
    helper(idx+1, temp, res, nums)
    
    # choose
    helper(idx+1, temp+[nums[idx]], res, nums)
    
end

def subsets(nums)
    temp = []
    res=[]
    
    helper(0, temp, res, nums)
    res
end