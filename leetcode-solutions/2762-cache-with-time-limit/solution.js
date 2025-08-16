// var TimeLimitedCache = function() {
    
// };

// /** 
//  * @param {number} key
//  * @param {number} value
//  * @param {number} duration time until expiration in ms
//  * @return {boolean} if un-expired key already existed
//  */
// TimeLimitedCache.prototype.set = function(key, value, duration) {
    
// };

// /** 
//  * @param {number} key
//  * @return {number} value associated with key
//  */
// TimeLimitedCache.prototype.get = function(key) {
    
// };

// /** 
//  * @return {number} count of non-expired keys
//  */
// TimeLimitedCache.prototype.count = function() {
    
// };

// /**
//  * const timeLimitedCache = new TimeLimitedCache()
//  * timeLimitedCache.set(1, 42, 1000); // false
//  * timeLimitedCache.get(1) // 42
//  * timeLimitedCache.count() // 1
//  */

class TimeLimitedCache{
    constructor()
    {
        this.cacheMap = new Map();
    }
    set(key,value,duration){
        let alreadyExists = this.cacheMap.get(key);
        if(alreadyExists)
        {
            clearTimeout(alreadyExists.timeoutId);
        }
        let timeoutId=  setTimeout(()=>{
            this.cacheMap.delete(key)
        },duration);
        this.cacheMap.set(key,{value,timeoutId});

        return Boolean(alreadyExists);
    }
    get(key){
        if(this.cacheMap.has(key))
        {
            return this.cacheMap.get(key).value;
        }
        return -1;
    }
    count(){
        return this.cacheMap.size;
    }
}
