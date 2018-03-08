#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class clavebits
{ private: int x;
   public: 
        clavebits& operator=(int i)
           {x=i; return *this; }
        inline unsigned bits (int k, int j)
            {return (x>>k)&~(~0<<j);}
};
typedef  clavebits  algo;

void cambioresiduos(int a[], int izq, int der, int b)
{   int i,j; int t;
	
    if (der>izq && b>0)
      {i= izq; j=der;
        while(j!=i){ 
	   		while(!bits(a[i],b,1) && i<j)i++;                //!a[i].bits(b,1)
            while( bits(a[j],b,1) && j>i)j--;
             intercambio(a, i, j);
           }
    	if (!a[i].bits(b,1)) j++;
            cambioresiduos(a, izq, j-1, b-1);
            cambioresiduos(a, j, der, b-1);
      }
}

int main(int argc, char** argv) {
	
	// llenado del for 
	int i;
	int n=10;
	int b=3;
	int *a;
	a=new int[];
	
	for(i=0; i<n; i++){
		a[i]=n--;               //por ahora llenado asi
	}
	
	cambioresiduos(a, 0, n-1,3)
	return 0;
}
