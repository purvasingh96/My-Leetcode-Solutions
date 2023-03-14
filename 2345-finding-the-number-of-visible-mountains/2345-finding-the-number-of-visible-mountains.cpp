class Solution {
private:
    bool isWithin(vector<int>& a, vector<int>& b){
        int x1 = a[0], y1=a[1];
        int x2=b[0], y2=b[1];
        
        return (y2 <= x2 + (y1-x1)) && (y2<= -x2 + (y1+x1));
    }
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        sort(peaks.begin(), peaks.end());
        map<vector<int>, int> m;
        for(auto x:peaks) m[x]+=1;
        
        deque<vector<int>> q;
        
        for(int i=0;i<peaks.size();i++){
            
            while(!q.empty() && isWithin(peaks[i], q.back())){
                q.pop_back();
            }
            
            if(q.empty() || !isWithin(q.back(), peaks[i])){
                q.push_back(peaks[i]);
            }
            
        }
        
        int ans=0;
        while(!q.empty()){
            auto f = q.front();
            q.pop_back();
            ans += m[f]==1?1:0;
        }
        
        return ans;
    }
};