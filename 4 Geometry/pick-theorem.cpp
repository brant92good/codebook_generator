void solve(istream &cin){
	ll n; cin >> n;
	vc<Point> a(n);
	for(auto &v:a) cin >> v;
	ll area=0,B=0;
	forn(i,0,n){
		ll j=(i+1)%n;
		area+=a[i]^a[j];
		B+=gcd(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y));
	}
	cout << (abs(area)/2+1-B/2) << ' ' << B << '\n';
	//area=I+B/2-1 I=internal node B=boundary node
}
