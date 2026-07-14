struct Point {
    long long x, y;
};

// 以 base 為原點極角排序: 從+x軸(角度0)逆時針到2π; 同角度距離近的在前
// 必須先分上下半平面再比cross, 否則超過180度時comparator無效(UB)
// base 本身若在點集中會被排在最前(視為角度0距離0)
void polarSort(vector<Point>& points, Point base) {
    auto half = [&](const Point& p) { // 0:上半平面(含+x軸), 1:下半平面(含-x軸)
        long long dx = p.x - base.x, dy = p.y - base.y;
        return (dy < 0 || (dy == 0 && dx < 0)) ? 1 : 0;
    };
    sort(points.begin(), points.end(), [&](const Point& a, const Point& b) {
        if (half(a) != half(b)) return half(a) < half(b);
        long long ax = a.x - base.x, ay = a.y - base.y;
        long long bx = b.x - base.x, by = b.y - base.y;
        long long cr = ax * by - ay * bx;
        if (cr != 0) return cr > 0;
        return ax * ax + ay * ay < bx * bx + by * by; // 座標<=1e9不溢位
    });
}
