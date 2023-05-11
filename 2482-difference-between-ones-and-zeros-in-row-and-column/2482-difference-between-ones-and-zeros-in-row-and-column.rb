# @param {Integer[][]} grid
# @return {Integer[][]}
def ones_minus_zeros(grid)
    m = grid.size
    n = grid[0].size
    diff = []
    
    one_rows = (grid.map {|row| row.sum})
    one_cols = (grid.transpose.map {|col| col.sum})
    
    (0..m-1).each do |i|
        row = []
        (0..n-1).each {|j| row<<(2*(one_rows[i] + one_cols[j]) - (m+n))}
        diff << row
    end
    diff
end