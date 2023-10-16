class Solution {
public:
    bool winnerOfGame(string colors) {
        int movesB=0, movesA=0;
        int cb=0, ca=0;
        int n = colors.size();
        int start=0;
        
        while(start<n){
            int end=start+1;
            while(end<n && colors[end]==colors[end-1]){
                end+=1;
            }
            int moves = max(end-start-2, 0);
            colors[start]=='A' ? (movesA += moves) : (movesB += moves);
            start=end;
        }
        
        return movesA > movesB;
    }
};