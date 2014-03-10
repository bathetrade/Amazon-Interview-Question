ABOUT THIS PROGRAM:
This program (problemSolver) attempts to solve Amazon's interview question about how many "shapes" exist in a randomly generated MxN grid, such as this 3x4 grid:

1 0 1 1   
1 0 0 1   
0 1 1 0  (There are 3 shapes here)

A "shape" is defined as the collection of ones which are adjacent to each other, such as

1 0  
1 0 

or 

1 1  
1 0 

for instance. Ones which are diagonal to each other are not considered part of the same shape, so the following grid

1 0  
0 1

has 2 separate shapes.



HOW TO USE THE PROGRAM:
Run "problemGenerator" to generate the file "input.txt," which contains a randomly generated MxN grid with a random number of shapes. Then, run problemSolver to display the number of shapes contained in the grid. 
