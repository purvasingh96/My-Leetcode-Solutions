class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // O(NlogN)
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        
        if(n==0 || power<tokens[0]) return 0;
        
        int maxscore=0;
        int score=0;
        
        int left=0, right=tokens.size()-1;
        
        while(left<=right){
            
            while(left<n && power>=tokens[left]){
                score+=1;
                power-=tokens[left++];
            }
            
            maxscore= max(maxscore, score);
            
            if(score>=1) {
                power += tokens[right--];
                score-=1;
            }
            
        }
        
        return maxscore;
        
    }
};