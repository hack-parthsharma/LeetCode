var timeLimit = function(fn, t) {
	return async function(...args) {
        return new Promise(async (resolve, reject) => {
        const tt = setTimeout(() => {
            reject("Time Limit Exceeded");
        }, t);

        try {
            const result = await fn(...args);
            resolve(result);
        } catch(err) {
            reject(err);
        }
        clearTimeout(tt);
        });
    }
};