/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const myMap = new Map();
    return function(...args) {
        const key = args.toString();

        if(myMap.has(key))
        return myMap.get(key);

        let val = fn(...args);
        myMap.set(key,val);

        return val;
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
