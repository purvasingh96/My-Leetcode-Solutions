# @param {Integer[]} nums
# @return {Integer[][]}

$res = []
def backtrack(nums, temp, visited)
    if(temp.size == nums.size)
        $res << temp.dup
        return
    end
    
    n = nums.size
    (0..n-1).each do |i|
        if(visited.include?(nums[i]) == false)
            visited << nums[i]
            temp << nums[i]
            backtrack(nums, temp, visited)
            temp.pop
            visited.delete(nums[i])
        end
    end
    
end


def permute(nums)
    temp=[]
    visited = Set.new
    backtrack(nums, temp, visited)
    ans = $res
    $res = []
    ans
end