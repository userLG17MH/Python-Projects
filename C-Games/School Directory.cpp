#include<stdio.h>
#include<conio.h>

int main()
{
	int ;
	printf("\n **MENU** ");
    printf("\n 1 Make A New Chart :O: ");
    printf("\n 2 Addition Of New Student :+: ");
    printf("\n 3 Transfer Of New Student :-: ");
    printf("\n 4 Name Wise Roll :/: ");
    printf("\n 5 Grading :*:");

    if (ch == 1)
    {
    	printf("\n Enter Department Name: ");
		printf("\n Enter Student Range: ");
		printf("\n Enter Year Of Addmission: ");
	}
	 
	else if (ch == 2) 
	{
		printf("\n Enter The Name Of Student: ");
        scanf("%d", &x);
        printf("\n Check Which Department Is Empty: ");
        scanf("%d", &x);
        printf("\n Enter Department: ");
        scanf("%d", &x);
    }
	     
    else if (ch == 3) 
	{
        printf("\n Enter Department: ");
        scanf("%d", &x);
        printf("\n Enter The Year: ");
        scanf("%d", &x);
        printf("\n Enter The Name Of Student: ");
        scanf("%d", &x);
    }
    
    else if (ch == 4) 
	{
        printf("\n Department Name - [BCA/BBA/HHM/BMLT] ");
        scanf("%d", &x);
        printf("\n Enter The Year: ");
        scanf("%d", &x);
        printf("\n Enter Section [A/B/C]: ");
        scanf("%d", &x);
    }
    
	else if (ch == 5)
	{
        printf("\n Department Name - [BCA/BBA/HHM/BMLT] ");
        scanf("%d", &x);
        printf("\n Enter The Year: ");
        scanf("%d", &x);
        printf("\n Enter Section [A/B/C]: ");
        scanf("%d", &x);
	}
	
	else
	{
        printf("\n !!Wrong Choice!!");
        printf("\n !!Try Again!!");
    }
    
	switch(ch) 
	{
        case 1:
       	{
            add(x, y, fptr);
            break;
        }
        case 2:
        {
		    leave(x, y, fptr);
            break;
        }
        case 3:
       	{
            roll(x, y, fptr);
            break;
        }
        case 4:
        {
            grade(x, y, fptr);
            break;
        }
        case 5:
        {
		    nwc(x,fptr);
		    break;
		}
		    
}