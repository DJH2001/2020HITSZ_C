#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Number:200110807\n");
    printf("subjectNo.2-program No.2\n\n");

    double a,b,c,p;
    double s;
    printf("请输入三个正数三边长a,b,c:\n");//限制输入条件为正数
    scanf("%lf%lf%lf",&a,&b,&c);
    do{

    if(a+b>c&&b+c>a&&b+a>c)//判断是三角形的条件
    {
        p=1/2.0*(a+b+c);//海伦公式
        s=sqrt(p*(p-a)*(p-b)*(p-c));//求三角形的面积
        printf("%lf\n",s);
        if(a==b&&b==c&&a==c)//判断三角形是否为等边三角形
        {
            printf("等边三角形");
        }
        else if(a==b||a==c||b==c)//判断三角形是否为等腰三角形
        {
            printf("等腰三角形");
        }
        else if((a==b&&a!=c&&a*a+b*b==c*c)||(a==c&&a!=b&&a*a+c*c==b*b)||(b==c&&b!=a&&b*b+c*c==a*a))//判断三角形为等腰直角三角形
        {
            printf("等腰直角三角形");
        }
        else if((a!=b&&a!=c&&b!=c&&a*a+b*b==c*c)||(a!=b&&a!=c&&b!=c&&a*a+c*c==b*b)||(a!=b&&a!=c&&b!=c&&b*b+c*c==a*a))//普通直角三角形
        {
            printf("直角三角形");
        }
        else
        {
            printf("一般三角形");
        }

     }
    else
        {
            printf("不是三角形");
        }
    }while(a<0||b<0||c<0);

    return 0;
}
