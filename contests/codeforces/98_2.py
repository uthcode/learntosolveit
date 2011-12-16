cards_and_photos = raw_input()
last_char = None
visit = 0
item_count = 0

for curr_char in cards_and_photos:
    if last_char == None:
        last_char = curr_char
        item_count += 1
    else:
        if curr_char == last_char:
            item_count += 1
            if item_count == 5:
                visit += 1
                item_count = 0
                last_char = None
        else:
            visit += 1
            item_count = 1
            last_char = curr_char

if item_count != 0:
    visit += 1

print visit
