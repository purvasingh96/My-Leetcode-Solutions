class Solution {
public:
    bool isPowerOfThree(int n) {
        vector<int> pows;
        
        for(int i=0;pow(3,i)<=n;i++){
            pows.push_back(pow(3, i));
        }
        
        return find(pows.begin(), pows.end(), n)!=pows.end();
    }
};