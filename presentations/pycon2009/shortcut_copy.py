import copy
new_list = copy.copy(existing_list)

# When we want every item and attribute in the object to be separately copied,
# recursively use deepcopy

new_list_of_dicts = copy.deepcopy(existing_list_of_dicts)

# For normal shallow copies, we have a good alternative to copy.copy, if we know
# the type of object we want to copy. To copy a list L, call list(L); to copy a
# dict d, call dict(d), to copy a set call set(s).

# To copy a a copyable object o, which belongs to some built-in Python type t,
# we may generally just call t(o)

