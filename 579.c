/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 579
*/

# include <stdio.h>

int main(void)
  {
	double hour,min,extra,hour_min,distance;

	while(scanf("%lf:%lf",&hour,&min)!=EOF && !(!hour && !min))
	{
	    extra = (min/60) * 5;
	    hour_min = (hour*5) + extra;

	    distance = hour_min - min;

	    if(distance<0)
	    distance *= -1;

	    if(distance>30)
	    distance = 60-distance;

	    printf("%0.3lf\n",distance*6);
	}

	return 0;
  }
