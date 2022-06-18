#include<bits/stdc++.h>
struct edge {
  int a;
  int b;
  double r;
  double c;
};
int bellman_ford(double d[], struct edge x[], int n, int m, int s, double v) {
  int i, j, flag;
  d[s] = v;
  for (i = 1; i <= n - 1; i++) {
    flag = 0;
    for (j = 0; j < 2 * m; j++) {
      if (d[x[j].b] < (d[x[j].a] - x[j].c) * x[j].r) {
        d[x[j].b] = (d[x[j].a] - x[j].c) * x[j].r;
        flag = 1;
      }
    }
    if (!flag) break;
  }
  for (j = 0; j < 2 * m; j++) {
    if (d[x[j].b] < (d[x[j].a] - x[j].c) * x[j].r) return 1;
  }
  return 0;
}
int main() {
  int n, m, s, i, t = 0;
  struct edge x[202];
  double v, d[101] = {
    0
  };
  scanf("%d%d%d%lf", & n, & m, & s, & v);
  for (i = 0; i < m; i++) {
    scanf("%d%d%lf%lf", &
      x[t].a, & x[t].b, & x[t].r, & x[t].c);
    t++;
    x[t].a = x[t - 1].b;
    x[t].b = x[t - 1].a;
    scanf("%lf%lf", & x[t].r, & x[t].c);
    t++;
  }
  if (bellman_ford(d, x, n, m, s, v)) printf("YES\n");
  else printf("NO\n");
  return 0;
}