/*
백준 15829문제 - hashing
https://www.acmicpc.net/problem/15829
*/

#include <cstdio>

const int r = 31;
const int m = 1234567891;

int main()
{
  int n, value_num;
  long long int sum = 0, num = 1; // 중요!
  char value;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf(" %1c", &value);
    value_num = value - 'a' + 1;
    sum = (sum +value_num * num) % m;
    num = (num*r) % m;
    
  }
  printf("%d\n", sum);
  return 0;
}