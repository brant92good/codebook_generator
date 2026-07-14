array<ll,2> exgcd(ll a, ll b){
	if(b == 0) return array<ll,2>{1,0};
	auto ans = exgcd(b, a % b);
	return array<ll,2>{ans[1], ans[0] - a / b * ans[1]};
}

