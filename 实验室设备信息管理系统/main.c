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
|       ��ѡ����Ҫ���еĲ���                |\n\
|       1��ʵ���豸��Ϣ��ѯ                 |\n\
|       2��ʵ���豸��Ϣ���������           |\n\
|       3��ʵ���豸��Ϣ����                 |\n\
|       4����ȡ�豸��Ϣ                     |\n\
|       5���鿴ʵ���Ҹ�������Ϣ             |\n\
|       6�����ػ�ӭ����                     |\n\
---------------------------------------------\n\
");

	int op;
	scanf_s("%d", &op);
	switch (op) {

	case 1:
		system("cls");
		printf("\
------------------------------------\n\
|       ��ѡ����Ҫ���еĲ���       |\n\
|       1�����������Ʋ�ѯ          |\n\
|       2�������ı�Ų�ѯ          |\n\
------------------------------------\n\
");
		LinkList* e = NULL;
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			printf("�������������ƣ�\n");
			char name[20];
			scanf_s("%s", name, 20);
			e = Find_Name(L, name);
			goto chose;
		case 2:
			printf("���������ı�ţ�\n");
			int ID;
			scanf_s("%d", &ID);
			e = Find_ID(L, ID);
			goto chose;
		default:
			system("cls");
			printf("���������������롣\n");
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
		printf("ʵ���Ҹ����ˣ����ĳ�\n");
		printf("�����˰༶��21�������ѧ�뼼��2��\n");
		printf("�����˵绰��13112690721\n");
		printf("\n�����ʵ���������ʣ���ͨ���绰��ϵ�����ˡ�\n");
		system("pause");
		goto chose;
	case 6:
		return;
	default:
		system("cls");
		printf("���������������롣\n");
		system("pause");
		goto chose;
	}
}

void admin() {
	system("cls");

	if (!Lock()) {
		printf("\n�˺Ż��������\n");
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
|       ��ѡ����Ҫ���еĲ���                |\n\
|       1��ʵ���豸��Ϣ¼��                 |\n\
|       2��ʵ���豸��Ϣ���                 |\n\
|       3��ʵ���豸��Ϣ��ѯ���޸ġ�ɾ����   |\n\
|       4��ʵ���豸��Ϣ���������           |\n\
|       5��ʵ���豸��Ϣ����                 |\n\
|       6�������豸��Ϣ                     |\n\
|       7����ȡ�豸��Ϣ                     |\n\
|       8���鿴ʵ���Ҹ�������Ϣ             |\n\
|       9���޸Ĺ���Ա�˺�����               |\n\
|       10�����ػ�ӭ����                    |\n\
---------------------------------------------\n\
");
	
	//12 ��ͷ�ι� 10ml 5 2023.1.1 ת��Һ��
	//1 ��ͷ�ι� 15ml 7 2023.1.1 ת��Һ��

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
|       ��ѡ����Ҫ���еĲ���       |\n\
|       1�����������Ʋ�ѯ          |\n\
|       2�������ı�Ų�ѯ          |\n\
------------------------------------\n\
");
		LinkList* e = NULL;
		int op1;
		scanf_s("%d", &op1);
		switch (op1) {
		case 1:
			printf("�������������ƣ�\n");
			char name[20];
			scanf_s("%s", name, 20);
			e = Find_Name(L, name);
			if (e == NULL) goto chose;
			goto change;
		case 2:
			printf("���������ı�ţ�\n");
			int ID;
			scanf_s("%d", &ID);
			e = Find_ID(L, ID);
			if (e == NULL) goto chose;
			goto change;
		default:
			system("cls");
			printf("���������������롣\n");
			system("pause");
			goto chose;
		}
change:
		printf("\
------------------------------------\n\
|       ��ѡ����Ҫ���еĲ���       |\n\
|       1��������Ϣ                |\n\
|       2��ɾ���豸                |\n\
|       3�����ز˵�                |\n\
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
		printf("ʵ���Ҹ����ˣ����ĳ�\n");
		printf("������ѧ�ţ�3121002783\n");
		printf("�����˰༶��21�������ѧ�뼼��2��\n");
		printf("�����˵绰��13112690721\n");
		printf("\n�����ʵ���������ʣ���ͨ���绰��ϵ�����ˡ�\n");
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
		printf("���������������롣\n");
		system("pause");
		goto chose;
	}
}

int main() {
	system("color f0");


welcome:
	system("cls");
	printf("����ʵ�����豸��Ϣ����ϵͳ\n");
	printf("���ߣ�21�������ѧ�뼼��2�೵�ĳ�3121002783\n");
	printf("���ʱ�䣺2023��1��1��\n\n");
	printf("\
��ӭʹ�ñ�����\n\
������Ϊʵ�����豸��Ϣ����ϵͳ\n\n\
��ѡ�������ݽ���ϵͳ\n\
1������Ա\n\
2���û�\n");
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
		printf("��������\n");
		system("pause");
		goto welcome;
	}


chose:
	system("cls");



	return 0;
}