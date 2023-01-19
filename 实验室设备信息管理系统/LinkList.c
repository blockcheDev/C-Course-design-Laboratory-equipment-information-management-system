#include "LinkList.h"

LinkList* creat(int n) {
	LinkList* node, * end;
	LinkList* L = (LinkList*)malloc(sizeof(LinkList));
	end = L;
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		printf("请输入第%d个设备信息：格式为（编号 名称 型号 价格 购买日期 用途）\n", i + 1);
		scanf_s("%d%s%s%d%s%s", &node->ID, node->name, 20, node->model, 20, &node->price, node->buy_date, 20, node->info, 255);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return L;
}

