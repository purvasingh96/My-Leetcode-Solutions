class Solution {
public:
//     string removeDuplicates(string s, int k) {
//         stack<pair<char, int>> st;
        
//         int i=0;
        
//         while(i<s.length()) {
            
//             if(st.empty() || s[i]!=st.top().first)  {
//                 st.push(make_pair(s[i], 1));
//                 i+=1;
//             } else{
                
//                 auto curr = st.top();
                
//                 if(curr.second+1 == k) {
//                     st.pop();
//                 } else{
//                     st.pop();
//                     st.push(make_pair(curr.first, curr.second+1));
                    
                    
//                 }
                    
//                 i+=1;
                
//             }
            
//         }
        
//         string res="";
        
//         while(!st.empty()) {
//             auto x = st.top();
//             st.pop();
//             res += string(x.second, x.first);
//         }
        
        
//         reverse(res.begin(), res.end());
//         return res;
        
        
//     }

    string removeDuplicates(string s, int k) {
  vector<pair<char, short>> st;
  string res;
  for (auto ch : s) {
    if (st.empty() || st.back().first != ch) st.push_back({ ch, 0 });
    if (++st.back().second == k) st.pop_back();
  }
  for (auto& p : st) res += string(p.second, p.first);
  return res;
}
};