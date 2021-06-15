/*
백준 2606문제 - 바이러스 
https://www.acmicpc.net/problem/2606
*/

#include <cstdio>
#include <vector>

using std::vector;

const int MAX = 100+10;
vector <int> myGraph[MAX];
bool visited[MAX] = {false, };

int DFS(int cur)
{
  int cnt = 0;
  visited[cur] = true;
  cnt++;
  
  for(int i = 0; i < myGraph[cur].size(); i++)
  {
    int next = myGraph[cur][i];
    if(!visited[next])
    {
      cnt += DFS(next);
    }
  }
  return cnt;
}
int main()
{
  int n, m;
  int a, b;
  int count; 
  
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d", &a, &b);
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  
  count = DFS(1);
  printf("%d", count-1);
  return 0;
}