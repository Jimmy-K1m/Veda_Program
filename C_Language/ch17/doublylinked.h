#pragma once
struct link {
	int id;
	char bookname[30];

	struct linked* before;
	struct linked* next;
}; // 헤더파일에는 가급적 struct 변수 선언 안 됨.

void Enter(struct link* Head, struct link* Tail);
void Print(struct link* Head, struct link* Tail);
void Search(struct link* Head, struct link* Tail);
void Delete(struct link* Head, struct link* Tail);
void Destroy(struct link* Head, struct link* Tail);

//void Enter(struct link* book_ptr);

// prev는 이전 노드의 주소가