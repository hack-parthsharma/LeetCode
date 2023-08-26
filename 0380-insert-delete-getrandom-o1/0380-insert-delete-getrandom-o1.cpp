class RandomizedSet {
 public:
  bool insert(int val) {
    if (valToIndex.count(val))
      return false;

    valToIndex[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (!valToIndex.count(val))
      return false;

    const int index = valToIndex[val];
    valToIndex[vals.back()] = index;
    valToIndex.erase(val);
    vals[index] = vals.back();
    vals.pop_back();
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    const int index = rand() % vals.size();
    return vals[index];
  }

 private:
  unordered_map<int, int> valToIndex;  // {val: index in vals}
  vector<int> vals;
};
