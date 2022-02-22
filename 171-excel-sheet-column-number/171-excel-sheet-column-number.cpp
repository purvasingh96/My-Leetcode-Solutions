class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int power=0;
        int ans = 0;
        
        for(int i=columnTitle.length()-1;i>=0;i--) {
            
            int num = (columnTitle[i] - 'A')+1;
            
            ans += (pow(26, power) * num);
            power += 1;
            
        }
        
        return ans;
        
        
    }
};