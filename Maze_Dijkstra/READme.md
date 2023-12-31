
Maze

problem statement:


 The following layout represents a board. If you do not see a nice
layout, you might try copying the board to a mono spaced editor such
as “notepad.exe”

o....<br />
xx.x.<br />
...xx<br />
..x..<br />
...f.<br />
.....<br />
􀂾 The “o” represents your game piece on the board, there can only be
one game piece on the board at any given point in time.
􀂾 The “.” represents an empty space on the board where your game piece
can move to.
􀂾 The “x” represents an occupied space on the game board where your
game piece cannot move to. NOTE: The positions of the occupied
spaces will never change during the game.
􀂾 The “f” represents the finish space on the game board. The goal is
to move your game piece to this space in the fewest number of moves
possible.
􀂾 Your game piece can only move to adjacent unoccupied game spaces,
either up, down, left, or right. Diagonal/orthogonal moves are not
allowed.
􀂾 The width and height of the input board should be dynamic based on
the input file. In this example the board width is 5 and the height
is 6, however based on the input file below the width would be 3 and
height of 4. The width and height of the board will not change
during the game.
xxo<br />
x..<br />
..x<br />
f..<br />

􀂾 The program output two versions of the solution:

1. a graphical depiction of the solution. For example, to solve the
game above, the moves would be depicted as follows:
xxo<br />
x..<br />
..x<br />
f..<br />
<br />
xx.<br />
x.o<br />
..x<br />
f..<br />
<br />
xx.<br />
xo.<br />
..x<br />
f..<br />
<br />
xx.<br />
x..<br />
.ox<br />
f..<br />
<br />
xx.<br />
x..<br />
..x<br />
fo.<br />
<br />
xx.<br />
x..<br />
..x<br />
o..<br />

2. a listing of the row, column values for game piece to reach
the finish space in the fewest number of moves.
0,2<br />
1,2<br />
1,1<br />
2,1<br />
3,1<br />
3,0<br />
􀂾 If there are no possible correct answers then, the ONLY thing output
to the screen should be “unsolvable”.

maze.txt is an example file.

compile and run instructions:

g++ maze.cpp -o maze.o
./maze "maze.txt"
