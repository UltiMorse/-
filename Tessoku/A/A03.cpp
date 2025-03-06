#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n - 1; i >= 0; --i)
using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    vector<int> Q(N);
    rep(j, N) cin >> Q[j];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (P[i] + Q[j] == K) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
