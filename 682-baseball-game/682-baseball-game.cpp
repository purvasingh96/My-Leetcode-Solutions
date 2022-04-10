class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        
        for(auto c:ops) {
            
            if(c!="+" && c!="D" && c!="C") {
                //cout<<c<<"\n";
                st.push_back(stoi(c));
                
            } else if(c=="+") {
                int n = st.size();
                int x = st[n-1];
                int y = st[n-2];
                
                st.push_back((x+y));
                
            } else if(c == "C") {
                st.pop_back();
            } else if(c=="D") {
                int x = st.back();
                st.push_back(2*x);
            }
            
           
            
        }
         return accumulate(st.begin(), st.end(), 0);
        
    }
};