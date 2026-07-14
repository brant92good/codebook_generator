// 找三點使外接圓最大: O(n^3) 枚舉 (答案的三點通常「不在」凸包上, 不能旋轉卡殼)
// 共線三點視為無效(回傳0); 全部共線輸出0. n~300內可跑
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll cross(P a, P b) { return a.first * b.second - a.second * b.first; }
ll dist2(P a, P b) {
    ll dx = a.first - b.first, dy = a.second - b.second;
    return dx * dx + dy * dy;
}
double dist(P a, P b) { return sqrt((double)dist2(a, b)); }

// R = abc / (4S); 2S 用 ll cross 算避免浮點誤判共線
double circumradius(P a, P b, P c) {
    ll S2 = abs(cross({b.first-a.first, b.second-a.second},
                      {c.first-a.first, c.second-a.second})); // 2S
    if (S2 == 0) return 0; // 共線
    return dist(b,c) * dist(a,c) * dist(a,b) / (2.0 * (double)S2);
}

int main() {
    int n;
    cin >> n;
    vector<P> pts(n);
    for (int i = 0; i < n; ++i) cin >> pts[i].first >> pts[i].second;
    double ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                ans = max(ans, circumradius(pts[i], pts[j], pts[k]));
    cout << fixed << setprecision(6) << ans << endl;
}
