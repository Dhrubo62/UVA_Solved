/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 10221 - "Satellites"
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
  double s,thita;
  char unit[100];

  while(cin >> s >> thita >> unit)
    {
      if(!strcmp(unit,"min"))
        thita /= 60.0;

      if(thita>180) thita = 360 - thita;
      thita = (PI/180.0)*thita;

      double arch = (s+6440.0)*thita;
      double chord = 2.0*(s+6440.0)*sin(thita/2.0);

      printf("%.6lf %.6lf\n",arch,chord);
    }

  return 0;
}
