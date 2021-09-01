#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;

vector <int> graph[MAX];
vector <int> cost[MAX];

int n, m, start, end2;

int Table[MAX];
bool Check[MAX]; //Check[i] = True 라는 말은 이미 i의 최단거리가 확정
int main()
{
  scanf("%d %d %d %d ", &n, &m, &start, &end2);
  
  for(int i =0 ; i< m; i++){
  
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    // gragh[1] : 2, 6, 8, 9 <인접리스트>
    // cost[1] : 1, 1, 3, 9 <가중치>
    
    graph[a].push_back(b);
    graph[b].push_back(a);
    
    cost[a].push_back(c);
    cost[b].push_back(c);
  }
  for(int i =0; i <n; i++) Table[i] = 987987987;
  Table[start] = 0;
  
  for(int i = 0; i < n; i++){
    // (1) 최솟값을 구한다. 단, 지금까지 최단거리로 확정되지 않았던 정점에 대해서
    // (2) 그 최솟값을 갖는 노드로부터 뻗어나간다.
    int minValue = 987987987, index = -1;
    for(int j = 0; j < n; j++){ // 지금까지 최솟값을 찾지 않는 것들 중 최솟값을 찾고 
      if(!Check[j] && minValue > Table[j]){
        minValue = Table[j];
        index = j;
      }
    }
    Check[index] = true;
    
    for(int j = 0; j < graph[index].size(); j++) // 인접 리스트 근처를 돌겠다
    {
      int Node2 = graph[index][j];
      int Cost2 = cost[index][j];
      
      // minIndex --(Cost2)-- Node2
      
      //minIndex를 거쳐서 Node2를 가는 것이 이득인지를 확인
      
      if(Table[Node2] > Table[index] + Cost2){
        Table[Node2] = Table[index] + Cost2;
      }
    }
  }
  
  printf("%d\n", Table[end2]);
  return 0;
}