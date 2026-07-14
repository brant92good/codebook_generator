// 10進位string(只含0~9, 長度<=500) 轉 bitset 二進位, 支援先減一個小常數
// decSub(s,x): 回傳 s-x (x>=0, 需保證 s>=x), O(len)
// decToBits(s): 10進string -> bitset, b[0]為LSB, O(len^2)
// bitsToDec(b): bitset -> 10進string, 驗證/輸出用
// 500位10進 ≈ 1661 bits, mxB=2048 夠用
constexpr ll mxB=2048;
string decSub(string s,ll x){
	for(ll i=s.size()-1;i>=0&&x;i--){
		ll d=(s[i]-'0')-x%10; x/=10;
		if(d<0){d+=10; x++;}
		s[i]=d+'0';
	}
	ll p=0; while(p+1<(ll)s.size()&&s[p]=='0') p++;
	return s.substr(p);
}
bitset<mxB> decToBits(string s){
	bitset<mxB> b;
	for(ll i=0;s!="0";i++){
		b[i]=(s.back()-'0')&1;
		ll r=0;
		for(char &c:s){ll d=r*10+(c-'0'); c='0'+d/2; r=d&1;}
		ll p=0; while(p+1<(ll)s.size()&&s[p]=='0') p++;
		s=s.substr(p);
	}
	return b;
}
string bitsToDec(bitset<mxB> b){
	string s="0";
	ll hi=mxB-1; while(hi>0&&!b[hi]) hi--;
	forr(i,hi,0){
		ll c=b[i];
		forr(j,(ll)s.size()-1,0){ll d=(s[j]-'0')*2+c; s[j]='0'+d%10; c=d/10;}
		if(c) s=char('0'+c)+s;
	}
	return s;
}
void solve(istream &cin){
	string s; ll k;
	cin>>s>>k; // 10進string 與 要減的常數
	bitset<mxB> b=decToBits(decSub(s,k));
	ll hi=mxB-1; while(hi>0&&!b[hi]) hi--;
	forr(i,hi,0) cout<<b[i]; // MSB->LSB 印出2進位
	cout<<'\n';
}
