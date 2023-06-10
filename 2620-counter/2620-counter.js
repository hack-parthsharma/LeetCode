function createCounter(n) {
  let i = -1;
  return function() {
    i++;
    return n + i;
  };
}
