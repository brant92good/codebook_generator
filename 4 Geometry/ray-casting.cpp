class Point{
	public:
		ll x,y;
		Point(){}
		Point(ll x,ll y):x(x),y(y){}
		friend ll operator^(const Point a,const Point b){return a.x*b.y-a.y*b.x;}
		friend ll operator*(const Point a,const Point b){return a.x*b.x+a.y*b.y;}
		friend Point operator-(const Point a,const Point b){
			return Point{a.x-b.x,a.y-b.y};
		}
		friend istream& operator>>(istream &in,Point &a){
			in >> a.x >> a.y;
			return in;
		}
};
bool on(Point &a,Point &b,Point &c){
		if((b-a)^(c-a)) return false;
		return 0<=((b-a)*(c-a)) && ((b-a)*(c-a))<=((b-a)*(b-a));
}
void query(vc<Point> &a,Point &p){
	ll n=a.size(),ok=0;
	forn(i,0,n){
		ll j=(i+1)%n;
		if(on(a[i],a[j],p)){cout << "BOUNDARY" << '\n'; return;}
		if(p.y>a[i].y!=p.y>a[j].y){
			ll sg=(a[j]-a[i])^(p-a[i]);
			if(sg<0==a[i].y>a[j].y) ok^=1;
		}
		
	}
	cout << (ok&1?"INSIDE":"OUTSIDE") << '\n';
}
