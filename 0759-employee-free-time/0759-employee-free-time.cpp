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
    vector<Interval> employeeFreeTime(vector<vector<Interval>> s) {
        map<int, int> m;
        vector<Interval> res;
        for(int i=0;i<s.size();i++){
            for(auto x:s[i]){
                m[x.start]+=1;
                m[x.end] -= 1;
            }
        }
        
        int start=-1, score=0;
        for(auto it:m){
            score += it.second;
            if(start==-1 && score==0){
                start=it.first;
            } 
            
            if(start!=-1 && score!=0){
                Interval x(start, it.first);
                res.push_back(x);
                start=-1;
            }
        }
        
        return res;
        
        
        
        
        
        
        
    }
};