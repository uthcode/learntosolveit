import os
list_of_files = os.listdir(os.getcwd())
python_files = []

for each in list_of_files:
    if each.endswith('.py'):
        python_files.append(each)

python_files.sort()
for fname in python_files:
    print fname + '\n'
