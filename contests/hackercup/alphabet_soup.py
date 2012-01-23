T = int(raw_input())

def count_hackercup(sentence):
    len_of_sentence = len(sentence)
    # Remove all the not required letters from the sentence
    eligible_letters = ""
    for char in sentence:
        if char in "HACKERCUP":
            eligible_letters += char
    max_words = len(eligible_letters)/len("HACKERCUP")
    list_of_max_words = [list("HACKERCUP") for i in range(max_words)]
    for char in eligible_letters:
        for word_list in list_of_max_words:
            if char in word_list:
                word_list.remove(char)
                break
    return max_words - len(filter(None,list_of_max_words))

for tc in range(T):
    test_sentence = raw_input()
    result = count_hackercup(test_sentence)
    print 'Case #%d: %d' % (tc+1, result)
