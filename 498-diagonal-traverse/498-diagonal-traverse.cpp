class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        /*
        moving_up_right= true
        count = 1;
        if(moving_up_right):
            if j == n-1:
                i++
                moving_up_right = false
            else if j==0:
                j++;
                moving_up_right = false
            else:
                i++
                j--
        
        else:
            if i== m-1:
                j++;
                moving_up_right = true;
            else if j == 0:
                i++;
                moving_up_right = true;
            else:
                i++
                j--
                
        res[count++] = mat[i][j]
        */
        
        int m=mat.size(), n = mat[0].size();
        
        int i=0, j=0, count=1;
        vector<int> res(m*n);
        bool moveUpRight = true;
        
        res[0] = mat[0][0];
        
        while(i!=m-1 || j!=n-1) {
            
            if(moveUpRight) {
                
                if(j == n-1)  {
                    i+=1;
                    moveUpRight = false;
                } else if(i == 0) {
                    j+=1;
                    moveUpRight = false;
                } else {
                    i-=1;
                    j+=1;
                }
                 
            } else {
                
                if(i == m-1) {
                    j+=1;
                    moveUpRight=true;
                } else if(j == 0) {
                    i+=1;
                    moveUpRight = true;
                } else {
                    i+=1;
                    j-=1;
                }
                
            }
            
            res[count++] = mat[i][j];
         
            
        }
        
        return res;
        
    }
};