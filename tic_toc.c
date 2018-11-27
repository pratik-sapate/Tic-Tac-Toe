#include<stdio.h>
//display grid after each tern
void display(char mat[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("|");
		for(j=0;j<3;j++)
		{
			printf("%2c |",mat[i][j]);
		}	
		printf("\n");
	}
}
//logic for win
int check_matrix(char mat[3][3])
{
	int i,j;
	
	if(((mat[0][0]==mat[1][1]&& mat[1][1]==mat[2][2])&&(mat[0][0]!=5))||((mat[0][2]==mat[1][1]&& mat[1][1]==mat[2][0])&&(mat[0][2]!=5)))
		return 0;
	for(i=0;i<3;i++)
	{	
		if(((mat[i][0]==mat[i][1]&& mat[i][1]==mat[i][2])&&(mat[i][0]!=5))||(mat[0][i]==mat[1][i]&& mat[1][i]==mat[2][i])&&(mat[0][i]!=5))
			return 0;
	} 
	return 1;
}
int main()
{
	char names[2][10];
	char matrix[3][3]={5,5,5,5,5,5,5,5,5};
	char bit[2]={'A','B'};
	int i,j,x,y;
	printf("enter first player name\n");
	scanf("%s",names[0]);

	printf("enter second player name\n");
	scanf("%s",names[1]);

	printf("%s uses => %c\n",names[0],bit[0]);
	printf("%s uses => %c\n",names[1],bit[1]);
	display(matrix);
	for(i=0;i<9;i++)
	{
		do
		{
			printf("%s its your turn please place coodinate(x,y)\n",names[i%2]);
			scanf("%d%d",&x,&y);
			if(x<1||y<1||x>3||y>3)
				printf("please enter between (1,1) and (3,3)\n");
				
			else if(matrix[x-1][y-1]!=5)
			{
				printf("you cannot enter here, select diffrent co ordinate\n");
			}
		}while((x<1||y<1||x>3||y>3)||(matrix[x-1][y-1]!=5));
			
		matrix[x-1][y-1]=bit[i%2];
		display(matrix);
		if(!(check_matrix(matrix)))
		{
			printf("congrats %s is winner\n",names[i%2]);
			break;
		}

	}

	if(i==9)
	{
		printf("Match is drow !! try again\n");
	}
}
