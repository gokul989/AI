#include<stdio.h>

int pathcost[17][17]={
{999,6,999,999,999,3,999,999,999,999,999,999,999,999,999,999,999},
{999,999,999,3,999,999,999,999,999,999,999,999,999,999,999,999,999},
{4,999,999,7,999,999,999,999,999,999,999,999,999,999,999,999,999},
{999,999,999,999,999,999,999,999,999,7,999,999,999,999,999,999,999},
{999,999,999,999,999,999,8,999,999,999,999,999,999,999,999,999,999},
{999,999,999,999,4,999,6,999,999,999,999,999,999,999,999,999,999},
{999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999},
{999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999},
{999,999,4,999,999,999,999,999,999,12,999,999,999,999,999,999,8},
{999,999,999,999,999,999,999,999,999,999,4,16,999,999,999,999,999},
{999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999},
{999,999,999,999,999,999,999,999,999,999,999,999,9,999,999,7,999},
{999,999,999,999,999,999,999,999,999,999,999,999,999,4,4,999,999},
{999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999},
{999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999},
{999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999},
{999,999,999,999,999,999,999,6,999,999,999,999,999,999,999,999,999}
};

int sld[17]={13,15,17,18,6,10,12,26,21,24,27,11,4,6,0,12,23};
int min=999,pc=0,a=0,z=0,m=17;
int stack[20]={0};

int g,u=0,p=0,q=0;

void astar(int ,int );
void new_open(int );
void stack_check(int );
void fsort_init(void);
void printstack(void);


struct foo
{  
	int x;
	int y;
	int p;
	int pcost;
};

struct foo fsort[34];

void fsort_init()
{
	int i=0;
	for(i=0;i<34;i++)
	{
		fsort[i].p=999;
		fsort[i].x=999;
		fsort[i].y=999;
		fsort[i].pcost=-1;
	}
	//printf("%d",++count);
	/*	for(i=0;i<34;i++)
	{
		printf("%d\t",fsort[i].p);
		printf("%d\t",fsort[i].x);
		printf("%d\t",fsort[i].y);
		printf("%d\n",fsort[i].pcost);
	}*/
}



void stack_check(int k)
{
	//printf("%d",++count);
	int i;
	
//	for(i=0;i<17;i++)
	//{
		//if(pathcost[stack[i]][k]!=999)
		//if(pathcost[k][i]!=999)
	//	{
		if(pathcost[stack[a-1]][k]!=999)
		u=1;
		
		//break;
		//}
	//}
	if(pathcost[g][k]<999)
	{
		//printf("%d\n",k);
		for(i=0;i<20;i++)
		stack[i]=0;
		a=0;
		min=999,pc=fsort[k].pcost,a=0,z=0,m=17,u=0;
		astar(k,k);
	}
	else
	{
			//printf("hh%d\n",k);
	z=1;
	}
	if(u==1)
	z=0;
	if(k==1)
	q=1;
	
}

void printstack()
{
	//printf("%d",++count);
int l;

printf("%d->",g);
	for(l=0;l<=a;l++)
	printf("%d->",stack[l]);
	printf("r123 \n");
	printf("pathcost = %d\n",fsort[14].pcost);
}


void new_open(int f)
{
	int i,y,k;
	min=999;
	for(i=0;i<34;i++)
	{
		if(fsort[i].p==1 && fsort[i].x<min)
		{
			//	printf("x");
			min=fsort[i].x;
			y=fsort[i].y;
			k=i;
		}
	}
	//printf("%d\n",min);
	//printf("%d\n",y);
	//printf("%d\n",k);
	//return min;
	//printf("x");
	pc=pc+pathcost[f][y];
	
	if(pc>999)
	stack_check(y);
	
	
	if(pc>999 || (pc>fsort[k].pcost && fsort[k].p==1))
	 pc=fsort[k].pcost;
	  
  	//printf("%d\n---------------------------------------------\n",pc);
	 //j=i;
	 //printf("%d",++count);
	astar(y,k);
	//printf("%d",++count);
}


void astar(int f,int j)
{
	int h,i;
	for(i=0;i<17;i++)
	{
		h= pc+pathcost[f][i] + sld[i];
		if(h<999)
		{   
  			if(fsort[i].pcost==-1)
  			{
			fsort[i].p=1;
			fsort[i].x=h;
			fsort[i].y=i;
			fsort[i].pcost=pc+pathcost[f][i];
			
			/*printf("%d\t",fsort[i].x);
			printf("%d\t",fsort[i].y);
			printf("%d\t",fsort[i].p);
			printf("%d\n",fsort[i].pcost);*/
  			}
  			else
  			{
  				fsort[m].p=1;
  				fsort[m].x=h;
				fsort[m].y=i;
				fsort[m].pcost=pc+pathcost[f][i];
				
				/*printf("%d\t",fsort[i].x);
			printf("%d\t",fsort[i].y);
			printf("%d\t",fsort[i].p);
			printf("%d\n",fsort[i].pcost);*/
  				m++;
			  }
  			
			if(i==14)
			{
				stack[a]=j;
				printstack();
				exit(1);
			}
		}
	}
	fsort[j].p=0;
	for(i=0;i<34;i++)
	{
		if(fsort[i].y==j)
		fsort[i].p=0;
	}
	stack[a]=j;
	a++;
	if(z==1)
	{
	stack[a-1]=0;
	if(p==1 && q==1)
	{
		stack[a-2]=stack[a-3]=stack[a-4]=0;
		a=a-3;
		q=0;
	}
	z=0;
	--a;
	}
	//printf("%d",++count);
	new_open(f);
	//printf("%d",++count);
	
}
		
main()
{
	//printf("%d",count);
	fsort_init();
	printf("0.b1\n1.b2\n2.b3\n3.b4\n4.c1\n5.c2\n6.c3\n7.mail\n8.o103\n9.o109\n10.o111\n11.o119\n12.o123\n13.o125\n14.r123\n15.storage\n16.ts\n");
	printf("//IF THE .EXE IS NOT RESPONDING->NO PATH POSSIBLE FROM THE GIVEN INPUT NODE\n");
	printf("Enter the starting node number:");
	scanf("%d",&g);
	while(g<0 || g>16)
	{
	
	printf("Enter valid starting node number:");
	scanf("%d",&g);
	}
	if(g==2)
	p=1;
	astar(g,g);
}
