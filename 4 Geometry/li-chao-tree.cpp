// solve()是特定題: (y2-y1)/m 整數除法, 斜率不整除會錯, 通用時只抄struct+insert+query
class Line{
	public:
		ll m,c;
		Line(){m=0,c=-inf;} //通用版: 空節點=-inf (m=0, cal不會溢位)
		//Line(){m=c=0;}   //原題版: 答案保證>=0才可用, 否則負答案會被鎖成0
		Line(ll m,ll c):m(m),c(c){}
		ll cal(ll x){return m*x+c;}
};
constexpr ll mxN=1e5;
Line t[mxN<<2];
void insert(ll i,ll sl,ll sr,Line l){
	ll mid=(sl+sr)>>1;
	if(l.cal(mid)>t[i].cal(mid)) swap(l,t[i]);
	if(sl==sr) return;
	if(l.m>t[i].m) insert(i<<1|1,mid+1,sr,l);
	else insert(i<<1,sl,mid,l);
}
ll query(ll i,ll sl,ll sr,ll x){
	ll mid=(sl+sr)>>1;
	if(sl==sr) return t[i].cal(x);
	if(x<=mid) return max(t[i].cal(x),query(i<<1,sl,mid,x));
	else return max(t[i].cal(x),query(i<<1|1,mid+1,sr,x));
}
void solve(istream &cin){
	ll n,m; cin >> n >> m;
	forn(i,0,n){
		ll y1,y2; cin >> y1 >> y2;
		// (y2-y1)/(m-0) = (y-y1)/x
		//x * (y2-y1)/m + y1= y
		Line l((y2-y1)/m,y1);
		insert(1,1,mxN,l);
	}
	forn(i,0,m+1) cout << query(1,1,mxN,i) << " \n"[i==m];
}
