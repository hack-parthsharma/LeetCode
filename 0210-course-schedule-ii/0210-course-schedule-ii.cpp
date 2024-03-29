enum class State { kInit, kVisiting, kVisited };
class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<vector<int>> graph(numCourses);
    vector<State> state(numCourses);
    for (const auto& p : prerequisites)
      graph[p[1]].push_back(p[0]);
    for (int i = 0; i < numCourses; ++i)
      if (hasCycle(graph, i, state, ans))
        return {};
    reverse(begin(ans), end(ans));
    return ans;
  }
 private:
  bool hasCycle(const vector<vector<int>>& graph, int u, vector<State>& state,
                vector<int>& ans) {
    if (state[u] == State::kVisiting)
      return true;
    if (state[u] == State::kVisited)
      return false;
    state[u] = State::kVisiting;
    for (const int v : graph[u])
      if (hasCycle(graph, v, state, ans))
        return true;
    state[u] = State::kVisited;
    ans.push_back(u);

    return false;
  }
};
