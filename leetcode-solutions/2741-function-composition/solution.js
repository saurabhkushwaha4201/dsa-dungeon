/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    let n = functions.length;
    return function(x) {
        // for(let i = n-1;i>=0;i--)
        // {
        //     let currFn = functions[i];
        //     x  = currFn(x);
        // }
        // return x;

        return functions.reduceRight((acc, currFn) => currFn(acc), x);
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
