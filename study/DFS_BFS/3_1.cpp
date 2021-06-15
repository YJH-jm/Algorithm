/*
백준 1260문제 - DFS와 BFS 
https://www.acmicpc.net/problem/1260
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using std::sort;
using std::queue;
using std::vector;

const int MAX = 1000+10;
vector <int>myGraph[MAX];
bool visited[MAX] = {false};

void DFS(int cur)
{
    int next;
    printf("%d ", cur);
    visited[cur] = true; //방문함

    for(int i = 0; i < myGraph[cur].size(); i++)
    {
        next = myGraph[cur][i];
        if(!visited[next]) DFS(next);
    }
}

void BFS(int current)
{
    int next, cur;
    queue <int> Queue;
    
    Queue.push(current);
    visited[current] = true;

    while(!Queue.empty())
    {
        cur = Queue.front();
        Queue.pop();
        printf("%d ", cur);

        for(int i = 0; i < myGraph[cur].size(); i++)
        {
            next = myGraph[cur][i];
            if(!visited[next])
            {
                Queue.push(next);
                visited[next]=true;
            }
        }
        
    }
}

int main()
{
  int n, m, v;
  int a, b;
  scanf("%d %d %d", &n, &m, &v);
  for(int i = 0; i < m; i++)
  {
      scanf("%d %d", &a, &b);
      myGraph[a].push_back(b);
      myGraph[b].push_back(a);
  }
  for(int i =  0; i < n; i++)
  {
    sort(myGraph[i].begin(), myGraph[i].end());
  }
  DFS(v);
  memset(visited, false, sizeof(visited));
  printf("\n");
  BFS(v);

  return 0;
}