#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define INFINITY 9999
#define MAX 10

void dijikstra(int G[MAX][MAX], int n, int startnode,int terminalnode,int vx[MAX]);

void main(){
	int gdriver=DETECT,gmode;
	int x[10],y[10];
	int vx[10];
	int count;
	int opt;
	int G[MAX][MAX], i, j, n, u , v;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	line(getmaxx()/2,0,getmaxx()/2,getmaxy());//put up a line between the graphical representation
	//x and y are the initial point on the top left corner of the half screen
	printf("\nEnter the no. of vertices:: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix::\n");
	for(i=1;i <=n;i++)
		for(j=1;j <=n;j++)
			scanf("%d", &G[i][j]);
	printf("\nEnter the starting node:: ");
	scanf("%d", &u);
	printf("\nEnter the terminal node:: ");
	scanf("%d",&v);
			    x[0]=getmaxx()/2;
				y[0]=0;
			for(i=1;i<=n;i++)
			{
			if(i%2==0)
			x[i]=x[i-1]+40;
			else{
			x[i]=x[i-1]+40;
			y[i]=y[i-1]+40;
			}
			circle(20+x[i],10+y[i],10);
			switch(i){
			case 1:
			outtextxy(20+x[i],10+y[i],"1");
			break;
			case 2:
			outtextxy(20+x[i],10+y[i],"2");
			break;
			case 3:
			outtextxy(20+x[i],10+y[i],"3");
			break;
			case 4:
			outtextxy(20+x[i],10+y[i],"4");
			break;
			case 5:
			outtextxy(20+x[i],10+y[i],"5");
			break;
			case 6:
			outtextxy(20+x[i],10+y[i],"6");
			break;
			case 7:
			outtextxy(20+x[i],10+y[i],"7");
			break;
			case 8:
			outtextxy(20+x[i],10+y[i],"8");
			break;
			}
			}
			//Step1 : Creating a Graph
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if(G[i][j] != INFINITY && G[i][j]!=0)
					line(20+x[i],10+y[i],20+x[j],10+y[j]);
				}
			for(i=1;i<=n;i++)
			y[i]+=200;//shift down to the final graph
	dijikstra(G,n,u,v,vx);
				count=1;
				while(vx[count]!=INFINITY)
				{
					setcolor(BLUE);
					circle(20+x[vx[count]],10+y[vx[count]],10);
					switch(vx[count])
						{
						case 1:
						outtextxy(20+x[vx[count]],10+y[vx[count]],"1");
						break;
						case 2:
						outtextxy(20+x[vx[count]],10+y[vx[count]],"2");
						break;
						case 3:
						outtextxy(20+x[vx[count]],10+y[vx[count]],"3");
						break;
						case 4:
						outtextxy(20+x[vx[count]],10+y[vx[count]],"4");
						break;
						case 5:
						outtextxy(20+x[vx[count]],10+y[vx[count]],"5");
						break;
						case 6:
						outtextxy(20+x[vx[count]],10+y[vx[count]],"6");
						break;
						case 7:
						outtextxy(20+x[vx[count]],10+y[vx[count]],"7");
						break;
						case 8:
						outtextxy(20+x[vx[count]],10+y[vx[count]],"8");
						break;
						}
					count++;
				}
				//connecting the path
				i=1;
				while(vx[i]!=INFINITY)
				{
					if(G[vx[i]][vx[i+1]] !=INFINITY && G[vx[i]][vx[i+1]]!=0)
					line(20+x[vx[i]],10+y[vx[i]],20+x[vx[i+1]],10+y[vx[i+1]]);
					i++;
				}
				getch();
				closegraph();
}

void dijikstra(int G[MAX][MAX], int n, int startnode,int terminalnode,int v[MAX])
{
	int k=1;//final path vertices number
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j;
	v[k]=startnode;
	k=k+1;
	for(i=1;i <=n;i++)
		for(j=1;j<=n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	for(i=1;i<=n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	//main logic
	while(count <=n){
		mindistance=INFINITY;
		for(i=1;i <=n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=1;i <=n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
	
	for(i=1;i<=n;i++)
		if(i!=startnode && i==terminalnode)
		{
			printf("\nThe distance of %d from %d = %d", terminalnode,startnode, distance[i]);
			printf("\nMinimum Shortest Path = %d-->",startnode);
			j=i;
			do
			{
				j=pred[j];
				if(j!=startnode)
			{	
				printf("%d-->", j);
				v[k]=j;
				k=k+1;
			}
				else
				break;
			}
			while(j!=startnode);
			printf("%d",i);
			v[k]=i;
		}
		k=k+1;
		v[k]=INFINITY;
}
