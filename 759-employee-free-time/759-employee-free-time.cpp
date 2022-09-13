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
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        
        for(auto e:schedule){
            for(auto x:e){
                res.push_back(x);
            }
        }
        
        
        sort(res.begin(), res.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });
        
        vector<Interval> not_free;
        vector<Interval> free;
        
        for(auto e:res) {
            
            if(not_free.size() == 0 || not_free.back().end <= e.start) {
                not_free.push_back(e);
            } else {
                int new_start = min(not_free.back().start, e.start);
                int new_end = max(not_free.back().end, e.end);
                
                Interval temp;
                temp.start = new_start;
                temp.end = new_end;
                
                not_free.pop_back();
                not_free.push_back(temp);
                                    
            }
            
        }
        
        
        for(int i=1;i<not_free.size();i++){
            
            auto x = not_free[i-1], y=not_free[i];
            
            if(y.start > x.end){
                Interval temp;
                temp.start = x.end;
                temp.end = y.start;
                free.push_back(temp);
            }
            
        }
        
        return free;
        
    }
};