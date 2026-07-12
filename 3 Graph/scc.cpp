void dfs(ll u){
	dfn[u]=low[u]=++tim,st[++id]=u,vs[u]=1;
	for(auto &v:adj[u]){
		if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
		else if(vs[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		for(ll v=-1;v!=u;scc[st[id]]=sc,vs[st[id]]=0,v=st[id],id--);
		sc++;
	}
}
