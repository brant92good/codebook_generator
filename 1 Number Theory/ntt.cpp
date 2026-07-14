using ll=long long;
// 注意: 兩模數CRT, 結果是真值 mod 998244353*1004535809 (~1.0028e18)
// 真實係數必須 < 該值 (值域1e9且長度>~1000就會爆), 否則需三模數NTT
// 長度上限 2^21 (n+m <= ~2e6): fft2 模數只有 2^21 階單位根, 超過會靜默出錯
 class FFT{
	public:
		ll mod,root,root_inv,maX,M,M_inv;
		FFT(){}
		FFT(ll a,ll b,ll c,ll d,ll e,ll f):mod(a),root(b),root_inv(c),maX(d),M(e),M_inv(f){}
		ll fsp(ll a,ll m){
			ll ans=1;
			while(m){
				if(m&1) ans=(ans*a)%mod;
				a=(a*a)%mod,m>>=1;
			}
			return ans;
		}
		void fft(ll sz,vc<ll> &arr,ll inv){
			for(ll i=1,j=0;i<sz;++i){
				ll bit=sz>>1; for(;j&bit;bit>>=1) j^=bit; j^=bit;
				if(i<j) swap(arr[i],arr[j]);
			}
			for(ll l=2;l<=sz;l<<=1){
				ll wlen=inv?root_inv:root;
				for(ll i=l;i<maX;i<<=1) wlen=(wlen*wlen)%mod;
				for(ll i=0;i<sz;i+=l){
					ll w=1;
					for(ll j=0;j<l/2;++j){
						ll x=arr[i+j],y=(w*arr[i+j+l/2])%mod;
						arr[i+j]=(x+y<mod?x+y:x+y-mod);
						arr[i+j+l/2]=(x-y>=0?x-y:x-y+mod);
						w=(w*wlen)%mod;
					}
				}
			}
			if(inv){
				ll n_1=fsp(sz,mod-2);
				forn(i,0,sz){
					arr[i]=(arr[i]*n_1)%mod;
				}
			}
		}
};
constexpr ll MM=1002772198720536577;
ll mul(ll a,ll b){
	__int128 aa=a,bb=b,cc;
	cc=(aa*bb)%MM;
	return (ll)cc;
}
void solve(){
	FFT fft1(998244353,15311432,469870224,1<<23,1004535809,332747959);
	FFT fft2(1004535809,702606812,700146880,1<<21,998244353,669690699);
	ll n,m;
	cin >> n >> m;
	vc<ll> a(n+1),b(m+1);
	for(auto &v:a) cin >> v;
	for(auto &v:b) cin >> v;
	ll sz=1;
	for(;sz<a.size()+b.size();sz<<=1);
	a.resize(sz),b.resize(sz);
	vc<ll> A=a,B=b;
	fft1.fft(sz,a,0);
	fft1.fft(sz,b,0);
	forn(i,0,sz) a[i]=(a[i]*b[i])%fft1.mod;
	fft1.fft(sz,a,1);

	fft2.fft(sz,A,0);
	fft2.fft(sz,B,0);
	forn(i,0,sz) A[i]=(A[i]*B[i])%fft2.mod;
	fft2.fft(sz,A,1);

	forn(i,0,n+m+1) cout << (mul(a[i],fft1.M*fft1.M_inv) + mul(A[i],fft2.M*fft2.M_inv))%MM << " \n"[i==n+m];
}
int main()
{
    fast_io;
    int testcase;
    // cin>>testcase;
    testcase=1;
    while(testcase--)
        solve();
    return 0;
}
