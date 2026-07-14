// 節點數: build用2n-1, 每次單點改約log(n)+1個; mxT要 >= 2n+q*20 (n=q=2e5時約4.2e6)
// 記憶體約 7e6*(8+4+4) ≈ 106MB; 多測時 t/lc/rc 殘留值會錯, 需清到 sz 為止
constexpr ll mxN=2e5+1;
constexpr ll mxT=7e6+1;
ll n,q,t[mxT],a[mxN],rt[mxN<<1],rsc,sz; int lc[mxT],rc[mxT];
void built(ll i,ll sl,ll sr){
	if(sl==sr){t[i]=a[sl]; return;}
	ll mid; mid=(sl+sr)>>1;
	lc[i]=++sz,rc[i]=++sz;
	built(lc[i],sl,mid);
	built(rc[i],mid+1,sr);
	t[i]=t[lc[i]]+t[rc[i]];
}
ll pst(ll pos,ll val,ll i,ll sl,ll sr){
	ll x; x=++sz;
	if(sl==sr){t[x]=val; return x;}
	ll mid; mid=(sl+sr)>>1;
	if(pos<=mid) lc[x]=pst(pos,val,lc[i],sl,mid),rc[x]=rc[i];
	else lc[x]=lc[i],rc[x]=pst(pos,val,rc[i],mid+1,sr);
	t[x]=t[lc[x]]+t[rc[x]];
	return x;
}
ll query(ll l,ll r,ll i,ll sl,ll sr){
	if(l>sr || r<sl) return 0;
	if(l<=sl && sr<=r) return t[i];
	ll mid; mid=(sl+sr)>>1;
	return query(l,r,lc[i],sl,mid)+query(l,r,rc[i],mid+1,sr);
}
void solve(istream &cin){
	cin>>n>>q;
	sz=rsc=0;
	forn(i,1,n+1) cin>>a[i];
	rt[++rsc]=++sz;
	built(rt[1],1,n);
	while(q--){
		ll op; cin>>op;
		if(op==3){
			ll k; cin>>k;
			rt[++rsc]=++sz;
			lc[rt[rsc]]=lc[rt[k]],rc[rt[rsc]]=rc[rt[k]],t[rt[rsc]]=t[rt[k]];
		}
		else if(op==1){
			ll k,a,x; cin>>k>>a>>x;
			rt[k]=pst(a,x,rt[k],1,n);
		}
		else{
			ll k,a,b; cin>>k>>a>>b;
			cout << query(a,b,rt[k],1,n) << '\n';
		}
	}
}
 
