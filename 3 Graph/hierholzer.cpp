//debrujin sequence 特化版(n<=15), 不是通用歐拉迴路模板, 一般題要整段改寫
ll n;
string s;
vc<ll> adj[1<<14|1];
void dfs(ll u=0){
    while(!adj[u].empty()){
        ll v; v=adj[u].back(); adj[u].pop_back();
        dfs(v);
        s+=(v&1)?'1':'0';
    }
}
void solve(istream &cin){
    cin>>n;
    if(n==1){cout << "01" << '\n'; return;}
    forn(i,0,1<<(n-1)){
        adj[i].emp((i<<1)&((1<<(n-1))-1));
        adj[i].emp((i<<1|1)&((1<<(n-1))-1));
    }
    dfs();
    forn(i,0,n-1) s+='0';
    reverse(all(s));
    cout << s << '\n';
}
