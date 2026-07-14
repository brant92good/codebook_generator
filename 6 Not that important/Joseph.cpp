// 回傳 0-indexed 的倖存者位置
ll josephus(ll n, ll k) { // O(n)
  ll res = 0;
  for (ll i = 1; i <= n; ++i) res = (res + k) % i;
  return res;
}
ll josephus2(ll n, ll k) { // O(k log n), k<=n 時用; k>n 落回迴圈版避免深遞迴爆棧
  if (n == 1) return 0;
  if (k == 1) return n - 1;
  if (k > n) {
    ll res = 0;
    for (ll i = 2; i <= n; ++i) res = (res + k) % i;
    return res;
  }
  ll res = josephus2(n - n / k, k);
  res -= n % k;
  if (res < 0)
    res += n;  // mod n
  else
    res += res / (k - 1);  // 还原位置
  return res;
}
