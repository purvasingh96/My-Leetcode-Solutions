class Solution {
public:
    void modifyMap(map<char, int>& m, vector<int>& res, int count, int digit, string word) {
                    int temp = count;
                    while(temp!=0) {
                        res.push_back(digit);
                        temp-=1;
                    }
                    
                    for(auto c:word) {
                        m[c] -= count;
                        if(m[c] == 0) m.erase(c);
                    }
            
            
    }
    
    string originalDigits(string s) {
        map<char, int> m;
        vector<int> res;
        string alpha = "egfihonsrutwvxz";
        
        for(auto c:alpha) {
            m[c] = 0;
        }
        
        for(auto c:s) {
            m[c]+=1;
        }
        
        vector<char> first_pass = {'z', 'w', 'u', 'x', 'g'};
        
        for(auto c:first_pass) {
            int count = m[c];
            if(count!=0) {
                
                if (c == 'z')      modifyMap(m, res, count, 0, "zero");
                else if (c == 'w')  modifyMap(m, res, count, 2, "two");
                else if (c == 'u') modifyMap(m, res, count, 4, "four");
                else if (c == 'x') modifyMap(m, res, count, 6, "six");
                else if(c == 'g') modifyMap(m, res, count, 8, "eight");
                
            }
            
        }
        
        vector<char> second_pass = {'h', 'f', 'o', 's', 'n'};
        
        for(auto c: second_pass) {
            
            int count = m[c];
            if(count != 0) {
                
                if(c == 'h') modifyMap(m, res, count, 3, "three");
                else if(c == 'f') modifyMap(m, res, count, 5, "five");
                else if(c == 'o') modifyMap(m, res, count, 1, "one");
                else if(c == 's') modifyMap(m, res, count, 7, "seven");
                else if(c == 'n') modifyMap(m, res, count/2, 9, "nine");
            }
        }
        
        string final_res = "";
        sort(res.begin(), res.end());
        
        for(auto c : res) {
            final_res += to_string(c);
        }
        
        return final_res;
        
    }
};
