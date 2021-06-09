// 숫자카드2 - https://www.acmicpc.net/problem/10816
#include <cstdio>
#include <algorithm>

using std::sort;
//using namespace std; 백준에서 사용하면 compile error 발생

const int MAX = 500010;
int n, m;
int data[MAX];

int getStartIndex(int start, int end, int value)
{
    //start는 항상 구하고자 하는 값보다 작다
    //end는 항상 구하고자 하는 값보다 같거나 크다
    int mid, s, e;
    if(value < data[start]) return -1;
    else if(value == data[start]) return start;
    
    s = start;
    e = end;
    
    while(s+1 != e)
    {
        mid = (s+e)/2;
        if(data[mid] < value) s = mid;
        else e = mid;
    }
    
    return e;
}

int getEndIndex(int start, int end, int value)
{
    //start는 항상 구하고자 하는 값보다 작거나 같다
    //end는 항상 구하고자 하는 크다
    int mid, s, e;
    if(value > data[end]) return -1;
    else if(value == data[end]) return end;
    
    s = start;
    e = end;
    
    while(s+1 != e)
    {
        mid = (s+e)/2;
        if(data[mid] <= value) s = mid;
        else e = mid;
    }
    
    return s;
}

int main()
{
    int startIndex, endIndex, value;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &data[i]);
    sort(data, data+n);
   
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &value);
        
        startIndex = getStartIndex(0, n-1, value);
        endIndex = getEndIndex(0, n-1, value);
        if(startIndex != -1 && endIndex != -1) printf("%d ", endIndex-startIndex+1);
        else printf("0 ");
    }
    
    return 0;
}