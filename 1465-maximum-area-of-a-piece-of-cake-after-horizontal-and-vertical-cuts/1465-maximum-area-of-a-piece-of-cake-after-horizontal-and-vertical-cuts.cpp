class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(0);
        hc.push_back(h);
        vc.push_back(0);
        vc.push_back(w);
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int mh=0, mv=0;
        
        for(int i=1;i<hc.size();i++){
            mh = max(mh, (hc[i]-hc[i-1]));
        }
        //cout<<"ere";
        
        for(int j=1;j<vc.size();j++){
            //cout<<j<<" ";
            mv = max(mv, (vc[j]-vc[j-1]));
        }
        //cout<<"ere";
        return (1LL*mh*mv) % 1000000007;;
        
    }
};