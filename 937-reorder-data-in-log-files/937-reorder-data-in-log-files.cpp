class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
       vector<string> letter, digit;
        
        for(auto s:logs){
            if(s.back() >= 'a' && s.back() <= 'z') letter.push_back(s);
            else digit.push_back(s);
        }
        
        sort(letter.begin(), letter.end(), [](const string& a, const string& b){
            int pos_a = a.find(" ");
            string a_right = a.substr(pos_a+1);
            string a_left = a.substr(0, pos_a);
            
            int pos_b = b.find(" ");
            string b_right = b.substr(pos_b+1);
            string b_left= b.substr(0, pos_b);
            
            if(a_right!=b_right) return a_right < b_right;
            return a_left < b_left;
        });
        
        letter.insert(letter.end(), digit.begin(), digit.end());
        return letter;
        
    }
};