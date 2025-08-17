/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
    // const joinedArray = [...arr1];

    // for(let i = 0;i<arr2.length;i++)
    // {
    //     let idx = joinedArray.findIndex(item => item.id === arr2[i].id);
    //     if(idx!=-1){
    //         joinedArray[idx] = {...joinedArray[idx],...arr2[i]}
    //     }
    //     else{
    //         joinedArray.push(arr2[i]);
    //     }
    // }

    // return joinedArray.sort((a,b)=>a.id - b.id);

    const myMap = new Map();

    for (let obj of arr1) {
        myMap.set(obj.id, obj);
    }

    for (let obj of arr2) {
        const existing = myMap.get(obj.id);
        if (existing) {
            // merge with old object
            myMap.set(obj.id, { ...existing, ...obj });
        } else {
            // new id insert
            myMap.set(obj.id, obj);
        }
    }

    const joinedArray = Array.from(myMap.values());
    return joinedArray.sort((a, b) => a.id - b.id);

};
