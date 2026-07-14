constexpr ll mxN=2e5+1;
ll tin=0,in[mxN]{},t[mxN<<1];
ll n,q,a[mxN],d[mxN]{},e[mxN]{};
vc<ll> adj[mxN];
ll dfs(ll u=1,ll p=0){
	ll mx=0,sub=1;
	forn(i,0,adj[u].size()){
		ll v=adj[u][i];
		if(v!=p){d[v]=d[u]+1; ll val=dfs(v,u); sub+=val; if(val>mx) mx=val,e[u]=v;}
		else swap(adj[u][i],adj[u][0]);
	}
	return sub;
}
void hld(ll u=1,ll p=1){
	in[u]=++tin,t[in[u]+n-1]=a[u];
	if(e[u]) hld(e[u],p);
	forn(i,1,adj[u].size()){ll v=adj[u][i]; if(e[u]!=v) hld(v,v);}
	e[u]=p;
}
void pst(ll p,ll val){for(t[p+=n-1]=val;p>>=1;t[p]=max(t[p<<1],t[p<<1|1]));}
ll qry(ll l,ll r){
	ll ans=0;
	for(l+=n-1,r+=n-1;l<=r;l>>=1,r>>=1){if(l&1) ans=max(ans,t[l++]); if(r&1^1) ans=max(ans,t[r--]);}
	return ans;
}
ll query(ll a,ll b){
	ll ans=0;
	for(;e[a]!=e[b];b=adj[e[b]][0]){
		if(d[e[a]]>d[e[b]]) swap(a,b);
		ans=max(ans,qry(in[e[b]],in[b]));
	}
	if(in[a]>in[b]) swap(a,b);
	return max(ans,qry(in[a],in[b]));
}
void solve(istream &cin){
	cin >> n >> q;
	forn(i,1,n+1) cin >> a[i];
	forn(i,0,n-1){ll u,v; cin >> u >> v; adj[u].emp(v),adj[v].emp(u);}
	adj[1].emp(0);
	dfs();
	hld();
	forr(i,n-1,1) t[i]=max(t[i<<1],t[i<<1|1]);
	for(ll op,a,b;q--;){
		cin >> op >> a >> b;
		if(op==1) pst(in[a],b);
		else cout << query(a,b) << ' ';
	}
}
