//consecutive point p[i] (0<=i<n)
//注意: 輸出是「2倍面積」(鞋帶公式沒除2); 2A = sum(p[i]^p[i+1])
//|座標|<=1e9 時 2A<=8e18 勉強不溢位, 更大要__int128

void solve(istream &cin){
	ll n,res=0;
	cin>>n;
	forn(i,1,n+1){
		cin>>a[i];
		if(i>1) res+=a[i-1]^a[i];//cross product
		if(i==n) res+=a[n]^a[1];
	}
	cout << abs(res) << '\n';
}
