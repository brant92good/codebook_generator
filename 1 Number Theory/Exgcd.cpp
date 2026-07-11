array<int,2> exgcd(int a, int b){
	if(b == 0) return array<int,2>{1,0};
	auto ans = exgcd(b, a % b);
	return array<int,2>{ans[1], ans[0] - a / b * ans[1]};
}

