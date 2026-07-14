ll dp[mxN][2]{},n,res[mxN];
void solve(istream &cin){
	cin >> s,n=s.length();
	ll l1,l2,r1=-1,r2=-1;
	forn(i,0,n) res[i]=1;
	forn(i,0,n){
		if(r1>i) dp[i][1]=min(r1-i,dp[l1+r1-i][1]);
		if(r2>i) dp[i][0]=min(r2-i,dp[l2+r2-i-1][0]);
		while(i+dp[i][1]<n && i-dp[i][1]>=0 && s[i+dp[i][1]]==s[i-dp[i][1]]) res[i+dp[i][1]]=max(res[i+dp[i][1]],2*dp[i][1]+1),dp[i][1]++;
		while(i+dp[i][0]+1<n && i-dp[i][0]>=0 && s[i+dp[i][0]+1]==s[i-dp[i][0]]) res[i+dp[i][0]+1]=max(res[i+dp[i][0]+1],2*(dp[i][0]+1)),dp[i][0]++;
		if(i+dp[i][1]>r1) l1=i-dp[i][1],r1=i+dp[i][1];
		if(i+dp[i][0]>r2) l2=i-dp[i][0]+1,r2=i+dp[i][0];
	}
	forn(i,0,n) cout << res[i] << " \n"[i==n-1];
}
