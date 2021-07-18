from collections import deque

def reverse_polish_notation(li):
    stack = deque()
    expression = {"+": 1, "-": 1, "*": 2, "/": 2, "(": 3, ")": 4}
    for value in li.split():
        if value.isdigit():
            print(value, end=" ")
        else:
            if expression[value] != 4:
                if len(stack) == 0:
                    stack.append(value)
                else:
                    while expression[value] <= expression[stack[-1]] and (expression[stack[-1]] != 3):
                        # pop all expression in stack which have value greater than current value
                        # and that expression should not "("
                        print(stack.pop(), end=' ')
                        if len(stack) == 0:
                            break
                    stack.append(value)
            else:
                while expression[value] > expression[stack[-1]]:
                    if expression[stack[-1]] == 3:
                        stack.pop()
                        break
                    else:
                        print(stack.pop(), end=' ')
    while len(stack) != 0:
        # pop all the last expression in stack except "("
        if expression[stack[-1]] != 3:
            print(stack.pop(), end=' ')
        else:
            stack.pop()


if __name__ == '__main__':
    li = "( 10 * 3 + 7 / 8 ) * ( 5 - 1 )"
    reverse_polish_notation(li)