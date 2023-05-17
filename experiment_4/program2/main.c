#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void right();//正确的回答函数
void wrong();//错误的回答的函数

int main()
{
    printf("Number:200110807\n");
    printf("subject No.4-program No.2\n\n\n");

    int i,j,a,sum,t;
    int counter=0;
    int score=0;
    int n=0;
    srand((unsigned)time(NULL));//产生随机数
    do
    {
        score=0;
        do
        {
            i=rand()%10+1;
            j=rand()%10+1;
            //产生1-10的随机数

            t=rand()%4+1;
            //产生四则运算的符号

            counter++;//次数的+1
            if(t==1)
            {
                do
                {
                    n++;
                    sum=i+j;
                    printf("%d+%d=?\n",i,j);
                    scanf("%d",&a);
                    if(fabs(sum-a)<1e-6)//判断实际值与用户输入的数值是否相等
                    {
                        score++;//得分+1
                        right();//调用right函数
                    }
                    else
                    {
                        wrong();//调用wrong函数
                    }
                }
                while(n<1);//计算一次结束循环
            }
            //当t的随机数为1时候，计算加法
            if(t==2)
            {
                do
                {
                    n++;
                    sum=i-j;
                    printf("%d-%d=?\n",i,j);
                    scanf("%d",&a);
                    if(fabs(sum-a)<1e-6)//判断实际值与用户输入的数值是否相等
                    {
                        score++;//分数+1
                        right();//调用right函数
                    }
                    else
                    {
                        wrong();//调用wrong函数
                    }
                }
                while(n<1);
            }
            //当t=2的时候计算减法
            if(t==3)
            {
                do
                {
                    n++;
                    sum=i*j;
                    printf("%d*%d=?\n",i,j);
                    scanf("%d",&a);
                    if(fabs(sum-a)<1e-6)//判断实际值与用户输入的数值是否相等
                    {
                        score++;
                        right();//调用right函数
                    }
                    else
                    {
                        wrong();//调用wrong函数
                    }
                }
                while(n<1);
            }
            //当t=3的时候计算乘法
            if(t==4)
            {
                do
                {
                    n++;
                    sum=1.0*i/j;
                    printf("%d/%d=?\n",i,j);
                    scanf("%d",&a);
                    if(fabs(sum-a)<1e-6)//判断实际值与用户输入的数值是否相等
                    {
                        score++;
                        right();//调用right函数
                    }
                    else
                    {
                        wrong();//调用wrong函数
                    }
                }
                while(n<1);//只允许计算一次
            }
            //当t=4的时候计算除法
        }
        while(counter<10);//循环结束条件次数=10
        printf("\n");
        printf("执行次数%d\n",counter);
        printf("你的分数是%d\n",score);
        if(score>=8)//判断用户得分情况
        {
            printf("Your have passed this test!\n");
            counter=11;
        }
        else
        {
            printf("No!You have to the next test!\n");
            counter=0;
        }
    }
    while(counter<10);
    //只有当用户得分情况大于等于8的时候，才能结束题目的训练
    system("Pause");
    return 0;
}
/****************************************************
**函数名称：right
**函数功能：当小学生回答正确的时候，给出不同情景的答复
****************************************************/
void right()
{
    int b;
    switch(b=rand()%3+1)
    {
    case 1:
    {
        printf("Well done!\n");
        break;
    }

    case 2:
    {
        printf("Excellent!\n");
        break;
    }

    case 3:
    {
        printf("Good job!\n");
        break;
    }

    }
}
/****************************************************
**函数名称：wrong
**函数功能：当小学生回答错误的时候，给出不同情景的答复
****************************************************/
void wrong()
{
    int b;
    switch(b=rand()%3+1)
    {
    case 1:
    {
        printf("Keep trying!\n");
        break;
    }

    case 2:
    {
        printf("Be careful!\n");
        break;
    }

    case 3:
    {
        printf("Don't give up!\n");
        break;
    }

    }
}
