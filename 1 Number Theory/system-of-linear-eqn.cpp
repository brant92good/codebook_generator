// mod mdl1 下高斯消去. 無解輸出-1; 無窮多解「不會偵測」(自由變數=0給特解), 題目要區分時要自己加
// 輸入係數需已在 [0,mdl1) 內 (負數要先轉正); inv 其實是快速冪, 模數寫死 mdl1
constexpr ll mxN=505;
ll n,m;
ll inv(ll a,ll m){ll ans; for(ans=1;m;ans=(m&1?(ans*a)%mdl1:ans),a=(a*a)%mdl1,m>>=1); return ans;}
void solve(istream &cin){
	cin>>n>>m;
	vc<ll> res(m,0);
	vc<vc<ll>> a(n,vc<ll>(m+1));
	forn(i,0,n) forn(j,0,m+1) cin>>a[i][j];
	ll l=0;
	for(ll i=0;i<m && l<n;++i){
		if(!a[l][i]) forn(j,l+1,n) if(a[j][i]){swap(a[j],a[l]); break;}
		if(!a[l][i]) continue;
		ll c=inv(a[l][i],mdl1-2);
		for(auto&v:a[l]) v=(v*c)%mdl1;
		forn(j,l+1,n){
			ll co=a[j][i];
			forn(k,i,m+1) a[j][k]=((a[j][k]-co*a[l][k])%mdl1+mdl1)%mdl1;
		}
		l++;
	}
	forr(i,n-1,0){
		ll j=0;
		while(j<m+1 && !a[i][j]) j++;
		if(j==a[i].size()) continue;
		if(j+1==a[i].size()){cout << -1 << '\n'; return;}
		ll u=a[i][m];
		forn(k,j+1,m) u=((u-a[i][k]*res[k])%mdl1+mdl1)%mdl1;
		res[j]=u;
	}
	forn(i,0,m) cout << res[i] << " \n"[i==m-1];
}
int main()
{
    fast_io;
    ll testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve(cin);
    return 0;
}
