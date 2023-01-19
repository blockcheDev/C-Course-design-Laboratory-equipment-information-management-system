#include "function.h"
#include "Lock.h"

void user() {
	int n = 0;
	LinkList* L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;

chose:
	system("cls");
	printf("\
---------------------------------------------\n\
|       请选择你要进行的操作                |\n\
|       1、实验设备信息查询                 |\n\
|       2、实验设备信息按编号排序           |\n\
|       3、实验设备信息总览                 |\n\
|       4、读取设备信息                     |\n\
|       5、查看实验室负责人信息             |\n\
|       6、返回欢迎界面                     |\n\
---------------------------------------------\n\
");

	int op;
	scanf_s("%d", &op);
	switch (op) {

	case 1:
		system("cls");
		printf("\
------------------------------------\n\
|       请选择你要进行的操作       |\n\
|       1、按器材名称查询          |\n\
|       2、按器材编号查询          |\n\
------------------------------------\n\
");
		LinkList* e = NULL;
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			printf("请输入器材名称：\n");
			char name[20];
			scanf_s("%s", name, 20);
			e = Find_Name(L, name);
			goto chose;
		case 2:
			printf("请输入器材编号：\n");
			int ID;
			scanf_s("%d", &ID);
			e = Find_ID(L, ID);
			goto chose;
		default:
			system("cls");
			printf("参数错误，重新输入。\n");
			system("pause");
			goto chose;
		}

	case 2:
		L = Sort(L, n);
		goto chose;
	case 3:
		system("cls");
		PrintAll(L, n);
		goto chose;
	case 4:
		system("cls");
		L = Read(&n);
		goto chose;
	case 5:
		system("cls");
		printf("实验室负责人：车文超\n");
		printf("负责人班级：21计算机科学与技术2班\n");
		printf("负责人电话：13112690721\n");
		printf("\n如果对实验室有疑问，请通过电话联系负责人。\n");
		system("pause");
		goto chose;
	case 6:
		return;
	default:
		system("cls");
		printf("参数错误，重新输入。\n");
		system("pause");
		goto chose;
	}
}

void admin() {
	system("cls");

	if (!Lock()) {
		printf("\n账号或密码错误\n");
		system("pause");
		return;
	}

	int n = 0;
	LinkList* L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;

chose:
	system("cls");
	printf("\
---------------------------------------------\n\
|       请选择你要进行的操作                |\n\
|       1、实验设备信息录入                 |\n\
|       2、实验设备信息添加                 |\n\
|       3、实验设备信息查询（修改、删除）   |\n\
|       4、实验设备信息按编号排序           |\n\
|       5、实验设备信息总览                 |\n\
|       6、保存设备信息                     |\n\
|       7、读取设备信息                     |\n\
|       8、查看实验室负责人信息             |\n\
|       9、修改管理员账号密码               |\n\
|       10、返回欢迎界面                    |\n\
---------------------------------------------\n\
");
	
	//12 胶头滴管 10ml 5 2023.1.1 转移液体
	//1 胶头滴管 15ml 7 2023.1.1 转移液体

	int op;
	scanf_s("%d", &op);
	switch (op) {
	case 1:
		n = Init(&L);
		goto chose;
	case 2:
		L = Add(L, &n);
		goto chose;
	case 3:
		system("cls");
		printf("\
------------------------------------\n\
|       请选择你要进行的操作       |\n\
|       1、按器材名称查询          |\n\
|       2、按器材编号查询          |\n\
------------------------------------\n\
");
		LinkList* e = NULL;
		int op1;
		scanf_s("%d", &op1);
		switch (op1) {
		case 1:
			printf("请输入器材名称：\n");
			char name[20];
			scanf_s("%s", name, 20);
			e = Find_Name(L, name);
			if (e == NULL) goto chose;
			goto change;
		case 2:
			printf("请输入器材编号：\n");
			int ID;
			scanf_s("%d", &ID);
			e = Find_ID(L, ID);
			if (e == NULL) goto chose;
			goto change;
		default:
			system("cls");
			printf("参数错误，重新输入。\n");
			system("pause");
			goto chose;
		}
change:
		printf("\
------------------------------------\n\
|       请选择你要进行的操作       |\n\
|       1、更改信息                |\n\
|       2、删除设备                |\n\
|       3、返回菜单                |\n\
------------------------------------\n\
");
		int op2;
		scanf_s("%d", &op2);
		switch (op2) {
		case 1:
			L = Change(L, e);
			goto chose;
		case 2:
			L = Delete(L, e, &n);
			goto chose;
		case 3:
			goto chose;
		default:
			goto chose;
		}
	case 4:
		L = Sort(L, n);
		goto chose;
	case 5:
		system("cls");
		PrintAll(L, n);
		goto chose;
	case 6:
		system("cls");
		Save(L, n);
		goto chose;
	case 7:
		system("cls");
		L = Read(&n);
		goto chose;
	case 8:
		system("cls");
		printf("实验室负责人：车文超\n");
		printf("负责人学号：3121002783\n");
		printf("负责人班级：21计算机科学与技术2班\n");
		printf("负责人电话：13112690721\n");
		printf("\n如果对实验室有疑问，请通过电话联系负责人。\n");
		system("pause");
		goto chose;
	case 9:
		system("cls");
		LockChange();
		goto chose;
	case 10:
		return;
	default:
		system("cls");
		printf("参数错误，重新输入。\n");
		system("pause");
		goto chose;
	}
}

int main() {
	system("color f0");


welcome:
	system("cls");
	printf("程序：实验室设备信息管理系统\n");
	printf("作者：21计算机科学与技术2班车文超3121002783\n");
	printf("完成时间：2023年1月1日\n\n");
	printf("\
欢迎使用本程序\n\
本程序为实验室设备信息管理系统\n\n\
请选择你的身份进入系统\n\
1、管理员\n\
2、用户\n");
	int op;
	scanf_s("%d", &op);
	switch (op) {
	case 1:
		admin();
		goto welcome;
	case 2:
		user();
		goto welcome;
	default:
		printf("参数错误！\n");
		system("pause");
		goto welcome;
	}


chose:
	system("cls");



	return 0;
}