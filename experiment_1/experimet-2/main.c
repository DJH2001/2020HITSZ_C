#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110807\n");
    printf("subject No.1-program No.2\n\n");

    char ch;
    int i,num,j;//num����������
    printf("Input the letter:\n");
    scanf("%c",&ch);
    printf("Input the number:\n");
    scanf("%d",&num);
    ch=ch-32;//��Сд��ĸת���ɴ�д��ĸ

    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num-i;j++)//�ո�
        {
            printf("  ");
        }
        for(j=1;j<=4*i-3;j++)//ÿ�е���ĸ��
        {
            printf("%c",ch);//��ӡ
        }
        printf("\n");
    }
    system("Pause");
    return 0;
}
