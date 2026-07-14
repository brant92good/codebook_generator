//SPFA; 回傳false=有負環(僅偵測從start可達的); d[]需外部初始化INF, d[start]=0
bool spfa(){
    vc<ll> vs(n+1,0); //1-indexed 要開 n+1
    queue<ll> q; q.emplace(start);
    while(!q.empty()){
        ll u=q.front(); q.pop(),vs[u]=0;
        for(auto&[v,w]:adj[u]){
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!vs[v]){vs[v]=1,cnt[v]++; if(cnt[v]>n) return false; q.emplace(v);}
            }
        }
    }
    return true;
}
