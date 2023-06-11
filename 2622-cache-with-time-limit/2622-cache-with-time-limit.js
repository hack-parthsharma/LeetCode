var TimeLimitedCache = function() {
    this.Cache=new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
     let res=false;
      if(this.Cache.has(key))
      {
         const ref=this.Cache.get(key).ref;
         clearTimeout(ref);
         res=true;
      }
       const ref=setTimeout(()=>{
         this.Cache.delete(key);
         },duration);
         this.Cache.set(key,{
               value:value,
               ref:ref
         });
      return res;
};


TimeLimitedCache.prototype.get = function(key) {
      if(this.Cache.has(key))
    {
       return this.Cache.get(key).value;  
    }
    return -1;
};


TimeLimitedCache.prototype.count = function() {
      return this.Cache.size;
};