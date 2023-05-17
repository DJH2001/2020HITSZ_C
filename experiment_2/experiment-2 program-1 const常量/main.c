#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:200110807\n");
    printf("subjectNo.2-program No.1\n\n");

    const double PI=3.14159;//const定义PI的值
    double r;
    printf("Please input r:");//输入球的半径
    scanf("%lf",&r);
    printf("S=%lf\n",4*PI*r*r);//计算球的表面积
    printf("V=%lf\n",4.0/3*PI*r*r*r);//计算球的体积

    return 0;
}
