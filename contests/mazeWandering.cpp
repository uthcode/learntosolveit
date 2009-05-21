/***

Problem Statement
    
According to research conducted recently, listening to classical music
increases one's mental abilities, while listening to metal decreases them. Now,
yet another experiment is being conducted to try to prove or disprove this
statement.  In this new experiment, a mouse is placed in a rectangular maze
consisting of NxM squares. Each square either contains a wall or is empty. The
maze is structured in such a way that for any two empty squares, there exists
exactly one path between them. A path is a sequence of pairwise distinct empty
squares such that every two consecutive squares are neighboring. Two squares
are considered neighboring if they share a common edge.  One of the empty
squares in the maze contains a piece of cheese. The mouse's goal is to reach
that square without visiting the same square twice. The mouse can only move
between neighboring squares. Since the mouse has been listening to classical
music for a week, he is extremely intelligent and guaranteed to achieve his
goal.  As the mouse moves from his starting point to the cheese, he may
encounter some squares where he must choose between several neighboring squares
to continue. This happens when the mouse steps into a square which has more
than one neighboring empty square, excluding the square from which he came, or
when he has more than one neighboring empty square at the start. These
situations are called "decisions" and the mouse will always make the right
choice.  You are given a vector <string> maze representing the maze. It
contains N elements, each containing M characters. Empty squares are denoted by
'.', walls are denoted by uppercase 'X', the mouse's starting point is denoted
by 'M', and the square containing the cheese is denoted by '*'. Return the
number of decisions the mouse will make on his way to the cheese.

Definition
    
Class:
MazeWanderingEasy
Method:
decisions
Parameters:
vector <string>
Returns:
int
Method signature:
int decisions(vector <string> maze)
	(be sure your method is public)
	    

	Constraints
	-
	maze will contain between 1 and 50 elements, inclusive.
	-
	Each element of maze will contain between 1 and 50 characters, inclusive.
	-
	Elements of maze will be of the same length.
	-
	maze will contain only '.', 'X', 'M' or '*' characters.
	-
	There will be exactly one '*' character in maze.
	-
	There will be exactly one 'M' character in maze.
	-
	For every pair of empty squares in the maze, there will exist exactly one path between them.
	Examples
	0)

	    
{"*.M"}
Returns: 0
From each square, the mouse can only move to one other square, so he never has to make any decisions.
1)

    
{"*.M",
	 ".X."}
Returns: 1
The mouse has to make a decision right at the start.
2)

    
{"...",
	 "XMX",
	  "..*"}
Returns: 2
The mouse makes decisions at both squares before reaching the cheese.
3)

    
{".X.X......X",
	 ".X*.X.XXX.X",
	  ".XX.X.XM...",
	   "......XXXX."}
Returns: 3

4)

    
{"..........*",
	 ".XXXXXXXXXX",
	  "...........",
	   "XXXXXXXXXX.",
	    "M.........."}
Returns: 0

This problem statement is the exclusive and proprietary property of TopCoder,
     Inc. Any unauthorized use or reproduction of this information without the
     prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003,
     TopCoder, Inc. All rights reserved.

**/
