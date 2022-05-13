/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
private:
    bool isCeleb(int c, int n){
        for(int i=0;i<n;i++) {
            if(i==c) continue;
            if(knows(c, i) || !knows(i, c)){
                return false;
            }
        }
        return true;
    }
public:
    int findCelebrity(int n) {
        int celeb=0;
        for(int i=0;i<n;i++) {
            if(knows(celeb, i)) {
                celeb=i;
            }
        }
        
        if(isCeleb(celeb, n)) return celeb;
        return -1;
    }
};