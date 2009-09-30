/*
 * i, j is the position.
 * i - 2, j + 1
 * i - 2, j - 1
 * i - 1, j + 2
 * i - 1, j - 2
 * i + 1, j + 2
 * i + 1, j - 2
 * i + 2, j + 1
 * i + 2, j - 1
 */


#include<iostream>
#include<vector>

using namespace std;

class KnightsTour
{
	public:

	vector <pair <int, int> > validmoves(vector <string> board, int r, int c)
	{
		vector <pair <int, int> > coords;
		vector <pair <int, int> > validcoords;
		int row, col;
		coords.push_back(make_pair(2,1));
		coords.push_back(make_pair(2,-1));
		coords.push_back(make_pair(1,2));
		coords.push_back(make_pair(1,-2));
		coords.push_back(make_pair(-1,2));
		coords.push_back(make_pair(-1,-2));
		coords.push_back(make_pair(-2,1));
		coords.push_back(make_pair(-2,-1));

		for(int i=0; i < coords.size(); i++)
		{
			row = r + coords[i].first;
			col = c + coords[i].second; 
			if ( (0 <= row) && (row < board.size()) && (0 <= col) && (col < board.size()) )
			{
				if (board[row][col] == '.')
					validcoords.push_back(make_pair(row,col));
			}
		}
		return validcoords;

	}

	int visitedPositions(vector <string> board)
	{
		int r,c,i,j,pos, nr,nc;
		vector <pair <int, int> > validcoords, possiblemoves;
		int visited=0,smallest=8,nextmoves=0;
		for (i = 0; i < board.size(); i++)
		{
			pos = board[i].find("K");
			if(pos != -1)
			{
				r = i;
				c = pos;
			}
		}

		do
		{
		board[r][c] = '*'; visited++;
		validcoords = validmoves(board, r,c);
		nextmoves = validcoords.size();
		smallest = 8;
		for (j=0; j < nextmoves; j++)
		{ 
			possiblemoves = validmoves(board, validcoords[j].first, validcoords[j].second);
			if (possiblemoves.size() <= smallest)
			{
				smallest = possiblemoves.size();
				nr = validcoords[j].first;
				nc = validcoords[j].second;
			}

		}
		if (nextmoves > 0)
		{
			r = nr;
			c = nc;
		}

		}while(nextmoves > 0);

		return visited;
	}

};
int main(int argc, char *argv[])
{
	KnightsTour obj;
	vector <string> board;
	board.push_back("K.......");
	board.push_back("........");
	board.push_back("........");
	board.push_back("........");
	board.push_back("........");
	board.push_back("........");
	board.push_back("........");
	board.push_back("........");
	cout<<obj.visitedPositions(board)<<endl;
}
