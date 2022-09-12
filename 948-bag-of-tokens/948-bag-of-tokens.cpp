class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        
        if(n==0 || power<tokens[0]) return 0;
        
        int maxscore=0;
        int score=0;
        
        int left=0, right=tokens.size()-1;
        
        while(left<n && right>=0){
            
            if(tokens[left]==INT_MAX && tokens[right]==INT_MAX) break;
            
            while(left<n && tokens[left]!=INT_MAX && power>=tokens[left]){
                score+=1;
                power-=tokens[left];
                tokens[left] =INT_MAX;
                left+=1;
            }
            
            maxscore= max(maxscore, score);
            
            if(score>=1) {
                if(tokens[right]!=INT_MAX) power += tokens[right];
                tokens[right]=INT_MAX;
                right-=1;
                score-=1;
            }
            
        }
        
        return maxscore;
        
    }
};