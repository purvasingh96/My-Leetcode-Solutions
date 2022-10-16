class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if(s.length()==1) return -1;
        int i=s.length()-2;
        
        while(i >= 0){
            bool found=false;
            while(i>=0 && s[i]-'0'>=s[i+1]-'0'){
                i-=1;
            }

            if(i<0) return -1;

            int j=s.length()-1;
            while(j>i && s[j]-'0' <= s[i]-'0'){
                j-=1;
            }
            
            cout<<"i: "<<i<<" j: "<<j<<"\n";
            
            if(j!=i){
                swap(s[i], s[j]);
                sort(s.begin()+i+1, s.end());
                found=true;
                break;
            }
            
            //cout<<"found: "<<found<<"\n";
            if(found) break;
        }
        
        if(i<0){
            swap(s[0], s[s.length()-1]);
            sort(s.begin()+1, s.end());
        }
        
        cout<<s;
        //return 0;
        if(stoll(s) > INT_MAX) return -1;
        return stoi(s);
        
    }
};