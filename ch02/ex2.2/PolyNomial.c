#include <stdio.h>
#define MaxDegree 100

typedef struct polynomial{
	int HighPower;
	int CoeffArray[MaxDegree];
}*PolyNomial;

void InitialPolyNomial(PolyNomial Poly)
{
	int i = 0;
	for(i = 0 ; i < MaxDegree ;i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

void AddPolyNomial(PolyNomial ps,PolyNomial p1,PolyNomial p2)
{
	ps->HighPower = p1->HighPower > p2->HighPower ? p1->HighPower : p2->HighPower;
	int i = 0;
	for(i = 0; i < ps->HighPower ;i++)
	{
		ps->CoeffArray[i] = p1->CoeffArray[i]+p2->CoeffArray[i];
	}
}


void MultiPolyNomial(PolyNomial pm,PolyNomial p1,PolyNomial p2)
{
	pm->HighPower = p1->HighPower + p2->HighPower-1;
	int i = 0,j = 0;
	for(i = 0; i < p1->HighPower ;i++)
	{
		for(j = 0; j < p2->HighPower ; j++)
		{
			pm->CoeffArray[i + j] += p1->CoeffArray[i] * p2->CoeffArray[j];
		}
	}
}



int main(int argc,char *argv[])
{
	struct polynomial sum,multi,p1,p2;
	InitialPolyNomial(&sum);
	InitialPolyNomial(&multi);
	InitialPolyNomial(&p1);
	InitialPolyNomial(&p2);
	
	p1.HighPower = 2;
	p1.CoeffArray[0] = 2;
	p1.CoeffArray[1] = 3;
	
	p2.HighPower = 2;
        p2.CoeffArray[0] = 4;
        p2.CoeffArray[1] = 5;

	int i = 0;
	AddPolyNomial(&sum,&p1,&p2);
	for(i = 0; i < sum.HighPower ;i++)
	{
		printf("%d ",sum.CoeffArray[i]);
	}
	printf("\n");

	MultiPolyNomial(&multi,&p1,&p2);
	for(i = 0; i < multi.HighPower ;i++)
        {
                printf("%d ",multi.CoeffArray[i]);
        }
        printf("\n");


	return 0;
}
