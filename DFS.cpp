#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cin >> n >> m;
for (int i = 0; i < n; i++)
for (int j = 0; j < m; j++)
cin >> board[i][j];
int mx = 0;
int num = 0;
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
if (board[i][j] == 0 || vis[i][j]) continue;
num++;
stack<pair<int, int> > S;
vis[i][j] = 1;
S.push({ i,j });
int area = 0;
while (!S.empty()) {
area++;
pair<int, int> cur = S.top(); S.pop();
for (int dir = 0; dir < 4; dir++) {
int nx = cur.X + dx[dir];
int ny = cur.Y + dy[dir];
if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
if (vis[nx][ny] || board[nx][ny] != 1) continue;
vis[nx][ny] = 1;
S.push({ nx,ny });
}
}
mx = max(mx, area);
}
}
cout << num << '\n' << mx;
}
