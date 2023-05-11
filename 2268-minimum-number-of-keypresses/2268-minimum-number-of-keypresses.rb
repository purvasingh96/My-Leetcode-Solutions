# @param {String} s
# @return {Integer}
def minimum_keypresses(s)
    n = s.length
    if n <=9
        return n
    end
    
    x = Array.new(10, 0)
    count = Array.new(26, 0)
    
    (0..n-1).each do |i|
        idx = s[i].ord-'a'.ord
        count[idx]+=1
    end
    
    temp = []
    (0..25).each do |i|
        if count[i]!=0
            temp << count[i]
        end
    end
    
    temp.sort! { |a, b| b<=>a }

    pos=1
    sz = temp.size
    ans=0
    
    (0..sz-1).each do |i|
        x[pos%9] += 1
        ans += (x[pos%9]*temp[i])
        pos+=1
    end
    
    return ans
    
end