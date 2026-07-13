class Point{
	public:
		ll x,y;
		Point(){}
		Point(ll x,ll y):x(x),y(y){}
		ll f(Point a,Point b){
			return a.x*b.y-b.x*a.y;
		}//croos product
		friend Point operator-(const Point a,const Point b){
			return Point{a.x-b.x,a.y-b.y};
		}
		friend istream& operator>>(istream &in,Point &a){
			in >> a.x >> a.y;
			return in;
		}
};
