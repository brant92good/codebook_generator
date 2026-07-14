// solve()斜率 (y2-y1)/(x2-x1): 垂直線段(x1==x2)會除以零, 不整除會截斷
class Line{
	public:
		ll m,c;
		Line(){m=0,c=-inf;} //通用版: 空節點=-inf
		//Line(){m=0,c=-1;} //原題版sentinel: 該題「查無值輸出-1」時用這行
		Line(ll m,ll c):m(m),c(c){}
		ll cal(ll x){return m*x+c;}
};
constexpr ll mxN=1e5;
Line t[mxN<<2];
void insert(ll i,ll sl,ll sr,ll l,ll r,Line L){
	if(l>sr || r<sl) return ;
	ll mid=(sl+sr)>>1;
	if(l<=sl && sr<=r){
		if(L.cal(mid)>t[i].cal(mid)) swap(L,t[i]);
		if(sl==sr) return;
		if(L.m>t[i].m) insert(i<<1|1,mid+1,sr,l,r,L);
		else insert(i<<1,sl,mid,l,r,L);
		return ;
	}
	insert(i<<1,sl,mid,l,r,L);
	insert(i<<1|1,mid+1,sr,l,r,L);
}
ll query(ll i,ll sl,ll sr,ll x){
	ll mid=(sl+sr)>>1;
	if(sl==sr) return t[i].cal(x);
	if(x<=mid) return max(t[i].cal(x),query(i<<1,sl,mid,x));
	else return max(t[i].cal(x),query(i<<1|1,mid+1,sr,x));
}
void solve(istream &cin){
	ll n,m,r0=-1; cin >> n >> m;
	forn(i,0,n){
		ll x1,x2,y1,y2; cin >> x1 >> y1 >> x2 >> y2;
		if(!x1) r0=max(r0,y1);
		Line l((y2-y1)/(x2-x1),-x1*(y2-y1)/(x2-x1) + y1);
		insert(1,1,mxN,x1,x2,l);
	}
	cout << r0 << " \n"[m==1];
	forn(i,1,m+1) cout << query(1,1,mxN,i) << " \n"[i==m];
}
