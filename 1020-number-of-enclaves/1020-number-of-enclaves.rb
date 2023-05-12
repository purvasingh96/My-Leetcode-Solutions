# @param {Integer[][]} grid
# @return {Integer

$dx = [0, 1, 0, -1]
$dy = [1, 0, -1, 0]

def isvalid(x, y, grid)
    return x>=0 && y>=0 && x<grid.size && y<grid[0].size
end

def dfs(x, y, grid)
    grid[x][y]=0
    
    (0..3).each do |k|
        newx = x + $dx[k]
        newy = y + $dy[k]
        if(isvalid(newx, newy, grid) && grid[newx][newy]==1)
            dfs(newx, newy, grid)
        end
    end
end

def num_enclaves(grid)
    ans=0
    m, n = grid.size, grid[0].size
    
    (0..m-1).each do |i|
        if grid[i][0] == 1
            dfs(i, 0, grid)
        end
        
        if grid[i][n-1] == 1
            dfs(i, n-1, grid)
        end
    end
    
    (0..n-1).each do |j|
        if grid[0][j] == 1
            dfs(0, j, grid)
        end
        
        if grid[m-1][j] == 1
            dfs(m-1, j, grid)
        end
    end
    
    (0..m-1).each do |i|
        (0..n-1).each do |j|
            if grid[i][j]==1
                ans+=1
            end
        end
    end
    
    ans
    
end