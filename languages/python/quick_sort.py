import random

def quick_sort(sortlist):
	left = []
	right = []
	solution = []
	if len(sortlist) <= 1:
		return sortlist
	pivot = sortlist[len(sortlist)/2]
	sortlist.remove(pivot)
	for each in sortlist:
		if each <= pivot:
			left.append(each)
		elif each > pivot:
			right.append(each)
	left_sorted = quick_sort(left)
	right_sorted = quick_sort(right)
	solution.append(left_sorted)
	solution.append(pivot)
	solution.append(right_sorted)
	return solution
		
list_to_sort = random.sample(range(1,100),10)

print quick_sort(list_to_sort)
