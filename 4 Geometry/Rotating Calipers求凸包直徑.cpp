struct Point {
    double x, y;
};

double dist2(const Point& a, const Point& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// 假設 convex 是逆時針的「嚴格」凸包(無共線點/重複點, 否則two-pointer不保證正確)
// 座標>1e7時 double 平方和超過2^53有精度風險, 應改ll算dist2最後才sqrt
double convexHullDiameter(const vector<Point>& convex) {
    int n = convex.size();
    if (n == 1) return 0;
    if (n == 2) return sqrt(dist2(convex[0], convex[1]));
    double res = 0;
    for (int i = 0, j = 1; i < n; ++i) {
        while (dist2(convex[i], convex[(j + 1) % n]) > dist2(convex[i], convex[j]))
            j = (j + 1) % n;
        res = max(res, dist2(convex[i], convex[j]));
    }
    return sqrt(res);
}