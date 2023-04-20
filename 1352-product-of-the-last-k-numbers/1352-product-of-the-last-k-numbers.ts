class ProductOfNumbers {
    private lzp: number;
    private prod: number[];
    private mod: number;
    private sz: number;
    constructor() {
        this.lzp=-1;
        this.mod = 1e9+7;
        this.prod = [];
        this.sz=0;
    }

    add(num: number): void {
        if(num == 0) {
            this.lzp = this.sz;
            this.prod.push(1);
        }
        else {
            if(this.prod.length==0) this.prod.push(num%this.mod);
        else {
                let p = this.prod[this.sz-1] * num;
                p = p%this.mod;
                this.prod.push(p);
            }
        }
        this.sz+=1;
        //console.log(this.prod);
    }

    getProduct(k: number): number {
        if(this.sz - k <= this.lzp) return 0;
        if(k  >= this.sz) return this.prod[this.prod.length-1];
        
        return this.prod[this.sz-1]/this.prod[this.sz - k-1];
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * var obj = new ProductOfNumbers()
 * obj.add(num)
 * var param_2 = obj.getProduct(k)
 */