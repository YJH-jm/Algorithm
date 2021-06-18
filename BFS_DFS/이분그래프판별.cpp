// 이분 그래프 탐색

#include <cstdio>
#include <vector>
using std::vector;
const int MAX = 1000+10;
vector <int>myGraph[MAX];
bool visited[MAX] = {false, };
int color[MAX] = {0,};
int n, m;
bool flag= false;

void DFS(int cur, int c)
{
  int c2, next;
  visited[cur] = true;//방문함
  color[cur] = c;
  if(c == 1) c2 = 2;
  else if(c == 2) c2 = 1;
  
  for(int i = 0; i < myGraph[cur].size(); i++)
  {
    next = myGraph[cur][i];
    
    if(color[next]!= 0 && color[next] == c)
    {
      flag = true;
      return;
    }
    if(!visited[next])
    {
      DFS(next, c2);
    }
  }
  
}
int main()
{
  int a, b;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d", &a, &b);
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  DFS(1, 1);
  if(flag) printf("No\n");
  else printf("Yes\n");
  return 0;
}