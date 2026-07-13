constexpr ll mxN=2e5+1;
ll n,d[2][2];
void solve(){
	cin >> n;
	d[0][0]=d[1][0]=-inf;
	d[0][1]=d[1][1]=inf;
	forn(i,0,n){
		ll x,y;
		cin >> x >> y;
		d[0][0]=max(d[0][0],x+y);
		d[0][1]=min(d[0][1],x+y);
		d[1][0]=max(d[1][0],x-y);
		d[1][1]=min(d[1][1],x-y);
		cout << max(d[0][0]-d[0][1],d[1][0]-d[1][1]) << '\n';
	}
}
