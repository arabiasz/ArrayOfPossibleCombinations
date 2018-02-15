# ArrayOfPossibleCombinations

A simple algorithm for generating an array of all combinations from a particular set according to the scheme given
below as an example drawn by hand. Working for n <= 20

eg 1.   
for k=2 and n=3 we have 3 combinations drawn as below

|  | 1 | 2 | 3 |
|------ | ------ | ------ | ------ |
| 0 | x | x |   |
| 1 | x |   | x |
| 2 |   | x | x |

The result of the algorithm will be the following table:

01  
02  
12  

eg 2.  
for k=2 and n=5 we have 10 combinations drawn as below

|  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|------ | ------ | ------ | ------ |------ | ------ | ------ | ------ |------ | ------ |------ |
| 0 | x | x | x | x |   |   |   |   |   |   |
| 1 | x |   |   |   | x | x | x |   |   |   |
| 2 |   | x |   |   | x |   |   | x | x |   |
| 3 |   |   | x |   |   | x |   | x |   | x |
| 4 |   |   |   | x |   |   | x |   | x | x |

The result of the algorithm will be the following table:  

01  
02  
03  
04  
12  
13  
14  
23  
24  
34  
