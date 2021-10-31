//program for set operations, practical assignment FDS 01
#include <stdio.h>
#define size 5
void accept (int *p);
void display (int *ptr, int n);
void Union (int p[], int q[], int m);
void Intersection (int a[], int b[], int m);
void Substraction1 (int p[], int q[], int n);
void Substraction2 (int p[], int q[], int n);
void symmdif (int p[], int q[], int m);

int main ()
{
  int arr1[size], arr2[size], n;
  printf ("Enter the 1st set:\n");
  accept (arr1);
  printf
    ("\n\t\t**************************************\t\t\n");
  printf ("\n\nEnter the 2nd set:");
  accept (arr2);
  printf ("The  first set is: ");
  display (arr1, size);
  printf ("The  second set is: ");
  display (arr2, size);
  do
    {
      printf("What operation do you want to do?");
      printf ("\n1: union\n");
      printf ("2: Intersection\n");
      printf ("3: Difference(arr1 -arr2)\n");
      printf ("4: Difference(arr2-arr1)\n");
      printf ("5: Symmetric difference of two sets\n");
      printf ("6: Stop\n");
      printf ("Enter your choice:");
      scanf ("%d", &n);
      switch (n)
	{
	case 1:

	  Union (arr1, arr2, size);
	  break;
	case 2:
	  Intersection (arr1, arr2, size);
	  break;
	case 3:
	  Substraction1 (arr1, arr2, size);
	  break;
	case 4:
	  Substraction2 (arr1, arr2, size);
	  break;
	case 5:
	  symmdif (arr1, arr2, size);
	  break;
	case 6:
	  break;
	}
 }
  while (n != 6);

  return 0;
}

void accept (int *p)
{
  for (int i = 0; i < size; i++)
    {
      printf ("Enter element:  %d  ", i + 1);
      scanf ("%d", &p[i]);
    }
}

void display (int *p, int n)
{

  printf ("\n{");
  for (int i = 0; i < n; i++)
    {
      printf (" %d ", p[i]);

    }
  printf ("}\n");

}

void Union (int p[], int q[], int m)
{
  int k = 0, c[2 * m], flag = 0;
  for (int i = 0; i < m; i++)
    {
      c[k] = p[i];
      k++;
    }
  for (int j = 0; j < m; j++)
    {
      flag = 0;
      for (int a = 0; a < m; a++)
	{
	  if (c[a] == q[j])
	    {
	      flag = 1;
	      break;
	    }

	}
      if (flag == 0)
	{
	  c[k] = q[j];
	  k++;
	}
    }
  printf ("the union of the set is :");
  printf ("\n{");
  for (int i = 0; i < k; i++)
    {
      printf (" %d", c[i]);
    }
  printf ("}");
}

void Intersection (int a[], int b[], int m)
{
  int c[2 * m], k = 0;
  for (int i = 0; i < m; i++)
    {

      for (int j = 0; j < m; j++)
	{
	  if (a[i] == b[j])
	    {
	      c[k] = a[i];
	      k++;
	    }
	}
   }
  printf ("the itersection is : ");
  printf ("\n{");
  for (int i = 0; i < k; i++)
    {
      printf (" %d ", c[i]);
    }
  printf ("}");
}

void Substraction1 (int p[], int q[], int n)
{
  int c[2 * n], k = 0, flag = 0;
  for (int i = 0; i < n; i++)
    {
      flag = 0;
      for (int j = 0; j < n; j++)
	{

	  if (p[i] == q[j])
	    {
	      flag = 1;
	      break;
	    }

	}
      if (flag == 0)
	{
	  c[k] = p[i];
	  k++;
	}

    }
  printf ("the substraction arr1-arr2 is : ");
  printf ("\n{");
  for (int i = 0; i < k; i++)
    {
      printf (" %d ", c[i]);
    }
  printf ("}");
}

void Substraction2 (int p[], int q[], int n)
{
  int c[2 * n], k = 0, flag = 0;
  for (int i = 0; i < n; i++)
    {
      flag = 0;
      for (int j = 0; j < n; j++)
	{

	  if (q[i] == p[j])
	    {
	      flag = 1;
	      break;
	    }

	}
      if (flag == 0)
	{
	  c[k] = q[i];
	  k++;
	}

    }
  printf ("the substraction arr2-arr1 is : ");
  printf ("\n{");
  for (int i = 0; i < k; i++)
    {
      printf (" %d ", c[i]);
    }
  printf ("}");
}


void symmdif (int p[], int q[], int m)
{
  int k = 0, c[2 * m], flag = 0;

  for (int j = 0; j < m; j++)
    {
      flag = 0;
      for (int a = 0; a < m; a++)
	{
	  if (p[a] == q[j])
	    {
	      flag = 1;
	      break;
	    }

	}
      if (flag == 0)
	{
	  c[k] = q[j];
	  k++;

	}
      if (flag == 0)
	{
	  c[k] = p[j];
	  k++;
	}
    }
  printf ("the symmetric difference of the set is :");
  printf ("\n{");
  for (int i = 0; i < k; i++)
    {
      printf (" %d", c[i]);
    }
  printf ("}");
}
