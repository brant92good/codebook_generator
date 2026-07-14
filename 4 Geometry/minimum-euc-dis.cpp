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
		friend bool operator<(const Point a,const Point b){return a.x<b.x||(a.x==b.x && a.y<b.y);}
};
ll euc(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void solve(istream &cin){
	ll n; cin >> n;
	vc<Point> a(n); for(auto &v:a) cin >> v;
	sort(all(a),[](Point u,Point v){return (u.y<v.y)||(u.y==v.y && u.x<v.x);});
	ll d;
	mls<Point> hp;
	d=euc(a[0],a[1]),hp.emplace(a[0]),hp.emplace(a[1]);
	for(ll i=2,p=0;i<n;i++){
		for(;p<i && (a[p].y-a[i].y)*(a[p].y-a[i].y)>=d;hp.erase(hp.lwb(a[p])),p++); //p<i! 寫p<n重複點(d=0)會清空set後erase(end())炸掉
		auto it=hp.lwb(a[i]);
		auto front=it,back=it;
		forn(j,0,4){
			if(front!=hp.ed()) d=min(d,euc(a[i],*front)); 
			else break; front++;
		}
		forn(j,0,4){ 
			if(back!=hp.ed()) d=min(d,euc(a[i],*back)); 
			{if(back!=hp.bg()) back--; else break;} 
		}
		hp.emplace(a[i]);
	}
	cout << d << '\n';
}
