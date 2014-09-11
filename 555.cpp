/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 555 - "Bridge Hands"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

struct card
{
    char d;
    char c;
};

struct human
{
    int ind;
    card crd[13];
} player[4];

int compare(card a, card b)
{
    char p=a.d,q=b.d,x=a.c,y=b.c;

    if(p=='H') p='Z';
    if(q=='H') q='Z';

    if(x=='T') x='A';
    else if(x=='J') x='B';
    else if(x=='Q') x='C';
    else if(x=='K') x='D';
    else if(x=='A') x='E';

    if(y=='T') y='A';
    else if(y=='J') y='B';
    else if(y=='Q') y='C';
    else if(y=='K') y='D';
    else if(y=='A') y='E';

    if(p==q) return x<y;
    else return p<q;
}

int main(void)
{
	char c;
	int i,p,n;

	while(cin>>c && c!='#')
	{
	    if(c=='S') p=1;
	    else if(c=='W') p=2;
	    else if(c=='N') p=3;
	    else p=0;

	    //initialize
	    for(i=0; i<4; i++) player[i].ind=0;

	    //input
	    for(i=0; i<52; i++)
	    {
	        if(p>3) p=0;

	        n=player[p].ind;
	        cin>>player[p].crd[n].d>>player[p].crd[n].c;

	        player[p].ind++;
	        p++;
	    }

	    //sorting
	    sort(player[0].crd,player[0].crd+13,compare);
	    sort(player[1].crd,player[1].crd+13,compare);
	    sort(player[2].crd,player[2].crd+13,compare);
	    sort(player[3].crd,player[3].crd+13,compare);

	    //printing
	    cout<<"S:";
	    for(i=0; i<13; i++) printf(" %c%c",player[0].crd[i].d,player[0].crd[i].c);
	    cout<<endl;
        cout<<"W:";
	    for(i=0; i<13; i++) printf(" %c%c",player[1].crd[i].d,player[1].crd[i].c);
	    cout<<endl;
        cout<<"N:";
	    for(i=0; i<13; i++) printf(" %c%c",player[2].crd[i].d,player[2].crd[i].c);
	    cout<<endl;
        cout<<"E:";
	    for(i=0; i<13; i++) printf(" %c%c",player[3].crd[i].d,player[3].crd[i].c);
	    cout<<endl;
	}

	return 0;
}
