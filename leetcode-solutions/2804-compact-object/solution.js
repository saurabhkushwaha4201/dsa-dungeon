/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    
    const solve = ((value)=>{

        if(Array.isArray(value))    // for arrays only
        {
            let result = [];
            // for(let i = 0;i<value.length;i++)
            // {
            //     const valid = solve(value[i]);

            //     if(Boolean(valid))
            //     {
            //         result.push(valid);
            //     }
            // }

            result  = value.map(el=>solve(el)).filter(el=>Boolean(el));
            return result;
        }
        else if(value !=null && typeof value==='object')    // for objects only null is also object but falsy value
        {
            const result = {};

            for(let key in value)
            {
                const valid = solve(value[key]);

                if(Boolean(valid))
                {
                    result[key] = valid
                }
            }
            return result;

        }
        else    // primitive checked by parent on above 
        return value;
    })
    return solve(obj);
};
