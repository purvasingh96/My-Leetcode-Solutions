class Solution {
public:
    string convertToTitle(int c) {
        string res="";
        vector<char> cache(26, ' ');
        int pos=0;
        for(int i=0;i<26;i++){
            cache[pos++] = (char)(i+65);
        }
        
        while(c > 0){
            c-=1;
            int r = c%26; // 156
            res.push_back(r+'A');
            c = c/26;
        }
        
        //res.push_back(c + 'A');
        reverse(res.begin(), res.end());
        return res;
    }
};