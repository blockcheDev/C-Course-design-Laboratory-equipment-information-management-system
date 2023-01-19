#include "Lock.h"

int Lock() {
	char id[20], pass[20];
	printf("请输入账号：\n");
	scanf_s("%s", id, 20);
	printf("请输入密码：\n");
	scanf_s("%s", pass, 20);

	errno_t err;
	FILE* f;
	err = fopen_s(&f, "AdminInfo.txt", "r");
	if (err) {
		printf("文件打开失败。\n");
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
	printf("请输入原始账号密码：\n");
	if (!Lock()) {
		printf("\n账号或密码错误\n");
		system("pause");
		return;
	}
	
	printf("请输入你要修改成的账号密码：\n");
	char id[20], pass[20];
	printf("请输入账号：\n");
	scanf_s("%s", id, 20);
	printf("请输入密码：\n");
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
		printf("文件打开失败。\n");
		return;
	}
	fprintf(f, "%s\n%s\n", id, pass);
	fclose(f);
	
	printf("账号密码修改成功！\n");
	system("pause");
	return;
}