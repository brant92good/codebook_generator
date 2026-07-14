// 遞迴深度可達2m(=2e5), 注意stack限制
constexpr ll mxN=2e5+1;
ll sc=0,scc[mxN];
ll id=0,st[mxN],vs[mxN]{};
ll n,m,tin=0,dfn[mxN]{},low[mxN];
vc<ll> adj[mxN];
void tarjan(ll u){
	dfn[u]=low[u]=++tin,st[++id]=u,vs[u]=1;
	for(auto &v:adj[u]){
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(vs[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		sc++;
		for(;id;){
			scc[st[id]]=sc,vs[st[id]]=0;
			id--;
			if(st[id+1]==u) break;
		}
	}
}
void solve(istream &cin){
	cin >> n >> m;
	forn(i,1,n+1){
		char c1,c2; ll x,y,X,Y; cin >> c1 >> x >> c2 >> y; 
		X=x+m,Y=y+m;
		if(c1=='-') swap(x,X);
		if(c2=='-') swap(y,Y);
		adj[X].emp(y),adj[Y].emp(x);
	}
	forn(i,1,2*m+1) if(!dfn[i]) tarjan(i);
	forn(i,1,m+1) if(scc[i]==scc[i+m]){cout << "IMPOSSIBLE" << '\n'; return;}
	forn(i,1,m+1) cout << (scc[i]>scc[i+m]?'-':'+') << " \n"[i==m];
}
