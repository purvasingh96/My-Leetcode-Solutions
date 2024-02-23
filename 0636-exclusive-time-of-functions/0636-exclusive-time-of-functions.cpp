class Solution {
private:
    vector<string> split(string s){
        string res="";
        vector<string> ans;
        for(int i=0;i<s.length();i++){
            if(s[i]==':'){
                ans.push_back(res);
                res = "";
            } else {
                res += s[i];
            }
        }
        ans.push_back(res);
        return ans;
    }
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n, 0);
        int prevTime=0;
        
        for(int i=0;i<logs.size();i++){
            vector<string> data = split(logs[i]);
            int idx = stoi(data[0]);
            string op = data[1];
            int currTime = stoi(data[2]);
            
            if(op == "start"){
                int top = st.empty() ? idx:st.top();
                ans[top] += currTime - prevTime;
                prevTime = currTime;
                st.push(idx);
            } else {
                st.pop();
                ans[idx] += currTime - prevTime+1;
                prevTime = currTime+1;
            }
            
        }
        
        return ans;
    }
};