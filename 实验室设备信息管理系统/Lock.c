#include "Lock.h"

int Lock() {
	char id[20], pass[20];
	printf("�������˺ţ�\n");
	scanf_s("%s", id, 20);
	printf("���������룺\n");
	scanf_s("%s", pass, 20);

	errno_t err;
	FILE* f;
	err = fopen_s(&f, "AdminInfo.txt", "r");
	if (err) {
		printf("�ļ���ʧ�ܡ�\n");
		return;
	}
	char a_id[20], a_pass[20];
	fscanf_s(f, "%s", a_id, 20);
	fscanf_s(f, "%s", a_pass, 20);
	fclose(f);
	int d0 = 53, d1 = 78;
	for (int i = 0; a_id[i] != '\0'; i++) {
		a_id[i] = ((a_id[i] - 33 - d0) % 94 + 94) % 94 + 33;
		d0 = (d0 * 2 - 1) % 94;
	}
	for (int i = 0; a_pass[i] != '\0'; i++) {
		a_pass[i] = ((a_pass[i] - 33 - d1) % 94 + 94) % 94 + 33;
		d1 = (d1 * 2 - 1) % 94;
	}

	if (strcmp(id, a_id) != 0 || strcmp(pass, a_pass) != 0) {
		return 0;
	}
	return 1;
}

void LockChange() {
	printf("������ԭʼ�˺����룺\n");
	if (!Lock()) {
		printf("\n�˺Ż��������\n");
		system("pause");
		return;
	}
	
	printf("��������Ҫ�޸ĳɵ��˺����룺\n");
	char id[20], pass[20];
	printf("�������˺ţ�\n");
	scanf_s("%s", id, 20);
	printf("���������룺\n");
	scanf_s("%s", pass, 20);

	int d0 = 53, d1 = 78;
	for (int i = 0; id[i] != '\0'; i++) {
		id[i] = (id[i] - 33 + d0) % 94 + 33;
		d0 = (d0 * 2 - 1) % 94;
	}
	for (int i = 0; pass[i] != '\0'; i++) {
		pass[i] = (pass[i] - 33 + d1) % 94 + 33;
		d1 = (d1 * 2 - 1) % 94;
	}

	errno_t err;
	FILE* f;
	err = fopen_s(&f, "AdminInfo.txt", "w");
	if (err) {
		printf("�ļ���ʧ�ܡ�\n");
		return;
	}
	fprintf(f, "%s\n%s\n", id, pass);
	fclose(f);
	
	printf("�˺������޸ĳɹ���\n");
	system("pause");
	return;
}