# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Integer[][]}
def find_difference(nums1, nums2)
    [(nums1-nums2).uniq, (nums2-nums1).uniq]
    
end