//undirected graph articulation point; root呼叫 tarjan(1,0), 不連通圖每個分量都要跑
ll n,tim=0,art=0;
vc<ll> dfn(mxN,0),low(mxN);
void tarjan(ll u,ll p){
    ll cnt=0; bool isArt=false;
    dfn[u]=low[u]=++tim;
    for(auto&v:adj[u]){
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u] && p) isArt=true; //非root: 某子樹回不到u之上
            cnt++;
        }
        else if(v!=p) low[u]=min(low[u],dfn[v]);
    }
    if(!p && cnt>1) isArt=true; //root: 至少兩個子樹
    art+=isArt;
}
