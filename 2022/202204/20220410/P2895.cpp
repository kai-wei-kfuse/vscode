#include <iostream>
#include <queue>
using namespace std;
struct aa {
    int x, y, t;
} a[500005];
int xx[] = {-1, 0, 1, 0};
int yy[] = {0, 1, 0, -1};
int vis[305][305];
queue<aa> Q;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].x >> a[i].y;
    }
    Q.push({0, 0, 0});
    vis[0][0] = 1;
    while(!Q.empty()){
        aa tmp = Q.front();
        Q.pop();
        for (int i = 0; i < 4;i++){
            int x = tmp.x + xx[i];
            int y = tmp.y + yy[i];
            if(x>=0 &&y>=0&& x<=300&&y<=300)
        }
    }
}