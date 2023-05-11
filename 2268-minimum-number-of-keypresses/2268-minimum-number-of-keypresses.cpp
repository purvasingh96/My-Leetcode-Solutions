class Solution {
public:
    int minimumKeypresses(string s) {
        if(s.length() <= 9) return s.length();
        int ans=0;
        vector<int> m(10, 0);
        vector<int> y(26, -1);
        vector<int> l(26, 0);
        
        vector<int> temp;
        
        for(auto x:s) l[x-'a']+=1;
        for(auto y:l) {
            if(y!=0) temp.push_back(y);
        }
        
        sort(temp.begin(), temp.end(), [](const int& a, const int& b){
            return a > b;
        });
        
        int pos=1;
        
        for(int i=0;i<temp.size();i++){
            int count = temp[i];
            
            m[pos%9] +=1;
            ans += (m[pos%9]*count);
            pos+=1;
            
        }
        
        
        
        return ans;
        
    }
};