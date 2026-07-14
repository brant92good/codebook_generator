// mxN=501 => n,m<=500; 匹配數0時不會輸出任何匹配行
constexpr ll mxN=501;
ll n,m,k,mat[mxN<<1]{},d[mxN<<1];
vc<ll> adj[mxN];
ll bfs(){
	queue<ll> q;
	memset(d,-1,sizeof(d));
	forn(i,1,n+1) if(!mat[i]) d[i]=0,q.emplace(i);
	while(!q.empty()){
		ll u=q.front(); q.pop();
		if(~d[0]) return 1;
		for(auto &v:adj[u]){
			if(!(~d[mat[v]])) d[mat[v]]=d[u]+1,q.emplace(mat[v]);
		}
	}
	return 0;
}
bool dfs(ll u){
	if(!u) return true;
	for(auto &v:adj[u]) if(d[mat[v]]==d[u]+1 && dfs(mat[v])){mat[u]=v,mat[v]=u;return true;}
	d[u]=-1;
	return false;
}
void solve(istream &cin){
	cin >> n >> m >> k;
	forn(i,0,k){ll u,v; cin >> u >> v; adj[u].emp(n+v);}
	ll res=0;
	for(;bfs();) forn(i,1,n+1) if(!mat[i]) res+=dfs(i);
	cout << res << '\n';
	if(res) forn(i,1,n+1) if(mat[i]) cout << i << ' ' << (mat[i]-n) << '\n';
}
