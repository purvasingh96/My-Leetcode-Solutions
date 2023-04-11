class ProductOfNumbers {
    private n: number;
    private prod: number[];
    private lzp: number;
    private mod: number;
    
    constructor() {
        this.n=0;
        this.mod=1e9+7;
        this.prod = [];
    }

    add(num: number): void {
        if(num==0) {
            this.prod.push(1);
            this.lzp=this.n;
        } else {
            if(this.prod.length==0){
                this.prod.push(num);
            } else {
                let p: number = this.prod[this.n-1]*num;
                this.prod.push(p%this.mod);
            }
        }
        this.n+=1;
    }

    getProduct(k: number): number {
        if(this.n-k <= this.lzp) return 0;
        if(k>=this.n) return this.prod[this.n-1];
        return this.prod[this.n-1]/this.prod[this.n-k-1];
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * var obj = new ProductOfNumbers()
 * obj.add(num)
 * var param_2 = obj.getProduct(k)
 */