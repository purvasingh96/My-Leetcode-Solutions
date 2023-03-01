
class Solution {
private:
    bool within(vector<int>& a, vector<int>& b){
        int x1 = a[0], y1=a[1];
        int x2=b[0], y2=b[1];
        int diff1 = (y1-x1);
        int diff2 = (y1+x1);
        
        return y2 <= x2 + diff1 and y2 <= -x2 + diff2;
    }
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        
        map<vector<int>, int> m;
        for(auto x:peaks){
            m[x]+=1;
        }
        
        
        sort(peaks.begin(), peaks.end());
        int n = peaks.size();
        deque<vector<int>> q;
        
        for(int i=0;i<peaks.size();i++){
            
            while(!q.empty() && within(peaks[i], q.back())){
                q.pop_back();
            }
            if(q.empty() || !within(q.back(), peaks[i])){
                q.push_back(peaks[i]);
            }
        }
        
        cout<<q.size();
        
        int ans=0;
        while(!q.empty()){
            auto f =q.front();
            q.pop_front();
            ans += m[f]==1?1:0;
        }
        return ans;
    }
};