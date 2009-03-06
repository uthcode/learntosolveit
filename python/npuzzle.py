#!/usr/bin/python
# -*- coding: utf-8 -*-
# vim: ts=4 sw=4 et ai ff=unix ft=python nowrap
#
# Program: npuzzle.py
#
# Description: Solves the N-Puzzle Sliding Block Problem.
#
# Usage: python npuzzle.py.
#
# License: GNU GPL Version 2.0. Please refer www.gnu.org.

import random


class State:

    def __init__(self, nsize):
        """Initialze the n-puzzle problem, with n-size value, tsize the total nodes and initial the goal state from n.
        """

        self.nsize = nsize
        self.tsize = pow(self.nsize, 2)
        self.goal = range(1, self.tsize)
        self.goal.append(0)

    def printst(self, st):
        """Print the list in a Matrix Format."""

        for (index, value) in enumerate(st):
            print ' %s ' % value, 
            if index in [x for x in range(self.nsize - 1, self.tsize, 
                         self.nsize)]:
                print 
        print 

    def getvalues(self, key):
        """Utility function to gather the Free Motions at various key positions in the Matrix."""

        values = [1, -1, self.nsize, -self.nsize]
        valid = []
        for x in values:
            if 0 <= key + x < self.tsize:
                if x == 1 and key in range(self.nsize - 1, self.tsize, 
                        self.nsize):
                    continue
                if x == -1 and key in range(0, self.tsize, self.nsize):
                    continue
                valid.append(x)
        return valid

    def expand(self, st):
        """Provide the list of next possible states from current state."""

        pexpands = {}
        for key in range(self.tsize):
            pexpands[key] = self.getvalues(key)
        pos = st.index(0)
        moves = pexpands[pos]
        expstates = []
        for mv in moves:
            nstate = st[:]
            (nstate[pos + mv], nstate[pos]) = (nstate[pos], nstate[pos + 
                    mv])
            expstates.append(nstate)
        return expstates

    def one_of_poss(self, st):
        """Choose one of the possible states."""

        exp_sts = self.expand(st)
        rand_st = random.choice(exp_sts)
        return rand_st

    def start_state(self, seed=1000):
        """Determine the Start State of the Problem."""

        start_st = (self.goal)[:]
        for sts in range(seed):
            start_st = self.one_of_poss(start_st)
        return start_st

    def goal_reached(self, st):
        """Check if the Goal Reached or Not."""

        return st == self.goal

    def manhattan_distance(self, st):
        """Calculate the Manhattan Distances of the particular State.
           Manhattan distances are calculated as Total number of Horizontal and Vertical moves required by the values in the current state to reach their position in the Goal State.
        """

        mdist = 0
        for node in st:
            if node != 0:
                gdist = abs(self.goal.index(node) - st.index(node))
                (jumps, steps) = (gdist // self.nsize, gdist % self.nsize)
                mdist += jumps + steps
        return mdist

    def huristic_next_state(self, st):
        """This is the Huristic Function. It determines the next state to follow and uses Mahattan distances method as the huristics. This this determined way, a A* approach for path finding is used. 
If more than one path have same manhattan distance, then a random choice of one of them is analyzed and carried forward. If not best path, randomness to providethe other choice is relied upon. No Depth First search is Used."""

        exp_sts = self.expand(st)
        mdists = []
        for st in exp_sts:
            mdists.append(self.manhattan_distance(st))
        mdists.sort()
        short_path = mdists[0]
        if mdists.count(short_path) > 1:
            least_paths = [st for st in exp_sts if self.manhattan_distance(st) == short_path]
            return random.choice(least_paths)
        else:
            for st in exp_sts:
                if self.manhattan_distance(st) == short_path:
                    return st

    def solve_it(self, st):
        while not self.goal_reached(st):
            st = self.huristic_next_state(st)
            self.printst(st)


if __name__ == '__main__':
    print 'N-Puzzle Solver!'
    print 10 * '-'
    state = State(3)
    print 'The Starting State is:'
    start = state.start_state(5)
    state.printst(start)
    print 'The Goal State should be:'
    state.printst(state.goal)
    print 'Here it Goes:'
    state.printst(start)
    state.solve_it(start)


