import random

def random_list(n):
    '''Generates a random list of n integers between 0 and 1000'''
    return random.sample(xrange(1000),n)
