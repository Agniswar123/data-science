#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
float **ptr,*mincst,*min,*prev,*classlabel,*details;
int *med,*temp,k,*cost,row=150,col=4,a,b,c,d;
FILE *fp;

float rand_index()
{
	int i,j,k;
	float rival;
	a=0;
	b=0;
	c=0;
	d=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<row;j++)
		{
			if(classlabel[i]==classlabel[j])
			{
				if(details[i]==classlabel[j])
					a++;
				else
					c++;
			}
			else
			{
			if(details[i]==classlabel[j])
					d++;
				else
					b++;
			}
		}
	}
	rival=(a+b)/(a+b+c+d);
	printf("\nR V %f",rival);
}

float abs(float a, float b)
{
	float k;
	k=a-b;
	
	if(k>=0)
		return k;
	else
		return k*-1;
	
}

float costcurr()
{
	int i,j,m;
	float s=0,cost[k];
	min=(float*)malloc(150*sizeof(float));
	mincst=(float*)malloc(150*sizeof(float));
	for(i=0;i<150;i++)
	{
		for(j=0;j<k;j++)
		{
			s=0;
			for(m=0;m<5;m++)
			{
				s+=abs(ptr[temp[j]][m],ptr[i][m]);
			}
			cost[j]=s;
		}
		min[i]=0;
		mincst[i]=cost[0];
		for(j=0;j<k;j++)
		{
			if(mincst[i]>cost[j])
				{
					min[i]=j;
					mincst[i]=cost[j];
				}
		}
	}
	s=0;
	
	//total cost of whole one iteration
	for(i=0;i<150;i++)
		s+=mincst[i];
	/*minchk	
	for(i=0;i<150;i++)
	{
		printf(" %f ",min[i]);	
		
	}*/
	return s;
}

int main()
{
	int i,j,m,n,o,p,s=0;
	float temp1,money,min2,mincst2;
	
	//DMA
	ptr=(float**)malloc(150*sizeof(float*));
	for(i=0;i<150;i++)
		ptr[i]=(float*)malloc(5*sizeof(float));
		
	classlabel=(float*)malloc(row*sizeof(float));
	details=(float*)malloc(row*sizeof(float));	
	FILE *fp;
	fp=fopen("pqr.txt","r");
	if(fp==NULL)
		exit(0);
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
		fscanf(fp,"%f",&temp1);
		ptr[i][j]=temp1;
		}
		fscanf(fp,"%f",&temp1);
		classlabel[i]=temp1;
	}
	
	/*check inputted data
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%f ",ptr[i][j]);
			
		printf(" class:=%f",classlabel[i]);
			printf("\n");
	}*/
	
	printf("Enter No of Partitions\n");
	scanf("%d",&k);
	
	med=(int*)malloc(k*sizeof(int));
	cost=(int*)malloc(k*sizeof(int));
	for(i=0;i<k;i++)
		med[i]=i;
	temp=med;

	money=costcurr();

	
	for(i=k;i<row;i++)
	{
		temp=med;
		for(j=0;j<k;j++)
		{
			temp[j]=i;
			cost[j]=costcurr();
		}
		min2=0;
		mincst2=cost[0];
		for(m=0;m<k;m++)
			{
			if(mincst2>cost[m])
			{
				mincst2=cost[m];
				min2=m;
				printf(" %f ",m);
			}
			}
		if(mincst2<money)
			{
				money=mincst2;
				printf(" %d ",i);
				med[m]=i;
			}
		//printf("IT %d",i-k);
	}
	printf("\n%f",money);
	
	rand_index();
	fclose(fp);
	return 0;
}
