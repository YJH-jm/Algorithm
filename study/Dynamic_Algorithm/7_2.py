# /*
# 프로그래머스 43105문제 - 정수 삼각형
# https://programmers.co.kr/learn/courses/30/lessons/43105
# */

def solution(triangle):
    answer = 0
    ans = []
    # print(len(triangle))
    for i in range(len(triangle)):
        ans.append([])
        if i == 0:
            ans[i].append(triangle[i][0])
        else:
            for j in range(len(triangle[i])):
                if j == 0:
                    ans[i].append(ans[i-1][0] + triangle[i][0])
                elif j == i:
                    ans[i].append(ans[i-1][i-1] + triangle[i][i])
                else:
                    ans[i].append(max(ans[i-1][j]+triangle[i][j], ans[i-1][j-1]+triangle[i][j]))

    for i in range(len(triangle)):
        if answer < ans[len(triangle)-1][i]:
            answer = ans[len(triangle)-1][i]
    return answer

if __name__ == "__main__":
    triangle = [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]
    print(solution(triangle))