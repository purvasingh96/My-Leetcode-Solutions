class Solution {
public:
    int minimumKeypresses(string s) {
        if(s.length() <= 9) return s.length();
        int ans=0;
        unordered_map<int, int> m;
        vector<int> y(26, -1);
        for(int i=1;i<=9;i++){
            m[i] = 0;
        }
        
        unordered_map<char, int> l;
        vector<pair<char, int>> temp;
        for(auto x:s) l[x]+=1;
        for(auto y:l) {
            temp.push_back({y.first, y.second});
        }
        
        sort(temp.begin(), temp.end(), [](const pair<char, int>& a, const pair<char, int>& b){
            return a.second > b.second;
        });
        
        int pos=1;
        
        for(int i=0;i<temp.size();i++){
            char c = temp[i].first;
            int count = temp[i].second;
            
            m[pos%9] +=1;
            ans += (m[pos%9]*count);
            pos+=1;
            
        }
        
        
        
        return ans;
        
    }
};