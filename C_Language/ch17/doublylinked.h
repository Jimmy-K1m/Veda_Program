#pragma once
struct link {
	int id;
	char bookname[30];

	struct linked* before;
	struct linked* next;
}; // ������Ͽ��� ������ struct ���� ���� �� ��.

void Enter(struct link* Head, struct link* Tail);
void Print(struct link* Head, struct link* Tail);
void Search(struct link* Head, struct link* Tail);
void Delete(struct link* Head, struct link* Tail);
void Destroy(struct link* Head, struct link* Tail);

//void Enter(struct link* book_ptr);

// prev�� ���� ����� �ּҰ�