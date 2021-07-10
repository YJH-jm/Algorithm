#include <cstdio>
#include <cstring>

const int MAX = 15;
int resultMin[MAX] = {0,}, resultMax[MAX] = {0,};
char input[MAX];
int k;
bool check[MAX] = {false,}, maxFlag = false, minFlag = false;

void getMax(int x)
{
  if(maxFlag) return;
  if(x > k)
  {
    for(int i = 0; i <= k; i++) printf("%d", resultMax[i]);
    maxFlag = true;
    return;
  }
  
  for(int i = 9; i >= 0; i--)
  {
    if(x == 0)
    {
      if(!check[i])
      {
        resultMax[x] = i;
        check[i] = true;
        getMax(x+1);
        check[i] = false; 
      }
    }
    else
    {
      if(input[x-1] == '>')
      {
        if(resultMax[x-1] > i && !check[i])
        {
          resultMax[x] = i;
          check[i] = true;
          getMax(x+1);
          check[i] = false;
        }
      }
      else if(input[x-1] == '<')
      {
        if(resultMax[x-1] < i && !check[i])
        {
          resultMax[x] = i;
          check[i] = true;
          getMax(x+1);
          check[i] = false;
        }
      }
    }
  }
}


void getMin(int x)
{
  if(minFlag) return;
  if(x > k)
  {
    for(int i = 0; i <= k; i++) printf("%d", resultMin[i]);
    minFlag = true;
    return;
  }
  
  for(int i = 0; i <= 9; i++)
  {
    if(x == 0)
    {
      if(!check[i])
      {
        resultMin[x] = i;
        check[i] = true;
        getMin(x+1);
        check[i] = false; 
      }
    }
    else
    {
      if(input[x-1] == '>')
      {
        if(resultMin[x-1] > i && !check[i])
        {
          resultMin[x] = i;
          check[i] = true;
          getMin(x+1);
          check[i] = false;
        }
      }
      else if(input[x-1] == '<')
      {
        if(resultMin[x-1] < i && !check[i])
        {
          resultMin[x] = i;
          check[i] = true;
          getMin(x+1);
          check[i] = false;
        }
      }
    }
  }
}


int main()
{
  scanf("%d", &k);
  for(int i = 0; i < k;  i++) scanf(" %c", &input[i]);
  getMax(0);
  memset(check, false, sizeof(check));
  printf("\n");
  getMin(0);
  return 0;
}