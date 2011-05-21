import operator

def choosebest(letters, possible_words):
    list_of_chars = []
    for word in possible_words:
        list_of_chars += list(word)
    possible_chars = set(list_of_chars)
    reduced_letters = ''
    for char in letters:
        if char in possible_chars:
            reduced_letters += char
    result_words = possible_words[:]
    for char in reduced_letters:
        all_values = []
        for word in possible_words:
            if char in word:
                all_values.append(True)
            else:
                all_values.append(False)
        if not all(all_values):
            index = all_values.index(True)
            word = possible_words[index]
            if word in result_words:
                result_words.remove(word)
            if len(result_words) == 1:
                break
    return result_words

T = int(raw_input())
for tc in range(1, T+1):
    N, M = map(int, raw_input().split())
    words = []
    for n in range(N):
        words.append(raw_input())
    words.sort(key=len)
    words.reverse()
    dict_of_word_lengths = {}
    dict_of_word_length_counts = {}
    for word in words:
        if len(word) in dict_of_word_lengths:
            dict_of_word_lengths[len(word)].append(word)
            dict_of_word_length_counts[len(word)] += 1
        else:
            dict_of_word_lengths[len(word)] = [word]
            dict_of_word_length_counts[len(word)] = 1
    letters = []
    for m in range(M):
        letters.append(raw_input())

    sorted_dict = sorted(dict_of_word_length_counts.iteritems(), key=operator.itemgetter(1))
    sorted_dict.reverse()

    keys_to_choose = [sorted_dict[0][0]]
    value_item = sorted_dict[0][1]
    for item in sorted_dict:
        key = item[0]
        value = item[1]
        if value == value_item:
            if key not in keys_to_choose:
                keys_to_choose.append(key)

    possible_words = []
    for key in keys_to_choose:
        for word in dict_of_word_lengths[key]:
            possible_words.append(word)
    result = []
    for letters_choice in letters:
        best_words = choosebest(letters_choice, possible_words)
        print best_words
        indexes = []
        for word in best_words:
            indexes.append(words.index(word))
        indexes.sort()
        best_word = indexes[0]
        result.append(word[best_word])

    result_sentence = ' '.join(result)
    print 'Case # %d: %s' % (tc, result_sentence)
