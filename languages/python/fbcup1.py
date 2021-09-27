import string
from collections import Counter
from collections import defaultdict

words = set(string.ascii_uppercase)
vowels = set(['A','E','I','O','U'])
consonants = words - vowels


T = int(input())
for tc in range(T):
    reverse_dict = defaultdict(list)
    num_vowels = 0
    num_consonants = 0
    tcn = tc + 1
    word = input()
    chars = set(word)
    if len(chars) == 1:
        print(f"Case #{tcn}:", 0)
        continue
    for c in chars:
        if c in vowels:
            num_vowels += 1
        else:
            num_consonants += 1
    print(f"consonants: {num_consonants}, vowels: {num_vowels}")
    word_counter = Counter(word)
    for w, c in word_counter.items():
        reverse_dict[c].append(w)
    sorted_keys = sorted(reverse_dict.keys(), reverse=True)
    # pick the one that you are not changing.
    print(reverse_dict)
    print(sorted_keys)

