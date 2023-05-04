class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r;
        queue<int> d;
        int n = senate.size();
        
        for(int i=0;i<senate.size();i++){
            if(senate[i] == 'R'){
                r.push(i);
            } else{
                d.push(i);
            }
        }
        
        
                
        // round 2
        while(!r.empty() && !d.empty()){
            if(d.front() < r.front()){
                r.pop();
                
                int t = d.front();
                d.pop();
                d.push(t+n);
            } else if(r.front() < d.front()){
               
                d.pop();
                int t = r.front();
                r.pop();
                r.push(t+n);
            }
        }
        
        if(d.empty()) return "Radiant";
        return "Dire";
    }
};