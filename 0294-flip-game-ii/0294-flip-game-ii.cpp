class Solution {

public:
    bool canWin(string s) {
        int n = s.length();
        if(n==0 || n<2) return false;
        
        for(int i=0;i<n-1;i++){
            if(s.substr(i, 2) == "++"){
                string next = s.substr(0, i) + "--" + s.substr(i+2);
                if(!canWin(next)) return true;
            }
        }
        
        return false;
    }
};