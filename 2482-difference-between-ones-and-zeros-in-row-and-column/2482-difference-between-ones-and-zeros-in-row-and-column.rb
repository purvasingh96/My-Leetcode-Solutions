# @param {Integer[][]} grid
# @return {Integer[][]}
def ones_minus_zeros(grid)
    m = grid.size
    n = grid[0].size
    diff = []
    
    one_rows = (grid.map {|row| row.sum})
    one_cols = (grid.transpose.map {|col| col.sum})
    
    puts(one_rows)
    puts("doen")
    
    (0..m-1).each do |i|
        row = []
        #puts("i: ", i)
        (0..n-1).each do |j|
            row<<(2*(one_rows[i] + one_cols[j]) - (m+n))
        end
        
        diff << row
    end
    diff
end