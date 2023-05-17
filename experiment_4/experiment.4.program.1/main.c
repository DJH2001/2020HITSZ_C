#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{

    int asking();/**定义一个提问的函数*/

    asking();
}
int asking()/**提问*/
{
    printf("Number:200110807\n");
    printf("subject No.4-program No.1\n\n\n");

    int i,j,sum,score;                          /**定义随机数*/
    int n=0;                                    /**n为错误次数*/
    int counter=0;                              /**counter为题目的数量*/
    float a;                                    /**用户输入的值*/
    srand(time(NULL));
    /**嵌套do while循环 小学生共进行三次运算*/
    do
    {
        /**选取i，j为1-10的随机数*/
        i=rand()%10+1;
        j=rand()%10+1;
        sum=i*j;
        printf("%d*%d=?\n", i,j);
        scanf("%f",&a);
        counter++;
        if(fabs(sum-a)<1e-6)                     /**不能直接判断是否相等，利用二者的差值在一个范围内，近似相等*/
        {
            score++;/**分数+1*/
            printf("Right!\n");
        }
        else
        {
            n++;                                /**错误次数+1*/
            do
            {
                printf("Wrong!Please try again!\n");
                scanf("%f",&a);
                if(a==sum)
                {
                    score++;
                    printf("Right!\n");
                }
                else
                {
                    n++;
                    do
                    {
                        printf("Wrong!Please try again!\n");
                        scanf("%f",&a);
                        if(a==sum)
                        {
                            score++;
                            printf("Right!\n");
                        }
                        else
                        {
                            n++;
                            printf("Wrong!Please try next subject!\n");
                        }
                    }
                    while(n<3);
                }
                while(n<3);
            }while(n<3);
        }
    }
    while(counter<10);/**执行十次后停止*/

    printf("你本次答题的正确率为%f\n",1.0*score/10);
    system("Pause");
    return 0;
}












