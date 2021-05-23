#include <stdio.h>
#include <stdlib.h>

char name[10];
char gender;
int age;

void writeDB(FILE* fp)
{
    int i;

    for (i=0;i<2;i++)
    {
        puts("name: " );scanf("%s",name);getchar();
        puts("gender: ");scanf("%c",&gender);getchar();
        puts("age: ");scanf("%d", &age);
        fprintf(fp, "%s %c %d \n", name,gender,age);
    }
}

void readDB(char* fileName)
{

    int n ;
    FILE* fp = fopen(fileName, "rt");
    if (fp != NULL)
    {
        while(1)
            {
                int ret = fscanf(fp,"%s %c %d ", name, &gender, &age);
                //printf("read done \n");
                if (ret == EOF)
                    break;
                printf("%s %c %d \n", name, gender, age);
        }
    }
    else
        puts("file open error");
    fclose(fp);
}

int main()
{

    char* fileName = "friend.txt";  // file name
    FILE* fp = fopen(fileName, "wt"); // file open
    writeDB(fp); // write
    fclose(fp); // file close
    readDB(fileName); // read DB
    return 0;
}
