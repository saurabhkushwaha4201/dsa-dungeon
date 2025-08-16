/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
    let n = functions.length;
    let resolvedCount = 0;
    const results = []
    return new Promise((resolve, reject) => {

        for (let i = 0; i < n; i++) {
            functions[i]().then(value => {
                results[i] = value
                resolvedCount++;
                if (resolvedCount == n)
                    resolve(results);
            }).catch(err => reject(err));
        }
    })


};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
