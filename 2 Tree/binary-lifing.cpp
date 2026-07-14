constexpr ll mxN=2e5+1;
ll n,q,p[mxN][20]={0}; //深度<mxN<2^18, 20層夠(49MB->32MB); n更大要加層數
vc<ll> adj[mxN];
void solve(istream &cin){
    cin>>n>>q;
    forn(i,2,n+1) cin>>p[i][0];
    forn(j,1,20) forn(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
    while(q--){
        ll x,k; cin>>x>>k;
        k=min(k,(ll)mxN); // 跳超過深度必到0, clamp避免高位bit被忽略
        forn(i,0,20) if(k>>i&1) x=p[x][i];
        cout << (x?x:-1) << '\n';
    }
}
