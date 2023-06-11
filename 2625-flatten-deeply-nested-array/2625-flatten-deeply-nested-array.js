function flat(arr, depth) {
  if (depth === 0) {
    return arr.slice(); // Base case: return a shallow copy of the array
  }

  let flattened = [];

  for (let i = 0; i < arr.length; i++) {
    if (Array.isArray(arr[i])) {
      const nested = flat(arr[i], depth - 1); // Recursively flatten nested arrays
      flattened.push(...nested); // Concatenate flattened nested arrays to the result
    } else {
      flattened.push(arr[i]); // Push individual elements to the result
    }
  }

  return flattened; // Return the flattened array
}