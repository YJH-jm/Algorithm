#include <cstdio>
const int MAX = 100+10;
int count[MAX] = {0,};
int main()
{
  int sum=0, value, maxValue = -1, maxIndex; 
  for(int i = 0; i < 10; i++)
  {
    scanf("%d", &value);
    sum += value;
    count[value/10]++;
  }
  
  for(int i = 0; i < MAX; i++)
  {
    if(count[i] > maxValue){
      maxValue =  count[i];
      maxIndex = i * 10;
    }
  }
  
  printf("%d\n", sum/10);
  printf("%d\n", maxIndex);
  
  return 0;
}