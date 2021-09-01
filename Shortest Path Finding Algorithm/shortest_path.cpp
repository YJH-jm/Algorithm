#include <cstdio>
#include <vector>
#include <algorithm>

// using namespace std;

using std::vector;

const int MAX = 10000+10;
vector <int> cost[MAX];
vector <int> graph[MAX];
bool check[MAX] = {false};
int Table[MAX];
int n, m, s, e;
int main()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    
    graph[a].push_back(b);
    graph[b].push_back(a);
    
    cost[a].push_back(1);
    cost[b].push_back(1);
    
  }
  
  scanf("%d %d", &s, &e);
  
  for(int i = 0; i < n; i++) Table[i] = 987987987;
  Table[s] = 0;
  
  for(int i = 0; i < n; i++)
  {
    int minValue = 987987987, index = -1;
    for(int j = 0; j  < n; j++)
    {
      if(!check[j] && minValue > Table[j])
      {
        minValue = Table[j];
        index = j;
      }
    }
    
    check[index] = true;
    
    for(int j = 0; j < graph[index].size(); j++)
    {
      int node2 = graph[index][j];
      int cost2 = cost[index][j];
      
      if(Table[node2] > Table[index]+cost2) Table[node2] = Table[index]+cost2;
    }
    
  }
  printf("%d\n", Table[e]);
  return 0;
}