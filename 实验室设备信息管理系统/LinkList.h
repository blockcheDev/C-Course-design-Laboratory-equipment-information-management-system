#include "base.h"

typedef struct shebei {
	int ID;
	char name[20], model[20], buy_date[20];
	int price;
	char info[255];
	struct shebei* next;
}LinkList;

LinkList* creat(int n);