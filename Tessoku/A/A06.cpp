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
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    int L[100009], R[100009], S[100009];
    for (int j = 1; j <= Q; ++j) cin >> L[j] >> R[j];

    S[0] = 0;
    for (int i = 1; i <= N; ++i) S[i] = S[i - 1] + A[i];
    for (int j = 1; j <= Q; ++j) cout << S[R[j]] - S[L[j] - 1] << "\n";
    return 0;
}
