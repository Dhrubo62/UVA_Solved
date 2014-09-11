/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11152
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

# define PI 2*acos(0.0)

int main(void)
{
  double a,b,c,s,triangle,circumcircle,radius,incircle,sunflower,violet,rose;

  while(cin >> a >> b >> c)
    {
      s = (a+b+c)/2;

      // area of the triangle
      triangle = pow(s*(s-a)*(s-b)*(s-c),0.5);

      // area of circumcircle
      radius = (a*b*c)/pow((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c),0.5);
      circumcircle = PI * radius * radius;

      // area of incircle
      radius = triangle/s;
      incircle = PI * radius * radius;

      sunflower = circumcircle - triangle;
      violet = triangle - incircle;
      rose = incircle;

      printf("%0.4lf %0.4lf %0.4lf\n",sunflower,violet,rose);
    }

  return 0;
}
