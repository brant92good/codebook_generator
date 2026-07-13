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
		friend ostream& operator<<(ostream &out,Point &a){
			out << a.x << ' ' << a.y << '\n';
			return out;
		}
		friend bool operator<(const Point a,const Point b){return a.x<b.x||(a.x==b.x && a.y<b.y);}
};
ll dis(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
ll ok(Point a,Point b,Point c){
	ll ang=(b-a)^(c-a); //ang>0 false ang< true
	return ang<0;
}
constexpr ll mxN=2e5+5;
ll st[mxN],id=0;
void solve(istream &cin){
	ll n; cin >> n;
	vc<Point> a(n); for(auto &v:a) cin >> v;
	forn(i,1,n) if(a[i]<a[0]) swap(a[i],a[0]);
	sort(1+all(a),[p=a[0]](Point a,Point b){ll ang=(a-p)^(b-p); return !ang?dis(p,a)<dis(p,b):ang>0;});
	{
		ll j; for(j=n-1;j>=0 && ((a[j]-a[0])^(a[n-1]-a[0]))==0;j--); reverse(j+1+a.bg(),a.ed());
	}
	forn(i,0,n){
		while(id>1 && ok(a[st[id-1]],a[st[id]],a[i])) --id;
		st[++id]=i;
	}
	cout << id << '\n';
	if(id) for(;id;cout << a[st[id--]]);
}
