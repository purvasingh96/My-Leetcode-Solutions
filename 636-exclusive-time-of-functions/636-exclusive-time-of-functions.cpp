struct Log{
    int id;
    string status;
    int time;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        stack<Log> st;
        vector<int> res(n, 0);
        
        for(auto log:logs) {
            stringstream ss(log);
            string temp1, temp2, temp3;
            
            getline(ss, temp1, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');
            
            Log item = {stoi(temp1), temp2, stoi(temp3)};
            
            
            if(item.status == "start") {
                st.push(item);
            } else{
                
                int time_add = item.time - st.top().time +1;
                
                res[item.id] += time_add;
                
                st.pop();
                
                if(!st.empty() && st.top().status == "start") {
                    //cout<<"here";
                    res[st.top().id] -= time_add;
                    
                }
                
                
            }
        }
        
        return res;
        
    }
};