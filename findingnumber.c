#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 1000


//Finding numbers and sum it up
int main(int argc, char *argv[])
{
    FILE *data;
    char row[MAXLEN], *start;
    int n,i, sum;

    if (argc < 2)
    {
        fprintf(stderr, "data name is required!!\n");
        exit(1);
    }

    data = fopen(argv[1], "r");
    if(data == NULL){
        perror(argv[1]);
        exit(1);
    }

    sum = 0;

    while (fgets(row, MAXLEN, data) != NULL)
    {

        start = row;
        if(*start == (char)0 || *start == '#')
            continue;

        //Finding the first occurence
        while (strchr("1234567890", *start) == NULL)
            start++;

        while (*start != (char)0)
        {
            //Occurence found and check if it has only 3 digit of numbers
            if (isnumber(*(start - 1)) == 0 && isnumber(*(start + 1)) && isnumber(*(start + 2)) && isnumber(*(start + 3)) == 0)
            {   
                sscanf(start,"%d", &n );
                sum = sum + n;
                if (n != 0)
                    printf("|  %d  |",n); 
                
                n = 0;
                start += 3;
                continue;
            }
            start++;
        }     
    }
    printf("\n");
    printf("sum: %d\n",sum);
    
    return 0;
}

