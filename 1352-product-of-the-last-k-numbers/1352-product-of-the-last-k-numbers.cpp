class ProductOfNumbers {
private:
    vector<long long> prod;
    int n;
   int lastZeroPos;
   int mod=1e9+7;

public:
    ProductOfNumbers() {
        n=0;
    }
    
    void add(int num) {
        if(num==0) {
            lastZeroPos=n;
            prod.push_back(1);
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
        
        if(n-k <= lastZeroPos) return 0;
        
        if(k>=n) {
            return prod.back();
        }
        return prod.back()/prod[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */