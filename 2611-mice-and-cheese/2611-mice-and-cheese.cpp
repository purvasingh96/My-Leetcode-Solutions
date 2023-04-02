class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        vector<vector<int>> a1;
        vector<vector<int>> a2;
        int n = r1.size();
        
        for(int i=0;i<n;i++){
            a1.push_back({r1[i], r2[i], i});
            a2.push_back({r2[i], i});
        }
        
        sort(a1.begin(), a1.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        
        sort(a2.begin(), a2.end());
        vector<bool> visited(n, false);
        int ans=0;
        
        while(k--){
            ans += a1.back()[0];
            visited[a1.back()[2]] = true;
            a1.pop_back();
        }
        
        while(a2.size()!=0){
            if(!visited[a2.back()[1]]) ans+= a2.back()[0];
            a2.pop_back();
        }
        
        return ans;
        
    }
};