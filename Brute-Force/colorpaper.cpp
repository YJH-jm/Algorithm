#include <cstdio>
const int MAX = 100+10;
int data[MAX][MAX] = {0,};
int count[MAX] = {0,};

void setPaper(int y, int x, int a, int b, int cnt)
{
  for(int i = y; i < y + a; i++)
  {
    for(int j = x; j < x + b; j++) data[i][j] = cnt;
  }
}

int main()
{
  int n, cnt = 0;
  int y, x, a, b;
  
  scanf("%d", &n);
  
  while(cnt < n)
  {
    cnt++;
    scanf("%d %d %d %d", &y, &x, &a, &b);
    setPaper(y, x, a, b, cnt);
  }
  
  for(int i = 0; i < 101; i++)
  {
    for(int j = 0; j < 101; j++) count[data[i][j]]++;
  }
  
  for(int i = 1; i <= n; i++) printf("%d\n", count[i]);
  
  return 0;
}