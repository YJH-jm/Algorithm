/*
백준 5692문제 - 팩토리얼 진법
https://www.acmicpc.net/problem/5692
*/

#include <cstdio>
#include <cstring>

const int MAX = 10;
int main()
{
    char str[MAX];
    int len, sum = 0, num = 1, num_str;
    while(true)
    {
        scanf("%s", str);
       
        
        if(strcmp(str, "0") == 0) break;
        
        len = strlen(str);
        sum = 0;
        num = 1;
        
        for(int i = 0; i < len; i++)
        {
            num *= (i+1);
            num_str = str[len-1-i] - '0';
            // printf("%d %d\n", num, num_str);
            sum += num_str*num;
        }
        printf("%d\n", sum);
    }
    return 0;
}