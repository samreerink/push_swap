# To use output as arguments for push_swap and/or checker:
# ARG="`python3 random_numbers.py`"; ./push_swap $ARG | ./checker_linux $ARG

import random

n = 100

for x in range(n - 1):
    print(random.randint(-10000,10000), end=" ")
print(random.randint(-10000,10000), end="")
