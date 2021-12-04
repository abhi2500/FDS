//Assignment 2, B233
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int n;
struct cricket
{
char name[23], country[23], category[23];
int age, odi, t20, batscore, wkt;
};

void bat_country(struct cricket p[]);
void bowl_country(struct cricket p[]);
void maxwickets(struct cricket p[]);
void display_one(struct cricket p[]);
void max_avg_score(struct cricket p[]);


int main()
{
struct cricket s[10];
int i, obs;
char cntry[25], num[25];
printf("\nEnter the number of players: ");
scanf("%d",&n);
printf("\nEnter data of %d players:\n",n);
for(i=0;i<n;i++)
{
  printf("Enter name of the player: ");
scanf("%s", s[i].name);
printf("Enter age of the player: ");
scanf("%d", &s[i].age);
printf("Enter country of the player: ");
scanf("%s", s[i].country);
printf("Enter category of the player: ");
scanf("%s", s[i].category);
printf("Enter Number of ODIs played: ");
scanf("%d", &s[i].odi);
printf("Enter Number of 20-20s played: ");
scanf("%d", &s[i].t20);
printf("Enter Average batting score: ");
scanf("%d", &s[i].batscore);
printf("Enter Total number of wickets taken: ");
scanf("%d", &s[i].wkt);
}

do
{
printf("\n\nCheck the data as\n1) Number of batsman of a particular country \n");
printf("2) Number of bowlers of a particular country  \n");
printf("3) Bowler with maximum wickets \n");
printf("4) Display board information of players \n");
printf("5) Display average batting score of a particular player.\n");
printf("6) Exit\n");
printf("Enter you choice: ");
scanf("%d",&obs);

switch(obs)
{
  case 1: bat_country(s);
  break;

  case 2: bowl_country(s);
  break;

  case 3: maxwickets(s);
  break;

  case 4: display_one(s);
  break;

  case 5: max_avg_score(s);
  break;


  default:printf("\nThank you.....!");
}
}while(obs!=6);
}

void bat_country(struct cricket p[])
{
  int ctr;
  char x[25];
  ctr=0;
printf("\nEnter country to display number of batsman: ");
scanf("%s",x);
for(int i=0; i<n; i++)
{
if((strcmp(x,p[i].country)==0)&&(strcmp("batsman",p[i].category)==0))
ctr++;
}
printf("\nNo. of batsman of country %s = %d ",x,ctr);
}

void bowl_country(struct cricket a[])
{
 int count=0;
 char cntry[15];
printf("\nEnter country to display number of bowlers: ");
scanf("%s", cntry);
for(int i=0; i<n; i++)
{
if((strcmp(cntry,a[i].country)==0)&&(strcmp("bowler",a[i].category)==0))
count++;
}
printf("\nNumber of bowlers of a %s country= %d ", cntry,count);
}

void maxwickets(struct cricket p[])
{
int count=0;
int index=0;
for(int i=0; i<n; i++)
{
if(strcmp("bowler",p[i].category)==0)
{
if (p[i].wkt>count)

{
count=p[i].wkt;
index=i;
}
}
}
printf("\n Name of Bowler taken max no of wickets is= %s\n", p[index].name);
}

void display_one(struct cricket p[])
{
 printf("\n name\t age\tcountry\tcategory\tODI\tT_20\tbatscore\twicket");
    for(int j=0;j<n;j++)
    {
      printf("\n%s\t%d\t%s\t%s\t\t%d\t%d\t%d\t%d",p[j].name,p[j].age,p[j].country,p[j].category,p[j].odi,p[j].t20,p[j].batscore,p[j].wkt);
    }

}

void max_avg_score(struct cricket p[])
{
int count=p[0].batscore;
int index=0;
for(int i=0; i<n; i++)
{
if(strcmp("batsman",p[i].category)==0)
{
if (p[i].batscore>count)
{
count=p[i].batscore;
index=i;
}
}
}
printf("\n Name of Batsman with highest average score is %s with score=%d\n",p[index].name,count);
}
