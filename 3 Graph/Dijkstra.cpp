void djk(){
	mls<pll> hp;
	res[1]=0,hp.emplace(pll{res[1],1});
	while(!hp.empty()){
		auto [d,u]=*hp.bg(); hp.erase(hp.bg());
		if(d>res[u]) continue;
		for(auto&[v,w]:adj[u]){
			if(w+res[u]<res[v]) res[v]=w+res[u],hp.emplace(pll{res[v],v});
		}
	}
}
