void kmp(){
	forn(i,1,m){
		ll j; j=k[i-1];
		while(j>0 && s[j]!=s[i]) j=k[j-1];
		if(s[j]==s[i]) k[i]=j+1;
	}
}
void solve(istream &cin){
	cin>>n>>s;
	m=s.length();
	kmp();
	//forn(i,0,m){err(i,k[i]);}
	forn(i,0,m+1){
		forn(j,0,26){
			if(i>0 && (s[i]-'A')!=j) nex[i][j]=nex[k[i-1]][j];
			else nex[i][j]=i+(s[i]-'A'==j);
		}
	}
	// forn(i,0,m+1){forn(j,0,26){err(i,j,nex[i][j]);}}
	dp[0][0][0]=1;
	forn(i,0,n){
		forn(f,0,2){
			forn(j,0,m+1){
				forn(c,0,26){
					// err(i,j,c,nex[j][c],dp[i][j]);
					ll nf; nf=f|(nex[j][c]==m);
					dp[i+1][nex[j][c]][nf]=(dp[i+1][nex[j][c]][nf]+dp[i][j][f])%mdl1;
				}
			}
		}
	}
	ll res; res=0;
	forn(i,0,m+1) res=(res+dp[n][i][1])%mdl1;
	cout << res << '\n';
}

