/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    
    // const str = JSON.stringify(obj);

    // return str == '{}' || str == '[]';

    // return Object.keys(obj).length == 0;

    for(o in obj)
    return false;

    return true;
};
