constexpr ll mxN=2e5+3;
ll n,m,rt,t[mxN][2]{},cnt[mxN],val[mxN],f[mxN],lz[mxN]{},vals[mxN];
string s;
ll dir(ll x){return t[f[x]][1]==x;}
void push_down(ll x){
	if(lz[x]){
		swap(t[x][0],t[x][1]);
		if(t[x][0]) lz[t[x][0]]^=1;
		if(t[x][1]) lz[t[x][1]]^=1;
		lz[x]=0;
	}
}
void push(ll x){cnt[x]=cnt[t[x][0]]+1+cnt[t[x][1]],vals[x]=vals[t[x][0]]+val[x]+vals[t[x][1]];}
void rotate(ll x){
	ll y=f[x],z=f[y],d=dir(x);
	t[y][d]=t[x][d^1],t[x][d^1]=y;
	if(t[y][d]) f[t[y][d]]=y;
	if(z) t[z][dir(y)]=x;
	f[y]=x,f[x]=z,push(y),push(x);
}
void splay(ll &z,ll x){
	ll w=f[z];
	for(ll y;(y=f[x])!=w;rotate(x)){
		if(f[y]!=w) rotate(dir(x)==dir(y)?y:x);
	}
	z=x;
}
void build(){
	rt=0;
	forn(i,1,n+3){
		t[i][0]=rt;
		if(rt) f[rt]=i;
		rt=i;
	}
	splay(rt,1);
}
void loc(ll &z,ll k){
	ll x=z;
	for(push_down(x);cnt[t[x][0]]+1!=k;push_down(x)){
		if(k>cnt[t[x][0]]) k-=cnt[t[x][0]]+1,x=t[x][1];
		else x=t[x][0];
	}
	splay(z,x);
}
void opt(ll l,ll r){
	loc(rt,l);
	loc(t[rt][1],r-l+2);
	ll x=t[t[rt][1]][0];
	lz[x]^=1;
}
ll query(ll l,ll r){
	loc(rt,l),loc(t[rt][1],r-l+2);
	ll x=t[t[rt][1]][0],y=vals[x];
	return y;
}
void solve(istream &cin){
	cin >> n >> m;
	forn(i,2,n+2) cin >> val[i];
	build();
	forn(i,0,m){
		ll op,l,r; cin >> op >> l >> r;
		if(op==1) opt(l,r);
		else cout << query(l,r) << '\n';
	}
}
