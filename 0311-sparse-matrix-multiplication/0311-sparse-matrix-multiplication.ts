function flatten(mat: number[][]){
    let m = new Map<number, number[]>();
    let k: number = mat.length;
    let n: number = mat[0].length;
    
    for(let i=0;i<k;i++){
        m.set(i, new Array<number>());
        for(let j=0;j<n;j++){
            if(mat[i][j]!=0){
                m.get(i)!.push(j);
            }
        }
    }
    
    return m;
}


function multiply(mat1: number[][], mat2: number[][]): number[][] {

    let res = [];
    let m: number = mat1.length;
    let n: number = mat1[0].length;
    let k: number = mat2[0].length;
    
    // m X k
    for(let i=0;i<m;i++){
        res.push(new Array<number>(k));
    }
    
    
    
    for(let i=0;i<m;i++){
        for(let j=0;j<k;j++){
            res[i][j] = 0;
        }
    }
    
    
    let a = flatten(mat1);
    let b = flatten(mat2);

    
    for(let row1 of a.keys()){
        for(let col1 of a.get(row1)){
            for(let row2 of b.keys()){
                for(let col2 of b.get(row2)){
                    
                    if(col1 == row2){
                        res[row1][col2] += mat1[row1][col1]*mat2[row2][col2];
                    }
                    
                }
            }
        }
    }
    
    return res;
    
    
    
};