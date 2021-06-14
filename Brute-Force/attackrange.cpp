#include <cstdio>
const int MAX = 100+10;
int data[MAX][MAX] = {0,};

int absNum(int a, int b)
{
  int num = a-b;
  if(num < 0) return -num;
  else return num;
}

int main()
{
  int n, x, y, r, dist;
  scanf("%d", &n);
  scanf("%d %d %d", &x, &y, &r);
  
  for(int i = x-r; i <= x+r; i++)
  {
    if(i < 1 || i > n) continue;
    for(int j = y-r; j <= y+r; j++)
    {
      if(j < 1 || j > n) continue;
      dist = absNum(x, i) + absNum(y, j);
      if(dist <= r) data[i][j] = dist;
    }
  }
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++) 
    {
      if(i == x && j == y) printf("x ");
      else printf("%d ", data[i][j]);
    }
    printf("\n");
  }
  return 0;
}