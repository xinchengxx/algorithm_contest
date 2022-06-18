#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int nx[] = {-1, 0, 1, 0};
const int ny[] = {0, 1, 0, -1};

int T_T, N, M, L, B, bit, sx, sy, sd;
bool vis[21][21][1<<14|1], blank[21][21];

struct node {
    int x, y, d, s;
    node(int x=0, int y=0, int d=0, int s=0): x(x), y(y), d(d), s(s) {}
    bool block(int x, int y) {
        if( x >= 1 && y >= 1 && x <= N && y <= M && blank[x][y] ) {
            int mx = this->x;
            int my = this->y;
            int md = this->d;
            for(int i=1; i < L; ++i) {
                int d = md & 3;
                mx += nx[d]; my += ny[d]; md >>= 2;
                if( mx == x && my == y ) return true;
            }
            return false;
        }
        return true;
    }
};

queue<node> Q;

int BFS() {
    while( !Q.empty() ) Q.pop();
    Q.push(node(sx, sy, sd));
    vis[sx][sy][sd] = true;

    while( !Q.empty() ) {
        node now = Q.front(); Q.pop();

        if( now.x == 1 && now.y == 1 ) return now.s;
        for(int d=0; d < 4; ++d) {
            int mx = now.x + nx[d];
            int my = now.y + ny[d];
            if( !now.block(mx, my) ) {
                int md = ((now.d<<2)&bit) | (d^2);
                if( vis[mx][my][md] ) continue;
                vis[mx][my][md] = true;
                Q.push(node(mx, my, md, now.s+1));
            }
        }
    }

    return -1;
}

void work() {
    while( scanf("%d%d%d", &N, &M, &L) == 3 && N && M && L ) {
        bit = (1<<(L-1<<1))-1;
        for(int n=1; n <= N; ++n)
            for(int m=1; m <= M; ++m)
                memset(vis[n][m], 0, bit+1);
        memset(blank, 1, sizeof blank);

        scanf("%d%d", &sx, &sy); sd = 0;
        int mx = sx, my = sy, mu, mv;
        for(int i=0; i < L-1; ++i) {
            scanf("%d%d", &mu, &mv);
            for(int d=0; d < 4; ++d) if( mx+nx[d] == mu && my+ny[d] == mv ) {
                sd |= d<<(i<<1);
                mx = mu; my = mv;
                break;
            }
        }
        scanf("%d", &B);
        while( B-- ) {
            scanf("%d%d", &mu, &mv);
            blank[mu][mv] = false;
        }

        printf("Case %d: %d\n", ++T_T, BFS());
    }
}

int main()
{
    work();
    return 0;
}