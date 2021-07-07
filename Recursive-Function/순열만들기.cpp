#include <cstdio>
const int MAX = 15;
char result[MAX];
bool check[MAX] = {false, };
int n, r;

void getResult(int x)
{
  char alpha;
  if(x >= r)
  {
    for(int i = 0; i < r; i++) printf("%c", result[i]);
    printf("\n");
    return;
  }
  
  for(int i = 0; i < n; i++)
  {
    alpha = 'a' + i;
    if(!check[i])
    {
      result[x] = alpha;
      check[i] = true;
      getResult(x+1);
      result[x] = 0;
      check[i] = false;
    }
  }
}

int main()
{
  scanf("%d %d", &n, &r);
  
  getResult(0);
  
  return 0;
}