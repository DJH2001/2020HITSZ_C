#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    int b;
    short int c;
    float d;
    double e;
    printf("Number:200110807\n");
    printf("subject No.1-programNo.1\n\n");

    printf("Please input the firs pinyin character of your last name:");
    scanf("%c",&a);
    printf("The first name Pinyin character of your last name is %c,size of char is %d\n\n",a,sizeof(a));//��ӡ��ĸ��char������ռ�ֽ�

    printf("Please input your age(short int):");
    scanf("%d",&c);
    printf("Your age is%d,size of short is %d\n\n",c,sizeof(b));//��ӡ�����short int������ռ�ֽ�

    printf("Please input your weight(int):");
    scanf("%d",&b);
    printf("Your weight is%d,size of int is %d\n\n",b,sizeof(int));//������غ�int������ռ�ֽ�

    printf("Please input your height(float):");
    scanf("%f",&d);
    printf("Your height is%0.1f,size of float is %d\n\n",d,sizeof(float));//�����ߺ�float������ռ�ֽ�

    printf("Please input your schoolID(double):");
    scanf("%f",&e);
    printf("Your schoolID is%f,size of double is %d\n\n",e,sizeof(double));//��ӡѧ�ź�double������ռ�ֽ�

    system("Pause");


    return 0;

}

