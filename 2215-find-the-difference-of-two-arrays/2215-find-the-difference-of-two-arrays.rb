# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Integer[][]}
def find_difference(nums1, nums2)
    m1, m2 = {}, {}
    n1, n2 = nums1.size, nums2.size
    
    (0..n1-1).each do |i|
        m1[nums1[i]] = 1
        m2[nums1[i]] = -1
    end
    
    (0..n2-1).each do |i|
        m1[nums2[i]]=-1
        if !m2.key?(nums2[i])
            m2[nums2[i]] = 1
        end
    end
    
    v1, v2 = [], []
    ans = []
    
    m1.map {|k,v| v==1?v1<<k:next}
    
    m2.map {|k,v| v==1?v2<<k:next}
    
    ans = [v1, v2]
    
    ans
    
end