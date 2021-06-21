#include <cstdio>
#include <cstring>
#include <queue>
using std::queue;

const int MAX = 1000+10;
int myGraph[MAX][MAX], countStart[MAX][MAX] = {0,}, countEnd[MAX][MAX]={0,};
bool visited[MAX][MAX] = {false, };
int n, m;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};


struct p{
  int y, x;
};

p makeP(int y, int x)
{
  p tmp;
  tmp.y = y;
  tmp.x = x;
  return tmp;
}
void BFS(int cury, int curx, int count[][MAX])
{
  p cur;
  int y, x, ny, nx;
  queue <p> Queue;
  Queue.push(makeP(cury, curx));
  visited[cury][curx] = true;
  count[cury][curx] = 0;
  
  while(!Queue.empty())
  {
    cur = Queue.front();
    Queue.pop();
    y = cur.y;
    x = cur.x;
    
    for(int i = 0; i < 4; i++)
    {
      ny = y + dy[i];
      nx = x + dx[i];
      
      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      
      if(!visited[ny][nx]) 
      {
        if(myGraph[ny][nx] == 0)
        {
           Queue.push(makeP(ny, nx));
        }
        visited[ny][nx] = true;
        count[ny][nx] = count[y][x]+1;
      }
    }
  }
  return;
}


int main()
{
  int  minDist = MAX*MAX, sum;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++) scanf("%d", &myGraph[i][j]);
  }
  
  BFS(n-1, 0, countStart);
  memset(visited, false, sizeof(visited));
  BFS(0, m-1, countEnd);
  
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++) 
    {
      if(countStart[i][j] != 0 && countEnd[i][j] != 0)
      {
        sum = countEnd[i][j] + countStart[i][j];
        if(sum < minDist) minDist = sum;
      }
    }
  }
  printf("%d\n", minDist);
  return 0;
}