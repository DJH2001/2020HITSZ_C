#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110807\n");
    printf("subject No.3-program No.1\n\n\n");
    int i,j;
    int count=0;
    int a,b,c,d,m;
    for(i=300;i<=500;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                 break;//找到除了1和本身之外可以被该数整除的数字
            }
        }
        if(j>=i)//根据循环可知如果是素数j++后会大于等于i
        {
            count++;
            printf("%d  ",i);//打印素数
            if(count%10==0)
            {
                printf("\n");//实现每十个换一行
            }
        }
    }
    printf("\n\n");
    int l=0;

    for(i=300;i<=500;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                 break;
            }
        }
        if(j>=i)
        {

            a=i%10;
            b=i/10;
            c=b%10;
            d=b/10;
            m=a*100+c*10+d;
            l++;
            printf("%d  ",m);
            if(l%10==0)
            {
                printf("\n");
            }
        }
    }

    return 0;
}
