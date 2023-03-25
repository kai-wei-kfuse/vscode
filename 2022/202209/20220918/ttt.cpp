// #include <bits/stdc++.h>
// #include <atcoder/dsu>
// using namespace std;

// int main() {
//     int N;
//     cin >> N;
//     vector<tuple<int, int, int>> edge(N - 1);
//     for (auto& [w, u, v] : edge) {
//         cin >> u >> v >> w;
//         u -= 1;
//         v -= 1;
//     }
//     sort(edge.begin(), edge.end());
//     atcoder::dsu dsu(N);
//     long long ans = 0;
//     for (const auto& [w, u, v] : edge) {
//         ans += (long long) w * dsu.size(u) * dsu.size(v);
//         dsu.merge(u, v);
//     }
//     cout << ans << '\n';
// }