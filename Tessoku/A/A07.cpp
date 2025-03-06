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
    
    int D, N, L[100009], R[100009], B[100009];
    cin >> D >> N;
    for (int i = 1; i <=N; ++i) cin >> L[i] >> R[i];
    for (int i = 1; i <= N; ++i) {
        B[L[i]] += 1;
        B[R[i] + 1] -= 1;
    }
    int res[100009];
    res[0] = 0;
    for (int d = 1; d <= D; ++d) res[d] = res[d - 1] + B[d];
    for (int d = 1; d <= D; ++d) cout << res[d] << "\n";
    return 0;
}
