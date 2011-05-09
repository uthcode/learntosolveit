import random

def random_list(n):
    '''Generates a random list of n integers between 0 and 1000'''
    return random.sample(range(1000),n)
