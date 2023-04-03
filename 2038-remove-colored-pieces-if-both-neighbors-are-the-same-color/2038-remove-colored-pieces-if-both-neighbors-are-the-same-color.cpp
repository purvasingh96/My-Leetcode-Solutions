class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.length() < 3) return false;
        
        int ca=0, cb=0;
        int l=3;
        string s = colors.substr(0, 3);
        if(s == "AAA") ca+=1;
        else if(s=="BBB") cb+=1;
        
        while(l<colors.length()){
            s.push_back(colors[l]);
            s.erase(s.begin());
            
            if(s == "AAA") ca+=1;
            else if(s == "BBB") cb+=1;
            l+=1;
        }
        //cout<<ca<<" "<<cb;
        
        return ca > cb;
        
    }
};