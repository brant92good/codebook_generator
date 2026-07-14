// 注意: 面積為0(退化/全共線)會除以零得NaN; 整數座標>~3e7時double精度風險(可改ll累加)
struct Point {
    double x, y;
};

Point polygonCentroid(const vector<Point>& poly) {
    double cx = 0, cy = 0, area = 0;
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        double cross = poly[i].x * poly[(i + 1) % n].y - poly[(i + 1) % n].x * poly[i].y;
        cx += (poly[i].x + poly[(i + 1) % n].x) * cross;
        cy += (poly[i].y + poly[(i + 1) % n].y) * cross;
        area += cross;
    }
    area /= 2.0;
    cx /= (6.0 * area);
    cy /= (6.0 * area);
    return {cx, cy};
}