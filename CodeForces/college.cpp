#include <iostream>
2 #include <vector>
3 usuing namespace std;
4 int Exponent(int a, int b)
5
if (b==0)
6
7
return 1;
8
else
9:
10
return a Exponent(a,b-1)
11
12 int main()
13 {
14
15
int a=3, b=7;

return 0;