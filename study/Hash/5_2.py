# 프로그래머스 15829문제 - hashing
# https://programmers.co.kr/learn/courses/30/lessons/42576

def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    # print(participant)
    # print(completion)
    for i in range(len(participant)-1):
        if participant[i] != completion[i]:
            answer += participant[i]
            return answer
    answer += participant[-1]
    return answer

if __name__ == "__main__":
    participant = ["leo", "kiki", "eden"]
    completion = ["eden", "kiki"]
    # participant = ["mislav", "stanko", "mislav", "ana"]
    # completion = ["stanko", "ana", "mislav"]

    print(solution(participant, completion))