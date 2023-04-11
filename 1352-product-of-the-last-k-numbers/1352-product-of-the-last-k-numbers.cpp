class ProductOfNumbers {
private:
    vector<long long> prod;
    int n;
    vector<int> zeroPositions;
    int mod = 1e9+7;
    vector<int> res;

public:
    ProductOfNumbers() {
        n=0;
    }
    
    void add(int num) {
        //res.push_back(num);
        if(num==0) {
            zeroPositions.push_back(n);
            prod.push_back(1);
            //else prod.push_back(prod.back());
        }
        else {
            if(prod.size()==0) prod.push_back(num);
            else {
                long long p = ((num)*(prod.back()))%mod;
                prod.push_back(p);
            }
            
        }
        
        n+=1;
    }
    
    int getProduct(int k) {
        //cout<<"get Prod of last "<<k<<" digits: ";
        //for(auto x: res) cout<<x<<" ";
        //cout<<"\n";
        int target = n-k;
        int sz = zeroPositions.size();
        int idx = lower_bound(zeroPositions.begin(), zeroPositions.end(), target) - zeroPositions.begin();
        
        if(idx < sz) return 0;
        if(k>=n) {
            //cout<<"prod is: "<<prod.back()<<"\n";
            return prod.back();
        }
        //cout<<"prod is: "<<prod.back()/prod[n-k-1]<<"\n";
        return prod.back()/prod[n-k-1];
        //return k>=n?prod.back()%mod:(prod.back()%mod/prod[n-k-1]%mod)%mod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */