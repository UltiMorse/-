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
    
    int H, W, Q;
    cin >> H >> W;
    vector<vector<int>> X(H + 1, vector<int>(W + 1)); // vectorは0で初期化されるので、明示的に初期化する必要はない。組み込み配列は明示的に初期化。
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cin >> X[i][j];
        }
    }
    cin >> Q;
    int A[100009], B[100009], C[100009], D[100009];
    for (int i = 1; i <= Q; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    vector<vector<int>> S(H + 1, vector<int>(W + 1));
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            S[i][j] = S[i][j - 1] + X[i][j];
        }
    }
    for (int j = 1; j <= W; ++j) {
        for (int i = 1; i <= H; ++i) {
            S[i][j] = S[i - 1][j] + S[i][j];
        }
    }
    for (int i = 1; i <= Q; ++i) {
        cout << S[C[i]][D[i]] - S[A[i] - 1][D[i]] - S[C[i]][B[i] - 1] + S[A[i] - 1][B[i] - 1] << "\n";
    }
    return 0;
}
