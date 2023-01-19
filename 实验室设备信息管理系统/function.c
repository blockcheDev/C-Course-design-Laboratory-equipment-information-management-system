#include "function.h"

int Init(LinkList** L) {
	system("cls");
	printf("��������Ҫ¼����豸������\n");
	int n;
	scanf_s("%d", &n);
	*L = creat(n);

	printf("¼��ɹ���\n");
	system("pause");
	return n;
}

LinkList* Add(LinkList* L, int* n) {
	system("cls");
	for (LinkList* p = L;; p = p->next) {
		if (p->next == NULL) {
			LinkList* q = (LinkList*)malloc(sizeof(LinkList));
			printf("������Ҫ��ӵ��豸��Ϣ����ʽΪ����� ���� �ͺ� �۸� �������� ��;��\n");
			scanf_s("%d%s%s%d%s%s", &q->ID, q->name, 20, q->model, 20, &q->price, q->buy_date, 20, q->info, 255);
			q->next = NULL;
			p->next = q;
			(*n)++;

			printf("��ӳɹ���\n");
			printf("��ǰ����%d���豸��Ϣ\n", *n);
			system("pause");
			return L;
		}
	}
}

LinkList* Find_Name(LinkList* L, char* name) {
	system("cls");
	for (LinkList* p = L->next; p != NULL; p = p->next) {
		if (strcmp(p->name, name) == 0) {
			printf("��ǰʵ���豸Ϊ��\n\n");
			printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "���", "����", "�ͺ�", "�۸�", "��������", "��;");
			printf("%-15d%-15s%-15s%-15d%-15s%-15s\n", p->ID, p->name, p->model, p->price, p->buy_date, p->info);
			system("pause");
			return p;
		}
	}

	printf("û�и��豸��Ϣ\n");
	system("pause");
	return NULL;
}

LinkList* Find_ID(LinkList* L, int ID) {
	system("cls");
	for (LinkList* p = L->next; p != NULL; p = p->next) {
		if (p->ID == ID) {
			printf("��ǰʵ���豸Ϊ��\n\n");
			printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "���", "����", "�ͺ�", "�۸�", "��������", "��;");
			printf("%-15d%-15s%-15s%-15d%-15s%-15s\n", p->ID, p->name, p->model, p->price, p->buy_date, p->info);
			system("pause");
			return p;
		}
	}

	printf("û�и��豸��Ϣ\n");
	system("pause");
	return NULL;
}

LinkList* Change(LinkList* L, LinkList* e) {
	for (LinkList* p = L; p->next != NULL; p = p->next) {
		if (p->next == e) {
			LinkList* q = p->next;
			printf("�������޸ĺ���豸��Ϣ����ʽΪ����� ���� �ͺ� �۸� �������� ��;��\n");
			scanf_s("%d%s%s%d%s%s", &q->ID, q->name, 20, q->model, 20, &q->price, q->buy_date, 20, q->info, 255);
			printf("�޸ĳɹ���\n");
			system("pause");
			return L;
		}
	}

	printf("�޸�ʧ�ܡ�\n");
	system("pause");
	return L;
}

LinkList* Delete(LinkList* L, LinkList* e, int* n) {
	for (LinkList* p = L; p->next != NULL; p = p->next) {
		if (p->next == e) {
			LinkList* q = p->next;
			p->next = p->next->next;
			free(q);
			(*n)--;
			printf("ɾ���ɹ���\n");
			system("pause");
			return L;
		}
	}

	printf("ɾ��ʧ�ܡ�\n");
	system("pause");
	return L;
}

LinkList* Sort(LinkList* L, int n) {
	for (int i = 1; i < n; i++) {
		LinkList* p = L;
		for (int j = 0; j < n - i; j++) {
			if (p->next->ID > p->next->next->ID) {
				LinkList* t0 = p->next, * t1 = p->next->next, * t2 = p->next->next->next;
				p->next = t1;
				p->next->next = t0;
				p->next->next->next = t2;
			}
			p = p->next;
		}
	}
	system("cls");
	printf("������ɣ�\n");
	PrintAll(L, n);
	return L;
}

void PrintAll(LinkList* L, int n) {
	printf("��ǰ����%d��ʵ���豸��\n\n", n);
	printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "���", "����", "�ͺ�", "�۸�", "��������", "��;");

	LinkList* p = L->next;
	for (int i = 0; i < n; i++) {
		if (p == NULL) {
			printf("���ݴ���\n");
			system("pause");
			return;
		}
		printf("%-15d%-15s%-15s%-15d%-15s%-15s\n", p->ID, p->name, p->model, p->price, p->buy_date, p->info);
		p = p->next;
	}

	system("pause");
	return;
}

void Save(LinkList* L, int n) {
	printf("���������뱣����ļ�����\n");
	char name[20];
	scanf_s("%s", name, 20);
	char s[255];
	sprintf_s(s, sizeof(s), "%s.txt", name);
	errno_t err;
	FILE* f;
	err = fopen_s(&f, s, "w");
	if (err) {
		printf("�ļ���ʧ�ܡ�\n");
		return;
	}

	fprintf_s(f, "%d\n", n);
	LinkList* p = L->next;
	for (int i = 0; i < n; i++) {
		fprintf_s(f, "%-15d%-15s%-15s%-15d%-15s%-15s\n", p->ID, p->name, p->model, p->price, p->buy_date, p->info);
		p = p->next;
	}
	fclose(f);

	printf("�豸��Ϣ����ɹ���\n");
	system("pause");
}

LinkList* Read(int* n) {
	printf("�����������ȡ���ļ�����\n");
	char name[20];
	scanf_s("%s", name, 20);
	char s[255];
	sprintf_s(s, sizeof(s), "%s.txt", name);
	errno_t err;
	FILE* f;
	err = fopen_s(&f, s, "r");
	if (err) {
		printf("�ļ���ʧ�ܡ�\n");
		return;
	}

	fscanf_s(f, "%d", n);
	LinkList* node, * end;
	LinkList* L = (LinkList*)malloc(sizeof(LinkList));
	end = L;
	for (int i = 0; i < *n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		fscanf_s(f, "%d%s%s%d%s%s", &node->ID, node->name, 20, node->model, 20, &node->price, node->buy_date, 20, node->info, 255);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	fclose(f);

	printf("�豸��Ϣ��\"%s\"�ļ���ȡ�ɹ���\n", s);
	PrintAll(L, *n);
	return L;
}