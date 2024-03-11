#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll n, m;
vl K;

ll ans;
void solve(ll x) {
  if (n < x) {
    return;
  }

  if (ans < x) {
    ans = x;
  }

  x *= 10;
  for (auto i = 0; i < m; ++i) {
    x += K[i];
    solve(x);
    x -= K[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;

  K = vl(m);
  for (auto&& x : K) {
    cin >> x;
  }

  ans = 0;
  solve(0);
  cout << ans;

  return 0;
}