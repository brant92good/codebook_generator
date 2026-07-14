// base=500寫死 => 隱含 n,m<=500 (女生編號=base+j), 換題記得改
constexpr ll mxN=1001;
constexpr ll base=500;
ll n,m,k,vs1[mxN],vs2[mxN],ok[mxN][mxN]{};
vc<ll> adj[mxN];
bool dfs(ll u){
	if(vs2[u]) return false;
	vs2[u]=1;
	for(auto&v:adj[u]) if(!vs1[v] || dfs(vs1[v])){vs1[v]=u; return true;}
	return false;
}
void solve(istream &cin){
	cin >> n >> m >> k;
	//[1,500] boy [500+1,500+500] girl
	forn(i,0,k){
		ll u,v; cin >> u >> v,v+=base;
		if(!ok[u][v])
			adj[u].emp(v),adj[v].emp(u),ok[u][v]=1;
	}
	memset(vs1,0,sizeof(vs1));
	forn(i,1,n+m+1){
		memset(vs2,0,sizeof(vs2));
		dfs(i);
	}
	vc<ar<ll,2>> res;
	forn(i,1,n+1){
		for(auto &v:adj[i]){
			if(vs1[v]==i) res.emp(ar<ll,2>{i,v-base});
		}
	}
	cout << res.size() << '\n';
	for(auto&[u,v]:res) cout << u << ' ' << v << '\n';
}
