struct Point {
    long long x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

long long cross(const Point& a, const Point& b, const Point& c) {
    // (b-a) x (c-a)
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// 只支援插入; 嚴格凸包(共線點會被移除), 每條殼同x只留一點
struct DynamicConvexHull {
    set<Point> up, dn; // 上凸殼、下凸殼 (皆由左至右)

    void insert(const Point& p) {
        insertHull(up, p, +1);
        insertHull(dn, p, -1);
    }

    // 逆時針凸包頂點(不重複); 1點/2點退化也正確
    vector<Point> getConvexHull() const {
        vector<Point> res(dn.begin(), dn.end());
        for (auto it = up.rbegin(); it != up.rend(); ++it)
            if (!(res.size() && (*it == res.back() || *it == res.front())))
                res.push_back(*it);
        return res;
    }

private:
    // side=+1上殼, -1下殼; p在殼上或內側回傳true
    bool covered(const set<Point>& h, const Point& p, long long side) const {
        if (h.empty() || p.x < h.begin()->x || p.x > h.rbegin()->x) return false;
        auto r = h.lower_bound(Point{p.x, LLONG_MIN}); // 第一個 x>=p.x
        if (r->x == p.x) return side * (r->y - p.y) >= 0;
        return side * cross(*prev(r), *r, p) <= 0;
    }
    void insertHull(set<Point>& h, const Point& p, long long side) {
        if (covered(h, p, side)) return; // 在殼內, 不影響凸包
        auto r = h.lower_bound(Point{p.x, LLONG_MIN});
        if (r != h.end() && r->x == p.x) h.erase(r); // 同x被p支配
        auto it = h.insert(p).first;
        while (it != h.begin()) { // 往左刪不再凸的點
            auto b = prev(it);
            if (b == h.begin()) break;
            auto a = prev(b);
            if (side * cross(*a, *b, *it) >= 0) h.erase(b);
            else break;
        }
        while (next(it) != h.end()) { // 往右刪不再凸的點
            auto b = next(it);
            if (next(b) == h.end()) break;
            auto c = next(b);
            if (side * cross(*it, *b, *c) >= 0) h.erase(b);
            else break;
        }
    }
};
