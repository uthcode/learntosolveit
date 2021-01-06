import os
from ideone import Ideone
i = Ideone(os.getenv('IDEUSER'), os.getenv('IDEPASS'))
print(i.create_submission('print(42)', language_name='python',run=False))
