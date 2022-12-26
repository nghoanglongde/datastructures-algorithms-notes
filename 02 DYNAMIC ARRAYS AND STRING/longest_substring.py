def handle_substring(s):
    max_len = 0
    for i in range(len(s)):
        temp = {}
        for j in range(i, len(s)):
            print(j, s[j])
            if s[j] not in temp:
                temp[s[j]] = 1
            else:
                max_len = max(max_len, len(temp))
                break 
    print(max_len)


if __name__ == "__main__":
    s = "au"
    handle_substring(s)