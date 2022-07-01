class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(), b.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
        });
        
        int ans=0;
        int i=0;
        
        while(i<b.size() && t>0){
            
            int freq = b[i][0];
            int cost = b[i][1];
            
            while(freq>0 && t>0){
                ans += cost;
                freq-=1;
                t-=1;
            }
            
            i+=1;
            
        }
        return ans;
        
    }
};