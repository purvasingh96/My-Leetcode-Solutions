# @param {Integer} n
# @return {String[][]}

def isValid(row, col, board)
    n = board.length
    (0..n-1).each do |i|
        if board[i][col] == 'Q'
            return false
        end
        if row-i>=0 && col-i>=0 && board[row-i][col-i]=='Q' 
            return false
        end
        if row-i>=0 && col+i<n && board[row-i][col+i]=='Q'
            return false
        end
        if row+i<n && col-i>=0 && board[row+i][col-i]=='Q'
            return false
        end
        if row+i<n && col+i<n && board[row+i][col+i]=='Q'
            return false
        end 
    end
    return true
end

def backtrack(row, board, ans=[])
    n = board.length
    if row == board.size
        ans << board.map(&:dup)
        return
    end
    
    (0..n-1).each do |col|
        if isValid(row, col, board)
            board[row][col] = 'Q'
            backtrack(row+1, board, ans)
            board[row][col] = '.'
        end
    end
end



def solve_n_queens(n)
    ans = []
    board = []
    (0..n-1).each do |i|
        board << ('.'*n)
    end
    backtrack(0, board, ans)
    ans
end