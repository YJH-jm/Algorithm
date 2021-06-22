# /*
# 프로그래머스 [1차] 비밀지도 
# https://programmers.co.kr/learn/courses/30/lessons/17681
# */

def  getBinary(n, value):
    tmp = []

    while value != 0:
        tmp.insert(0, value%2)
        value //= 2
    
    bin_len = len(tmp)
    for i in range(0,n-bin_len):
        tmp.insert(0, 0)
    return tmp


def solution(n, arr1, arr2):
    answer = []
    bin_arr1 = []
    bin_arr2 = []
    for i in range(n):
        bin_arr1.append(getBinary(n, arr1[i]))
        bin_arr2.append(getBinary(n, arr2[i]))
    
    for i in range(n):
        ans = ""
        for j in range(n):
            if bin_arr1[i][j] | bin_arr2[i][j] == 0:
                ans += " "
            elif bin_arr1[i][j] | bin_arr2[i][j] == 1:
                ans += "#"
        print(ans)
        answer.append(ans)

    print(answer)
    return answer


if __name__ == "__main__":
    n = 5
    arr1 = [9, 20, 28, 18, 11]
    arr2 = [30, 1, 21, 17, 28]
    solution(n, arr1, arr2)