#include <cstdio>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
const int MAX = 25+10;
int n, myGraph[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {false, };
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int DFS(int cury, int curx)
{
  int ny, nx, cnt = 0;
  visited[cury][curx] = true;
  cnt++;
  for(int i = 0; i < 4; i++)
  {
    ny = cury + dy[i];
    nx = curx + dx[i];
    
    if(myGraph[ny][nx]== 1 && !visited[ny][nx])
    {
      cnt+=DFS(ny,nx);
    }
  }
  return cnt;
}
int main()
{
  vector <int> result;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++) scanf("%1d", &myGraph[i][j]);
  }
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      if(myGraph[i][j] == 1 && !visited[i][j])
      {
        result.push_back(DFS(i, j));
      }
    }
  }
  sort(result.begin(), result.end());
  printf("%d\n", result.size());
  for(int i = 0; i < result.size(); i++)
  {
    printf("%d\n", result[i]);
  }
  
  return 0;
}