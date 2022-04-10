class Solution {
public:
    int maximumSwap(int num) {
        map<int, vector<int>> m;
        
        string original = to_string(num);
        
        for(int i=0;i<original.length();i++) {
            m[original[i] - '0'].push_back(i);
        }
        int idx=0;
        
        //cout<<"===\n";
        map<int, vector<int>>::reverse_iterator it;
        
        for(auto it=m.rbegin();it!=m.rend();it++) {
            
            int n = it->second.size();
            
            while(n>0) {
                //cout<<"n: "<<n<<" it.first "<<it->first<<" original[idx]: "<<original[idx]<<"\n";
                
                if(it->first!=original[idx]-'0') {
                        //cout<<"not qual"<<it->first<<" "<<original[idx];
                        char t = original[idx];
                        original[idx] = it->first + '0';
                        original[it->second.back()] = t;
                        return stoi(original);
                }
                
                n-=1;
                idx += 1;
            }
            
            
            
        }
        return stoi(original);
    }
};