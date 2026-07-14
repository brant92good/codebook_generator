// mod 需外部定義; 快速冪用時記得單位矩陣
vector<vector<ll>> matrixMultiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    ll rowA = A.size();
    ll colA = A[0].size();
    ll colB = B[0].size();
    vector<vector<ll>> C(rowA, vector<ll>(colB, 0));
    for (ll i = 0; i < rowA; ++i) {
        for (ll k = 0; k < colA; ++k) {
            for (ll j = 0; j < colB; ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}
