constexpr ll mxN=1e5+1;
ll n,m,dfn[mxN]{},low[mxN],tin=0;
vc<ll> adj[mxN];
vc<ar<ll,2>> res;
void tarjan(ll u=1,ll p=0){
	dfn[u]=low[u]=++tin;
	for(auto &v:adj[u]){
		if(v==p) continue;
		if(dfn[v]) low[u]=min(low[u],dfn[v]);
		else{
			tarjan(v,u),low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) res.emp(ar<ll,2>{u,v});
		}
	}
}
