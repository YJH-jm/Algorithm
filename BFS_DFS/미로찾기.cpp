#include <cstdio>
#include <queue>

using std::queue;
const int MAX = 1000+10;
int n, m, myGraph[MAX][MAX]={0,}, sum[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {false, };
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct p
{
  int y, x;
};

p makeP(int y, int x)
{
  p tmp;
  tmp.y = y;
  tmp.x = x;
  return tmp;
}

void BFS(int y, int x)
{
  int ny, nx, cury, curx;
  queue <p> Queue;
  p cur;
  
  visited[y][x] = true;
  Queue.push(makeP(y, x));

  
  while(!Queue.empty())
  {
    cur = Queue.front();
    Queue.pop();
    cury = cur.y;
    curx = cur.x;
    
    for(int i = 0; i < 4; i++)
    {
      ny = cury + dy[i];
      nx = curx + dx[i];
      
      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if(!visited[ny][nx] && myGraph[ny][nx] == 0)
      {
        Queue.push(makeP(ny, nx));
        visited[ny][nx] = true;
        sum[ny][nx] = sum[cury][curx] + 1;
      }
    }
  }
}

int main()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++) scanf("%d", &myGraph[i][j]);
  }
  
  BFS(n-1, 0);
  
  printf("%d\n", sum[0][m-1]);
  return 0;
}