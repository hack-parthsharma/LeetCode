enum class State { kDraw, kMouseWin, kCatWin };

class Solution {
 public:
  int catMouseGame(vector<vector<int>>& graph) {
    const int n = graph.size();
    // Result of (cat, mouse, move)
    // Move := 0 (mouse) / 1 (cat)
    vector<vector<vector<State>>> states(
        n, vector<vector<State>>(n, vector<State>(2)));
    vector<vector<vector<int>>> outDegree(
        n, vector<vector<int>>(n, vector<int>(2)));
    queue<tuple<int, int, int, State>> q;  // (cat, mouse, move, state)

    for (int cat = 0; cat < n; ++cat)
      for (int mouse = 0; mouse < n; ++mouse) {
        outDegree[cat][mouse][0] = graph[mouse].size();
        outDegree[cat][mouse][1] =
            graph[cat].size() - count(begin(graph[cat]), end(graph[cat]), 0);
      }

    // Start from states that winner can be determined
    for (int cat = 1; cat < n; ++cat)
      for (int move = 0; move < 2; ++move) {
        // Mouse is in the hole -> State::kMouseWin
        states[cat][0][move] = State::kMouseWin;
        q.emplace(cat, 0, move, State::kMouseWin);
        // Cat catches mouse -> State::kCatWin
        states[cat][cat][move] = State::kCatWin;
        q.emplace(cat, cat, move, State::kCatWin);
      }

    while (!q.empty()) {
      const auto [cat, mouse, move, state] = q.front();
      q.pop();
      if (cat == 2 && mouse == 1 && move == 0)
        return static_cast<int>(state);
      const int prevMove = move ^ 1;
      for (const int prev : graph[prevMove ? cat : mouse]) {
        const int prevCat = prevMove ? prev : cat;
        if (prevCat == 0)  // Invalid
          continue;
        const int prevMouse = prevMove ? mouse : prev;
        // The state is already determined
        if (states[prevCat][prevMouse][prevMove] != State::kDraw)
          continue;
        if (prevMove == 0 && state == State::kMouseWin ||
            prevMove == 1 && state == State::kCatWin ||
            --outDegree[prevCat][prevMouse][prevMove] == 0) {
          states[prevCat][prevMouse][prevMove] = state;
          q.emplace(prevCat, prevMouse, prevMove, state);
        }
      }
    }

    return static_cast<int>(states[2][1][0]);
  }
};
