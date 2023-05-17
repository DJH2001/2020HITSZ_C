#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110807\n");
    printf("subject No.1-program No.2\n\n");

    char ch;
    int i,num,j;//num定义总行数
    printf("Input the letter:\n");
    scanf("%c",&ch);
    printf("Input the number:\n");
    scanf("%d",&num);
    ch=ch-32;//将小写字母转换成大写字母

    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num-i;j++)//空格
        {
            printf("  ");
        }
        for(j=1;j<=4*i-3;j++)//每行的字母数
        {
            printf("%c",ch);//打印
        }
        printf("\n");
    }
    system("Pause");
    return 0;
}
