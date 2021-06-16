'''
프로그래머스 - 타겟 넘버
https://programmers.co.kr/learn/courses/30/lessons/43165
'''


def getResult(x, lenNum, tar, numbers):
    answer = 0
    if x >= lenNum:
        sum = 0
        for i in range(x):
            sum += result[i]
        if sum == tar:
            answer += 1
        return answer
    
    
    result.append(numbers[x])
    
    answer += getResult(x+1, lenNum, tar, numbers)
    
    result.pop()
    result.append(-numbers[x])
    
    answer += getResult(x+1, lenNum, tar, numbers)
    result.pop()
    
    return answer

def solution(numbers, target):
    answer = 0
    lenNum = len(numbers)
    global result
    result = []

    answer = getResult(0, lenNum, target, numbers)
    
    return answer
