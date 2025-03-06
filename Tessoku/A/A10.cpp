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
    
    int N, D;
    cin >> N;
    vector<int> A(N);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    cin >> D;
    int L[100009], R[100009];
    for (int i = 1; i <= D; ++i) {
        cin >> L[i] >> R[i];
    }
    vector<int> P(N);
    P[1] = A[1];
    for (int i = 2; i <= N; ++i) P[i] = max(P[i - 1], A[i]);
    vector<int> Q(N);
    Q[N] = A[N];
    for (int i = N - 1; i >= 1; --i) Q[i] = max(Q[i + 1], A[i]);
    for (int i = 1; i <= D; ++i) {
        cout << max(P[L[i] - 1], Q[R[i] + 1]) << "\n";
    }
    return 0;
}
