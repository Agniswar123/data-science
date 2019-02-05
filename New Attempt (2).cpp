#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
float **ptr,*mincst,*min,*prev,*kdata,*classlabel;
int *med,*temp,k,*next,row=150,col=4;
FILE *fp;

/*float abs(float a, float b)
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
	min=(float*)malloc(row*sizeof(float));
	mincst=(float*)malloc(row*sizeof(float));
	for(i=0;i<row;i++)
	{
		for(j=0;j<k;j++)
		{
			s=0;
			for(m=0;m<col;m++)
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
	for(i=0;i<row;i++)
		s+=mincst[i];
	return s;
}*/

int main()
{
	int i,j,m,n,o,p,s=0;
	float temp1,money,min2,mincst2;
	
	//DMA
	ptr=(float**)malloc(6304*sizeof(float*));
	for(i=0;i<6304;i++)
		ptr[i]=(float*)malloc(col*sizeof(float));
		
	kdata=(float*)malloc(row*sizeof(float));
	classlabel=(float*)malloc(row*sizeof(float));
	
	FILE *fp;
	fp=fopen("pqr.txt","r");
	
	if(fp==NULL)
		printf("Failed");
	
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
	
	//check inputted data
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%f ",ptr[i][j]);
			printf("\n");
	}
	
	fclose(fp);
	
	if(getch())
	{
		return 0;
	}
	
	
}
