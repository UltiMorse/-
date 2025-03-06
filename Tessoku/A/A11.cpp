#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n - 1; i >= 0; --i)
using ll = long long;
using ull = unsigned long long;
using ld = long double;

int N, X;
/*
// 二分探索してみる
int search(const vector<int>& A) { // アンパサンドで参照渡し
    int L = 1, R = N;
    while (L <= R) {
        int M = (L + R) / 2;
        if (X < A[M]) R = M - 1;
        else if (X > A[M]) L = M + 1;
        else return M;
    }
    return -1;
}
*/
// lower_boundを使った二分探索
int search(const vector<int>& A) {
    int pos = lower_bound(A.begin(), A.end(), X) - A.begin();
    if (pos < N && A[pos] == X) return pos;
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int ans = search(A);
    cout << ans + 1 << "\n";
    return 0;
}
