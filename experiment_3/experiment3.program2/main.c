#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    printf("Number:200110807\n");
    printf("subject No.3-program No.1\n\n");
    int i;
    double sum=0;
    for(i=1;i<=64;i++)
    {

        sum=sum+pow(2,i-1);
    }
    printf("��������Ҫ%e������\n",sum);
    printf("��Щ�����൱��%e������",sum/1.42e8);

    return 0;
}
