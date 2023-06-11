Array.prototype.snail = function(rowsCount, colsCount) {
    var arr = [];
    var n = rowsCount*colsCount;
    if(n != this.length) return arr;
    for(var i = 0;i< rowsCount;i++) arr[i] = [];
    
    for(var k=0, i = 0, j = 0, d=1; k<n; i+=d){
        if(i<0 || i== rowsCount){
            d = -1*d;
            j++;
            continue;
        }
        arr[i][j] = this[k++];
    }
    return arr;
}