# @param {Integer[][]} matrix
# @return {Void} Do not return anything, modify matrix in-place instead.
def rotate(matrix)
    m2 = matrix.transpose.map {|row| row.reverse!}
    
    matrix.map.with_index{ |row, i|
        row.map.with_index { |val, j|
            matrix[i][j] = m2[i][j]
        }
        
    }
    
end