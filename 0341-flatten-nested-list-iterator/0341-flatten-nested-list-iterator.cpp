class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    addInteger(nestedList);
  }
  int next() {
    const int num = stack.top().getInteger();
    stack.pop();
    return num;
  }
  bool hasNext() {
    while (!stack.empty() && !stack.top().isInteger()) {
      vector<NestedInteger> nestedList = stack.top().getList();
      stack.pop();
      addInteger(nestedList);
    }
    return !stack.empty();
  }
 private:
  stack<NestedInteger> stack;
  void addInteger(const vector<NestedInteger>& nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; --i)
      stack.push(nestedList[i]);
  }
};
