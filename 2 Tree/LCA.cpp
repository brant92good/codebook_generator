constexpr ll mxN=2e5+1;
ll pa[mxN][20],d[mxN]{};
vc<ll> adj[mxN];
void dfs(ll u=1,ll p=0){d[u]=d[p]+1,pa[u][0]=p; for(auto&v:adj[u]) if(v!=p) dfs(v,u);}
void init(ll n){ // 建好 adj 後呼叫一次
	dfs();
	forn(j,1,20) forn(i,1,n+1) pa[i][j]=pa[pa[i][j-1]][j-1];
}
ll lca(ll u,ll v){
	if(d[u]<d[v]) swap(u,v);
	forr(i,19,0) if(d[u]-(1<<i)>=d[v]) u=pa[u][i];
	if(u==v) return u;
	forr(i,19,0) if(pa[u][i]!=pa[v][i]) u=pa[u][i],v=pa[v][i];
	return pa[u][0];
}
