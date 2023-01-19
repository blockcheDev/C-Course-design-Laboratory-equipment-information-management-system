#include "LinkList.h"

int Init(LinkList** L);
LinkList* Add(LinkList* L, int* n);
LinkList* Find_Name(LinkList* L, char* name);
LinkList* Find_ID(LinkList* L, int ID);
LinkList* Change(LinkList* L, LinkList* e);
LinkList* Delete(LinkList* L, LinkList* e, int* n);
LinkList* Sort(LinkList* L, int n);
void PrintAll(LinkList* L, int n);
void Save(LinkList* L, int n);
LinkList* Read(int* n);
