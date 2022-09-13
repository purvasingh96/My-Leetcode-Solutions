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
        // linesweep
        vector<Interval> ans;
        map<int, int> dp;
        for(auto x:schedule){
            for(auto y:x){
                dp[y.start]+=1;
                dp[y.end]-=1;
            }
        }
        
        int res=0;
        int start=-1;
        
        for(auto x:dp){
            res+=x.second;
            if(res==0 && start==-1){
                start = x.first;
            } 
            
            else if(start!=-1 && res!=0){
                Interval t;
                t.start = start;
                t.end = x.first;
                ans.push_back(t);
                start=-1;
            }
        }
        
        return ans;
        
    }
};