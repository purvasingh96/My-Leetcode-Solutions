class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        int sum=0;
        for(auto c:ops) {
            
            if(c!="+" && c!="D" && c!="C") {
                //cout<<c<<"\n";
                sum += stoi(c);
                st.push_back(stoi(c));
                
            } else if(c=="+") {
                int n = st.size();
                int x = st[n-1];
                int y = st[n-2];
                sum += (x+y);
                st.push_back((x+y));
                
            } else if(c == "C") {
                sum -= st.back();
                st.pop_back();
                
            } else if(c=="D") {
                int x = st.back();
                sum += (2*x);
                st.push_back(2*x);
            }
            
           
            
        }
         return sum; //accumulate(st.begin(), st.end(), 0);
        
    }
};