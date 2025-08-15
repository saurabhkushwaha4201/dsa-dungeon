/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let n = arr.length;
    // const a = new Array(n);
    // for(let i = 0;i<n;i++)
    // {
    //     a[i] = fn(arr[i],i);
    // }

    // const a = Array.from({length:n},(_,i)=>fn(arr[i],i))
    const a = new Array();
    arr.forEach((val,idx)=>a.push(fn(val,idx)));
    return a;
};
