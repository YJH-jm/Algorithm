#include <cstdio>
const int MAX = 8 + 5;
int data[MAX][MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main()
{
  int i = 1, nY, nX, kingX, kingY;
  for(int i = 1; i <= 8; i++)
  {
    for(int j = 1; j <= 8; j++) 
    {
      scanf("%d", &data[i][j]);
      if(data[i][j] == 1)
      {
        kingY = i;
        kingX = j;
      }
    }
  }

  
  
  for(int k = 0; k < 4; k++)
  {
    i = 1;
    while(1)
    {
      nY = kingY + i*dy[k];
      nX = kingX + i*dx[k];
      
      if(nY < 1 || nY > 8 || nX < 1 || nX > 8) break;
      else if(data[nY][nX] == 3) break;
      else if(data[nY][nX] == 2)
      {
        printf("1\n");
        return 0;
      }
      i++;
    }
  }
  printf("0\n");
  return 0;
}