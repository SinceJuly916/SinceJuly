#include<stdio.h>
typedef struct Teac
{
	Stu a;
	int num;
	char name[20];
	int age;
}b;
struct Stu
{
	int num;
	char name[20];
	int age;
	char tele[13];
	char sex[10];
	double idcard;
}b;
void print1(Stu* a)//传址方式
{
	printf("%d\n", a->num);
	printf("%s\n", a->name);
	printf("%d\n", a->age);
	printf("%s\n", a->tele);
	printf("%s\n", a->sex);
	printf("%lf\n", a->idcard);
}
void print(Stu a)//传参方式
{
	printf("%d\n",a.num);
	printf("%s\n", a.name);
	printf("%d\n", a.age);
	printf("%s\n", a.tele);
	printf("%s\n", a.sex);
	printf("%lf\n", a.idcard);

}
int main()
{
	Stu a = {1,"雷蒙",24,"18999999999","男",61012519970916};//初始化
	b = { {a} ,2,"刘高辉",50};
	print(a);
	print1(&a);
	return 0;

}