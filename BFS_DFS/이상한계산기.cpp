#include <cstdio>
#include <queue>
using std::queue;
const int MAX = 100000+10;
int n, count[MAX] = {0,};
bool visited[MAX] = {false, }, flag = false; 

int main()
{
  scanf("%d", &n);
  int size;
  int cur, next;
  queue <int> Queue;
  Queue.push(1);
  visited[1] = true;
  while(!Queue.empty())
  {
    size = Queue.size();
    for(int i = 0; i < size; i++)
    {
      cur = Queue.front();
      Queue.pop();
      
      next = cur*2;
      if(next <= 99999 && next >= 1 && !visited[next]) 
      {
        Queue.push(next);
        visited[next] = true;
        count[next] = count[cur]+1;
      }
      
      next = cur/3;
      if(next <= 99999 && next >= 1&& !visited[next]) 
      {
        Queue.push(next);
        visited[next] = true;
        count[next] = count[cur]+1;
      }
    }
  }
  printf("%d",count[n]);
  return 0;
}