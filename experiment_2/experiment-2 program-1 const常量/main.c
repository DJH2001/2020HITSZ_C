#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110807\n");
    printf("subjectNo.2-program No.1\n\n");

    const double PI=3.14159;//const����PI��ֵ
    double r;
    printf("Please input r:");//������İ뾶
    scanf("%lf",&r);
    printf("S=%lf\n",4*PI*r*r);//������ı����
    printf("V=%lf\n",4.0/3*PI*r*r*r);//����������

    return 0;
}
