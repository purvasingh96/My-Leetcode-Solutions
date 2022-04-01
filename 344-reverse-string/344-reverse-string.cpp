class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0, right=s.size()-1;
        
        while(left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right]=t;
            left+=1;
            right-=1;
        }
        
        
        
    }
};