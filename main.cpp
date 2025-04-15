/*
Tic Tac Toe Game with n Dimensions

Description:
This program implements a Tic Tac Toe game for a grid of size n x n. The game supports two players, 'x' and 'o',
who take turns to place their symbols on the grid. The game checks for a winner after each move, and if the grid
is full without any player winning, it declares a tie.

The main parts of the code are explained below:

1. Initializing the Game:
   - The program prompts the user to enter the dimensions of the grid (n).
   - A 2D array `grid` is initialized to store the state of each cell (0 for empty, 1 for 'x', and 2 for 'o').

2. Setting up Verification Arrays:
   - Four arrays (`rs`, `cs`, `dr`, `dc`) are used to store the starting positions and directions for checking rows,
     columns, and diagonals.
   - `rs` and `cs` store the starting row and column indices.
   - `dr` and `dc` store the row and column directions for traversing the grid.

3. Populating Verification Arrays:
   - Rows: For each row, the starting position is set to the first cell of the row, and the direction is set to move right.
   - Columns: For each column, the starting position is set to the first cell of the column, and the direction is set to move down.
   - Diagonals: Two diagonals are considered:
     - The main diagonal from the top-left to the bottom-right.
     - The anti-diagonal from the top-right to the bottom-left.

4. Game Loop:
   - The game loop runs until all cells are filled or a player wins.
   - Players take turns to input their move (row and column).
   - The input is validated to ensure the cell is empty and within bounds.
   - The grid is updated with the player's symbol.

5. Printing the Grid:
   - The grid is printed with row and column indices to make it user-friendly.
   - '.' represents empty cells, 'x' and 'o' represent the players' moves.

6. Checking for a Winner:
   - After each move, the program checks all rows, columns, and diagonals to see if any of them contain the same symbol.
   - If a winning condition is found, the game announces the winner and exits.

7. Declaring a Tie:
   - If all cells are filled and no player has won, the game declares a tie and exits.

Example of a 3x3 grid and the moves:
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Tic Tac Toe Game with n dimensions\n";
    cout << "Enter the dimensions for the game: ";
    int n;
    cin >> n;
    int grid[9][9] = {0};

    int rs[9],cs[9],dr[9],dc[9];

    int verifies = 0;

    for (int r=0;r<n;r++)
        rs[verifies]=r , cs[verifies]=0, dr[verifies]=0,dc[verifies++]=1;

    for (int c=0;c<n;c++)
        rs[verifies]=0, cs[verifies]=c, dr[verifies]=1, dc[verifies++]=0;

   rs[verifies]=0, cs[verifies]=0, dr[verifies]=1, dc[verifies++]=1;

   rs[verifies]=0, cs[verifies]=n-1, dr[verifies]=1, dc[verifies++]=-1;

    int turn = 0;
    int steps =0;

    while (true)
    {
        if (steps==n*n)
        {
            cout << "Tie\n";
            break;
        }
        char symbol = 'x';
        if (turn==1)
            symbol='o';

        cout << "Player " <<symbol << " turn. Enter empty location (r,c): ";
        int r,c;
        cin >> r >> c;
        r--,c--;
        if (r<0||c<0||c>=n||r>=n||grid[r][c]!=0)
        {
            cout << "\nInvalid location, try again.\n";
            continue;
        }

        grid[r][c]=turn+1;

        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                cout << "   ";
                for (int j = 1; j <= n; j++)
                {
                    cout << j << " ";
                }
                cout << "\n";
                continue;
            }

            cout << i << "  ";
            for (int j = 0; j < n; j++)
            {
                char ch = '.';
                if (grid[i - 1][j] == 1)
                    ch = 'x';
                else if (grid[i - 1][j] == 2)
                    ch = 'o';
                cout << ch << " ";
            }
            cout << "\n";
        }


        for (int check=0;check<verifies;check++)
        {
            int row=rs[check], col=cs[check], diar=dr[check], dial=dc[check];
            int count =0 ,first =grid[row][col];

            if (first==0)
                continue;
            for (int step=0;step<n;step++, row+=diar, col+=dial)
                count+=grid[row][col]==first;

            if (count==n)
            {
                cout << "Player " << symbol << " won\n";
                return 0;
            }
        }

        turn = !turn;
        steps++;
    }
    return 0;
}