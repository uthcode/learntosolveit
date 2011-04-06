# DAWKINS' BLIND WATCHMAKER -- "METHINKS IT IS LIKE A WEASEL" EXAMPLE
#
# Start with a random phrase.  Successively:
# Breed a next generation by copying with small mutations.
# Choose the member of the next generation that most closely resembles
# the target phrase to start breeding the next generation.
# How many generations will it take before the target is reached?

from whrandom import random

# Parameters determining the problem space
Target = 'methinks it is like a weasel'
Alphabet = ' abcdefghijklmnopqrstuvwxyz'

# Parameters to play with
GenerationSize = 100
MutationChance = 1.0/28.0

IndexSet = range(len(Target))  # Used to speed up loops

def choice(sequence):
       n = len(sequence)
       i = int(random() * float(n)) % n
       return sequence[i]

def random_phrase():
       phrase = ''
       for i in IndexSet:
               phrase = phrase + choice(Alphabet)
       return phrase

def mutate_phrase(phrase):
       mutant = phrase
       for i in range(int(0.5 + MutationChance*float(len(phrase)))):
               i = choice(IndexSet)
               c = choice(Alphabet)
               mutant = mutant[:i] + c + mutant[i+1:]
       #print `mutant`
       return mutant

def matching_factor(phrase):
       factor = 0
       for i in IndexSet:
               if phrase[i] = Target[i]: factor = factor + 1
       return factor

def breed_generation(phrase):
       generation = [phrase]
       while len(generation) < GenerationSize:
               generation.append(mutate_phrase(phrase))
       return generation

def select_best(generation):
       factor, selected = -1, ''
       for phrase in generation:
               f = matching_factor(phrase)
               if f > factor:
                       factor, selected = f, phrase
       return selected

def main():
       gen = 0
       phrase = random_phrase()
       print gen, `phrase`
       while phrase <> Target:
               next_generation = breed_generation(phrase)
               #print next_generation
               phrase = select_best(next_generation)
               gen = gen+1
               print gen, `phrase`

main()
