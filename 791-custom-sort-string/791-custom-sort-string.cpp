class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> m;
        map<char, int> n;
        string res="";
        //for(auto x:order) m[x] +=1;
        
        for(auto x:s) n[x] +=1;
        
        for(auto x:order) {
            
            if(n.find(x)!=n.end()) {
                while(n[x]) {
                    res += x;
                    n[x] -=1;
                }
            }
            
        }
        
        for(auto it:n) {
            if(it.second != 0) {
                int size = it.second;
                while(size--) {
                    res += it.first;
                }
            }
        }
        
        return res;
        
    }
};