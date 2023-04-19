function flatten(mat: number[][]) : Map<number, number[]> {
    let m = new Map<number, number[]>();
    
    for(let i=0;i<mat.length;i++){
        m.set(i, new Array<number>());
        for(let j=0;j<mat[0].length;j++){
            if(mat[i][j] != 0){
                m.get(i)!.push(j);
            }
        }
    }

    return m;
}

function multiply(mat1: number[][], mat2: number[][]): number[][] {
    let m1 = flatten(mat1);
    let m2 = flatten(mat2);
    let ans = Array.from(Array(mat1.length), ()=>(new Array(mat2[0].length).fill(0)));
    
    
    for(let [r1, c] of m1.entries()){
        for(let c1 of c){
            for(let [r2, cs] of m2.entries()){
                for(let c2 of cs){
                    if(c1 == r2){
                        ans[r1][c2] += mat1[r1][c1]*mat2[r2][c2];
                    }
                }
            }
        }
    }
    return ans;
};