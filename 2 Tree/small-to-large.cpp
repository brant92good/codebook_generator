// 注意: 每層遞迴持有deque, 鏈狀樹會爆棧且記憶體~300MB, 深樹題慎用
constexpr ll mxN=2e5+1;
ll n,k,res=0;
vc<ll> adj[mxN];
deque<ll> dfs(ll u=1,ll p=0){
	deque<ll> cur(1,{1}),tmp;
	for(auto &v:adj[u]){
		if(v!=p){
			tmp=dfs(v,u),tmp.push_front(0);
			if(tmp.size()>cur.size()) swap(tmp,cur);
			forn(i,0,tmp.size()) if(k-i>=0 && k-i<cur.size()) res+=cur[k-i]*tmp[i];
			forn(i,0,tmp.size()) cur[i]+=tmp[i];
		}
	}
	return cur;
}
void solve(istream &cin){
	cin >> n >> k;
	forn(i,0,n-1){ll u,v; cin >> u >> v; adj[u].emp(v),adj[v].emp(u);}
	dfs();
	cout << res << '\n';
}
