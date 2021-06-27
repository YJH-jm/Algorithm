#include <cstdio>
const int MAX = 25;
int map[MAX][MAX];
int c, r;
int main()
{
  int maxX = 0, maxY = 0, cnt, value = 0;
  bool flag; 
  scanf("%d %d", &c, &r);
  
  for(int i = 1; i <= r; i++)
  {
    for(int j = 1; j <= c; j++) scanf("%d", &map[i][j]);
  }
  
  for(int i = 1; i <= c; i++)
  {
    cnt = 0;
    for(int j = 1; j <= r; j++)
    {
      if(map[j][i] == 1) break;
      cnt++;
    }
    if(cnt >= 4)
    {
      if(maxY < cnt) 
      {
        maxY = cnt;
        maxX = i;
      }
    }
  }
  
  if(maxY == 0)
  {
    printf("0 0\n");
    return 0;
  }
  
  for(int i = maxY; i > maxY-4; i--)
  {
    map[i][maxX] = 1;
    flag = false;
    for(int j = 1; j <= c; j++)
    {
      if(map[i][j] == 0)
      {
        flag = true;
        break;
      }
    }
    if(!flag) value++;
  }
  if(value == 0) printf("0 0\n");
  else printf("%d %d\n", maxX, value);
  return 0;
}