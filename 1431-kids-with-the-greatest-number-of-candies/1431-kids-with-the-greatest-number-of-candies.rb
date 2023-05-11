# @param {Integer[]} candies
# @param {Integer} extra_candies
# @return {Boolean[]}
def kids_with_candies(candies, extra_candies)
    val = candies.max
    n = candies.size
    res = []
    (0..n-1).each do |i|
        if(candies[i]+extra_candies >=val)
            res << true
        else
            res << false
        end
    end
    res
end