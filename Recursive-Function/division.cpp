#include <cstdio>
int n, cnt = 0;
const int MAX = 30;
int result[MAX];

void getResult(int x, int sum)
{
  int myNum;
  if(sum == n)
  {
    for(int i = 0; i < x-1; i++) printf("%d+", result[i]);
    printf("%d\n", result[x-1]);
    cnt++;
    return;
  }
  
  if(x == 0) myNum = n-1;
  else myNum = n-sum;
  
  for(int i = myNum; i >= 1; i--)
  {
    if(x == 0) 
    {
      result[x] = i;
      getResult(x+1, sum+i);
      result[x] = 0;
    }
    else
    {
      if(result[x-1] >= i)
      {
        result[x] = i;
        getResult(x+1, sum+i);
        result[x] = 0;
      }
    }
  }
}

int main()
{
  scanf("%d", &n);
  getResult(0, 0);
  printf("%d\n", cnt);
  return 0;
}