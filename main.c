#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int numbers[] = { 456,345,678,567,890,456,3456,123,765,456,896,456,678,987,000,145,90};

int  someData = 90;

void array_fill_numbers(int pNumbers[], unsigned int len)
{

    for ( unsigned int i = 0 ; i < len ; i++)
    {
        pNumbers[i] = rand() % 1000;
    }

}

void display_numbers(int *pNumbers, unsigned int len, char *pMessage)
{
    printf("%s",pMessage);

    for (unsigned i = 0 ; i < len ; i++)
    {
        printf("%5d  ",pNumbers[i]);
    }

    printf("\n");
}


void swap_numbers(int *x,int *y)
{
     int temp=*x;
     *x=*y;
     *y=temp;

#if 0
     void (*jump_addr) (void);
     jump_addr = (void*)0x20000009;
     jump_addr();
#endif

     someData = 10;
}


void bubble_sort(int *pNumbers , unsigned int len)
{

    int i,j,flag=0;

    for(i=0;i<len-1;i++)
    {
        flag=0;

        for(j=0;j<len-1-i;j++)
        {
            if(pNumbers[j] > pNumbers[j+1])
            {
                swap_numbers(&pNumbers[j],&pNumbers[j+1]);
                flag=1;
            }
        }

        if(flag==0)
            break;
    }
}

void insertion_sort(int *pNumbers , unsigned int len)
{

     int i,j,num;

     for(i=1 ; i<len ; i++)
     {
         j=i-1;

         num = pNumbers[i];

         while( (j>-1) && (pNumbers[j] > num) )
         {
             pNumbers[j+1] = pNumbers[j];
             j--;
         }

         pNumbers[j+1]=num;
     }


}



int main()
{
	// in this we not need to learn code this is for understand how line debbuging hapend its happend in
	// in this we observe step in step down and diffrent which debug line by line and change value


    unsigned int len = sizeof(numbers)/sizeof(int);

    array_fill_numbers(numbers,len);

    // brack point is use to stop or not exicute code at that point we can put it by doble click on line
    //or put curser on line and in run-->toggle brackpoint
    // we see brackpoint in debug mode and then window-->short view--> brackpoint therir we see all our point

    display_numbers(numbers,len,"B-unsorted array :");

    bubble_sort(numbers,len);

    display_numbers(numbers,len,"B-sorted array   :");

    array_fill_numbers(numbers,len);

    display_numbers(numbers,len,"I-unsorted array :");

    insertion_sort(numbers,len);

    display_numbers(numbers,len,"I-sorted array   :");



    return 0;
}
