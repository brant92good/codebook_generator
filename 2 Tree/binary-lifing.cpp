constexpr ll mxN=2e5+1;
ll n,q,p[mxN][31]={0};
vc<ll> adj[mxN];
void solve(istream &cin){
    cin>>n>>q;
    forn(i,2,n+1) cin>>p[i][0];
    forn(j,1,31) forn(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
    while(q--){
        ll x,k; cin>>x>>k;
        forn(i,0,30) if(k&(1<<i)) x=p[x][i];
        cout << (x?x:-1) << '\n';
    }
}
