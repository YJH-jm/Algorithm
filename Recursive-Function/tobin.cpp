#include <cstdio>
const int MAX = 35;
int n, k;
int result[MAX] = {0,};

void getResult(int x, int num)
{
  if(x < n && num == k)
  {
    for(int i = 0; i < n; i++) printf("%d", result[i]);
    printf("\n");
    return;
  }
  
  if(x >= n)
  {
    if(num == k)
    {
      for(int i = 0; i < n; i++) printf("%d", result[i]);
      printf("\n");
    }
    return;
  }
  
  for(int i = 1; i >= 0; i--)
  {
    result[x] = i;
    if(i == 0) getResult(x+1, num);
    else if(i == 1) getResult(x+1, num+1);
  }
}

int main()
{
  scanf("%d %d", &n, &k);
  getResult(0, 0);
  return 0;
}