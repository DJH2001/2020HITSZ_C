#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Number:200110807\n");
    printf("subjectNo.2-program No.2\n\n");

    double a,b,c,p;
    double s;
    printf("�����������������߳�a,b,c:\n");//������������Ϊ����
    scanf("%lf%lf%lf",&a,&b,&c);
    do{

    if(a+b>c&&b+c>a&&b+a>c)//�ж��������ε�����
    {
        p=1/2.0*(a+b+c);//���׹�ʽ
        s=sqrt(p*(p-a)*(p-b)*(p-c));//�������ε����
        printf("%lf\n",s);
        if(a==b&&b==c&&a==c)//�ж��������Ƿ�Ϊ�ȱ�������
        {
            printf("�ȱ�������");
        }
        else if(a==b||a==c||b==c)//�ж��������Ƿ�Ϊ����������
        {
            printf("����������");
        }
        else if((a==b&&a!=c&&a*a+b*b==c*c)||(a==c&&a!=b&&a*a+c*c==b*b)||(b==c&&b!=a&&b*b+c*c==a*a))//�ж�������Ϊ����ֱ��������
        {
            printf("����ֱ��������");
        }
        else if((a!=b&&a!=c&&b!=c&&a*a+b*b==c*c)||(a!=b&&a!=c&&b!=c&&a*a+c*c==b*b)||(a!=b&&a!=c&&b!=c&&b*b+c*c==a*a))//��ֱͨ��������
        {
            printf("ֱ��������");
        }
        else
        {
            printf("һ��������");
        }

     }
    else
        {
            printf("����������");
        }
    }while(a<0||b<0||c<0);

    return 0;
}
