#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{

    int asking();/**����һ�����ʵĺ���*/

    asking();
}
int asking()/**����*/
{
    printf("Number:200110807\n");
    printf("subject No.4-program No.1\n\n\n");

    int i,j,sum,score;                          /**���������*/
    int n=0;                                    /**nΪ�������*/
    int counter=0;                              /**counterΪ��Ŀ������*/
    float a;                                    /**�û������ֵ*/
    srand(time(NULL));
    /**Ƕ��do whileѭ�� Сѧ����������������*/
    do
    {
        /**ѡȡi��jΪ1-10�������*/
        i=rand()%10+1;
        j=rand()%10+1;
        sum=i*j;
        printf("%d*%d=?\n", i,j);
        scanf("%f",&a);
        counter++;
        if(fabs(sum-a)<1e-6)                     /**����ֱ���ж��Ƿ���ȣ����ö��ߵĲ�ֵ��һ����Χ�ڣ��������*/
        {
            score++;/**����+1*/
            printf("Right!\n");
        }
        else
        {
            n++;                                /**�������+1*/
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
    while(counter<10);/**ִ��ʮ�κ�ֹͣ*/

    printf("�㱾�δ������ȷ��Ϊ%f\n",1.0*score/10);
    system("Pause");
    return 0;
}












