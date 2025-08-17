/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */

function solve(arr,depth,result)
{
    for (let i = 0; i < arr.length; i++) {
        if (Array.isArray(arr[i])) {
            if(depth==0){
                result.push(arr[i]);
            }
            else if(depth>0){
                solve(arr[i],depth-1,result)
            }
        }
        else {
            result.push(arr[i]);
        }
    }
    return result;
}
var flat = function (arr, n) {

    const result = [];
    return solve(arr,n,result);

};
