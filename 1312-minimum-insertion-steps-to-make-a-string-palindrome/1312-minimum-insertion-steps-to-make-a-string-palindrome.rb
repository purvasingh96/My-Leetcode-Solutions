# @param {String} s
# @return {Integer}

def lcs(s1, s2, i, j, memo)
    if(i ==0 || j==0)
        return 0
    end
    
    if(memo[i][j]!=-1)
        return memo[i][j];
    end
    
    if(s1[i-1] == s2[j-1])
        return memo[i][j] = 1+lcs(s1, s2, i-1, j-1, memo)
    end
    
    return memo[i][j] = [lcs(s1, s2, i, j-1, memo), lcs(s1, s2, i-1, j, memo)].max
    
end


def min_insertions(s)
    n = s.length
    memo = Array.new(n+1) { Array.new(n+1, -1) }
    s1 = s
    s2 = s.reverse
    puts(s2)
    return n - lcs(s1, s2, n, n, memo)
end