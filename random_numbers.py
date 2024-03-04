# To use output as arguments for push_swap and/or checker:
# ARG="`python3 random_numbers.py`"; ./push_swap $ARG | ./checker_linux $ARG

import random

n = 100
i = 0;
numbers = []

while i < n:
    x = random.randint(-2147483648,2147483647)
    if x not in numbers:
        if i != (n - 1):
            print(x, end=" ")
        else:
            print(x, end="")
        i += 1
        numbers.append(x)
