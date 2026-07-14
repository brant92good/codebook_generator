// 先設 f[x][x]=0 其餘INF (INF用0x3f3f3f3f3f3f3f3f可安全相加)
for (ll k = 1; k <= n; k++) {
  for (ll x = 1; x <= n; x++) {
    for (ll y = 1; y <= n; y++) {
      f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
    }
  }
}
