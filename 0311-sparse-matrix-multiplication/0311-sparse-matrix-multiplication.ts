function flatten(mat: number[][]) : Map<number, number[]> {
    let flatMap = new Map<number, number[]>();
    for(let row=0;row<mat.length;row++){
        flatMap.set(row, new Array<number>());
        for(let col=0;col<mat[0].length;col++){
            if(mat[row][col]!=0) flatMap.get(row).push(col);
        }
    }

    return flatMap;
}

function multiply(mat1: number[][], mat2: number[][]): number[][] {
    let fm1 = flatten(mat1);
    let fm2 = flatten(mat2);
    let m1 = mat1.length, n2 = mat2[0].length;
    
    let res = Array.from(Array(m1), ()=> new Array(n2).fill(0));
    
    for(let [row1,cols1] of fm1.entries()){
        for(let col1 of cols1){
            for(let [row2, cols2] of fm2.entries()){
                for(let col2 of cols2){
                    if(col1 == row2){
                        res[row1][col2] += (mat1[row1][col1] * mat2[row2][col2]);
                    }
                }
            }
        }
    }
    
    return res;
    
};