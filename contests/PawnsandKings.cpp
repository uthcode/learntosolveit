/**

Problem Statement
    
You are given a vector <string> board representing a standard 8x8 chess board.
The '.' character represents an empty cell, 'P' represents a cell occupied by a
pawn, and 'K' represents a cell occupied by a king.

In a single move, a king can move to any of its 8 neighboring cells. If you
move a king into a cell occupied by a pawn, the king will capture that pawn.
You can never move a king outside the board or into a cell already occupied by
another king.  

Return the minimal number of moves required for the kings to capture all the
pawns.

Definition
    
Class: PawnsAndKings
Method: minNumberOfMoves
Parameters: vector <string>
Returns: int Method signature:
int minNumberOfMoves(vector <string> board)
(be sure your method is public)
    

Constraints

- board will contain exactly 8 elements.
- Each element of board will contain exactly 8 characters.
- Each character of each element of board will be '.', or an uppercase 'P', or an uppercase 'K'.
- The number of 'P' characters will be between 1 and 10, inclusive.
- The number of 'K' characters will be between 1 and 10, inclusive.

Examples 0)

    
{".PPPPKP.", 
 "........", 
 "........", 
 "........", 
 "........", 
 "........", 
 "........", 
 "........"}

Returns: 6

The only king will make the minimal number of moves by first capturing the only
pawn at its right side and then capturing the other pawns.

1)
    
{"P......P", 
 "........", 
 "........",
 "........",
 "...KK...",
 "........",
 "........",
 "P......P"}

Returns: 20

If we mark the kings with A and B and the pawns with 1, 2, 3 and 4, then one
possible solution is that A captures the pawns 1 and 2, and B captures the
pawns 3 and 4.

1......4
........
........
........
...AB...
........
........
2......3

2)

{".....P.P",
 "..K....P",
 "....K...",
 "..PP...P",
 "...K..KK",
 "........",
 "K.......",
 "KP.K...."}

Returns: 9

3)
    
{"PK...KPK",
 "......K.",
 "...K....",
 "..KPK...",
 "...K....",
 "........",
 "........",
 "K..P.K.P"}

Returns: 8

	This problem statement is the exclusive and proprietary property of
	TopCoder, Inc. Any unauthorized use or reproduction of this information
	without the prior written consent of TopCoder, Inc. is strictly
	prohibited. (c)2003, TopCoder, Inc. All rights reserved.

**/


