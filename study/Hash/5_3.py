def solution(phone_book):
    answer = True
    phone_book.sort()
    len_list = len(phone_book)
    for i in range(1, len_list):
        if phone_book[i-1] in phone_book[i]:
            answer = False
            break

    return answer


if __name__ == "__main__":
    phone_book = ["11", "123", "12", "111"]
    # phone_book = ["119", "97674223", "1195524421"]
    # phone_book = ["123","456","789"]
    # phone_book = ["12","123","1235","567","88"]

    print(solution(phone_book))
    