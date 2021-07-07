/*
백준 10829문제 - 팩토리얼
https://www.acmicpc.net/problem/10829
*/

#include <cstdio>

int factorial(int n)
{
  if(n == 0) return 1;
  else return n * factorial(n-1);
}

int main()
{
  int n;
  scanf("%d", &n);
  printf("%d\n", factorial(n));
  return 0;
}