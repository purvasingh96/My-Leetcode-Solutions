class Solution {
private:
    vector<string> split(string s){
        string res="";
        vector<string> ans;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == ':'){
                ans.push_back(res);
                res="";
            }
            else {
                res += s[i];
            }
        }
        
        if(res!=""){
            ans.push_back(res);
        }
        
        return ans;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n, 0);
        int prev_time = 0;
        
        for(auto l:logs){
            vector<string> x = split(l);
            int idx = stoi(x[0]);
            int curr_time = stoi(x[2]);
            string op = x[1];
            
            if(op == "start"){
                int j = st.empty() ? idx : st.top();
                ans[j] += curr_time - prev_time;
                prev_time = curr_time;
                st.push(idx);
            } else {
                ans[idx] += curr_time-prev_time+1;
                prev_time = curr_time+1;
                st.pop();
            }
        }
        return ans;
    }
};