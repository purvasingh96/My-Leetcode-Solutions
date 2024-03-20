class Solution {
private:
    vector<string> split(string log){
        string res="";
        log+=':';
        vector<string> ans;
        for(int i=0;i<log.length();i++){
            if(log[i] == ':'){
                ans.push_back(res);
                res="";
            } else{
                res += log[i];
            }
        }
        return ans;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n, 0);
        int pt=0;
        
        for(auto log:logs){
            vector<string> temp = split(log);
            int i = stoi(temp[0]);
            string op = temp[1];
            int ct = stoi(temp[2]);
            if(op == "start"){
                if(st.empty()){
                    st.push(i);
                } else {
                    ans[st.top()] += ct-pt;
                    pt = ct;
                    st.push(i);
                }
            } else {
                int top = st.top();
                st.pop();
                ans[top] += (ct -pt+1);
                pt = ct+1;
            }
        }
        
        return ans;
        
    }
};