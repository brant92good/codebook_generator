// SPFA版MCMF: 邊權必須非負(無負環偵測, 原圖有負權會死迴圈); 源1匯n寫死; 多測清 e/id/adj
class Edge{
	public:
		ll u,v,c,w;
		Edge(){}
		Edge(ll u,ll v,ll c,ll w):u(u),v(v),c(c),w(w){}
};
constexpr ll mxN=501;
ll n,m,k,id=0,vs[mxN]{},d[mxN],pa[mxN];
vc<Edge> e;
vc<ll> adj[mxN];
ll bfs(){
	memset(pa,-1,8*(n+1)),memset(d,0x3f,sizeof(d));
	queue<ll> q;
	d[1]=0,vs[1]=1,q.emplace(1);
	while(!q.empty()){
		auto u=q.front(); q.pop(),vs[u]=0;
		for(auto &eid:adj[u]){
			auto [x,v,c,w]=e[eid];
			if(c && d[u]+w<d[v]){
				pa[v]=eid,d[v]=d[u]+w;
				if(!vs[v]) vs[v]=1,q.emplace(v);
			}
		}
	}
	return d[n]<INF;
}
void solve(){
	cin >> n >> m >> k;
	forn(i,1,m+1){
		ll u,v,c,w; cin >> u >> v >> c >> w;
		e.emp(Edge{u,v,c,w}),e.emp(Edge{v,u,0,-w}),adj[u].emp(id++),adj[v].emp(id++);
	}
	ll f=0,res=0;
	for(ll nf,v;f<k && bfs();){
		for(nf=k-f,v=n;v!=1;nf=min(nf,e[pa[v]].c),v=e[pa[v]].u);
		for(v=n;v!=1;e[pa[v]].c-=nf,e[pa[v]^1].c+=nf,v=e[pa[v]].u);
		res+=d[n]*nf,f+=nf;
	}
	cout << (f<k?-1:res) << '\n';
}
