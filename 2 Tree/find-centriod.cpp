void dfs(ll u=1,ll p=0){
    d[u]=1;
    for(auto&v:adj[u]){
        if(v==p)
            continue;
        dfs(v,u);
        d[u]+=d[v];
    }
}
ll dfs_solve(ll u=1,ll p=0){
    for(auto&v:adj[u]){
        if(v==p)
            continue;
        if(d[v]*2>n) return dfs_solve(v,u);
    }
    return u;
}
