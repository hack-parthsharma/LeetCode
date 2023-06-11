/**
 * @param {Function} fn
 */
function memoize(fn) {
    let callcount=0;
    let Mp=new Map();
    return function(...args) {
           let key;
            key=`${args[0]}`;   
           if(args.length==2)
           {
              key+="+"+`${args[1]}`;
           }
           if(Mp.has(key))
           {
              return Mp.get(key);  
           }
           callcount+=1;
           let res=fn(...args);  
           Mp.set(key,res);
           return res;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
