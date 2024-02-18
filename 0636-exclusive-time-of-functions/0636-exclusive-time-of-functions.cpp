class Solution {
private:
    vector<string> split(string s){
        string res = "";
        vector<string> ans;
        
        for(auto c:s){
            if(c!=':'){
                res += c;
            } else {
                ans.push_back(res);
                res="";
            }
        }
        ans.push_back(res);
        return ans;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
       vector<int> res(n, 0);
        int prev_time=0;
        stack<int> st;
        
        for(auto l:logs){
            auto temp = split(l);
            int idx = stoi(temp[0]);
            string op = temp[1];
            int time = stoi(temp[2]);
            
            if(op == "start"){
                if(!st.empty()){
                    res[st.top()] += (time - prev_time);
                }
               st.push(idx);
                prev_time = time;
            } else {
                res[idx] += (time - prev_time+1);
                st.pop();
                prev_time = time+1;
            }
        }
        
        return res;
            
    }
};