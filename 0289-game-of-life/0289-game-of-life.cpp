class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
		// size of board (m * n)
        int m = board.size(), n = board[0].size(), cnt;
		// vectors X & Y is used to visit all 8 neighbour.
        vector<int> X{-1, 0, 1}, Y{-1, 0, 1};
		// Iterating over board from top to down & left to right
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
				// store count of alive neighbour.
                cnt = 0;
				// while using X & Y vectors to visit all neighbour we also visit our current cell & if it is alive it will be counted so decrementing cnt.
                if(board[i][j] == 1)
                    cnt--;
				// using X & Y to visit all neighbour 
				// [i - 1, j - 1][i - 1, j + 0][i - 1, j + 1][i + 0, j - 1][i + 0, j + 0][i + 0, j + 1][i + 1, j - 1][i + 1, j + 0][i + 1, j + 1]
                for(auto x : X)
                {
                    for(auto y : Y)
                    {
						if(i + x >= 0 && j + y >= 0 && i + x <= m - 1 && j + y <= n - 1)
                        {
							// since board is changing simultaneously I am coding the state of the cell so when i am visiting them as neighbour of other cell i should know what was their previous value (i.e. in starting state).
							// 0 -> 0 = -1 if original value is 0 & new value is 0 then representing it with -1
							// 0 -> 1 = -2 if original value is 0 & new value is 1 then representing it with -2
							// 1 -> 0 = -3 if original value is 1 & new value is 0 then representing it with -3
							// 1 -> 1 = -4 if original value is 1 & new value is 1 then representing it with -4
							// in case of -3 & -4 the original value of cell was 1 & we have to consider them while counting alive neighbour, & 1 represent unvisited neighbour (i.e. neighbour who is situated in right side & bottom of current cell).
							if(board[i + x][j + y] == 1 || board[i + x][j + y] == -3 || board[i + x][j + y] == -4)
                                cnt++;
                        }
                    }
                }
				// if less than 2 or greater than 3 neighbours are alive then current cell dies.
				if(cnt < 2 || cnt > 3)
					// coding state so i can know the previous value (i.e. before i visited them)
                    board[i][j] == 0 ? board[i][j] = -1 : board[i][j] = -3;
				// if 2 neighbours are alive then current cell stays alive.
                else if(cnt == 2)
                    board[i][j] == 0 ? board[i][j] = -1 : board[i][j] = -4;
				// if exactly 3 neighbour are alive than currenct cell come back to life.
                else if(cnt == 3)
                    board[i][j] == 0 ? board[i][j] = -2 : board[i][j] = -4;
            }
        }
		// assigning new values to the cell based on our coding scheme.
		for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j] == -2)
                    board[i][j] = 1;
                else if(board[i][j] == -3)
                    board[i][j] = 0;
                else
                    board[i][j] = 1;
            }
        } 
    }
};