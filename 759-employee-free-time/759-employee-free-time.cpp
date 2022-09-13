/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> a) {
        auto cmp = [&](const auto& x, const auto& y){
          return a[x[0]][x[1]].start > a[y[0]][y[1]].start;  
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        
        for(int i=0;i<a.size();i++){
            if(a[i].size()>0) q.push({i, 0});
        }
        
        
        int cur_end = a[q.top()[0]][q.top()[1]].start;
        vector<Interval> res;
        
        while(!q.empty()){
            
            auto f = q.top();
            q.pop();
            
            int i=f[0], j=f[1];
            
            auto x = a[i][j];
            
            if(j+1 < a[i].size()) q.push({i, j+1});
            
            if(cur_end < x.start){
                Interval t;
                t.start= cur_end;
                t.end=x.start;
                res.push_back(t);
            }
            
            cur_end = max(cur_end, x.end);
            
            
        }
        
        return res;
        
        
    }
};