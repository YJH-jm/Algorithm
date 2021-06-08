# 소수찾기 문제 : https://programmers.co.kr/learn/courses/30/lessons/42839

def getPrimeNum(num):
    if num == 1:
        return False

    for i in range(2, num-1):
        if num % i == 0:
            return False

    return True

def getResult(num_len, num, res): 
    ans = 0
    if len(res) >= num_len:
        return ans
    
    for i in range(num_len): #0번째, 1번째 자리의 수인 1, 7을 사용하기 위해!
        if check_num[i] != 1:
            if num[i] == '0' and len(res) == 0:
                continue
            check_num[i] = 1
            res += num[i]
            res_num = int(res)
            if res_num not in checkList:
                checkList.append(res_num)
                if getPrimeNum(res_num):
                    ans += 1
            ans += getResult(num_len, num, res)
            check_num[i] = 0
            res = res[0:-1]
    
    return ans

def solution(numbers):
    answer = 0
    global check_num
    global checkList
    checkList = []
    len_num = len(numbers) 
    check_num = []
    for i in range(len_num):
        check_num.append(0)

    result = ""
    answer = getResult(len_num, numbers, result)
    print(checkList)
    return answer


if __name__ == '__main__':
    print(solution("013"))