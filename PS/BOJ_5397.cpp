#include <stdio.h>

struct List {
	char t;
	List *prev = nullptr;
	List *next = nullptr;
};

void Write(List**, List**, char);
void MoveLeft(List**, List**);
void MoveRight(List**, List**);
void Backspace(List**, List**);

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, i;
	char t;
	scanf("%d", &n);
	getchar();
	for (i = 1; i <= n; i++) {
	
		List* head = nullptr;
		List* cursor = nullptr;

		while (1) {
			scanf("%c", &t);

			if (t == '\n') break;

			if (t == '<') {
				MoveLeft(&head, &cursor);
			}
			else if (t == '>') {
				MoveRight(&head, &cursor);
			}
			else if (t == '-') {
				Backspace(&head, &cursor);
			}
			else {
				Write(&head, &cursor, t);
			}
		}

		List* iter;
		for (iter = head; iter != nullptr; iter = iter->next) {
			printf("%c", iter->t);
		}
		printf("\n");
	}

	return 0;
}

void Write(List** h, List** c, char t) {
	
	List *temp = new List;
	temp->t = t;

	if (*h == nullptr) {	//head==NULL, cursor==NULL
		*h = temp;
		*c = temp;
	}
	else {	
		if (*c == nullptr) {	//head!=NULL, cursor==NULL
			(*h)->prev = temp;
			temp->next = *h;
			(*c) = temp;
			(*h) = temp;
		}
		else {	//head!=NULL, cursor!=NULL
			if ((*c)->next == nullptr) {	//cursor가 맨끝에있을때
				temp->prev = (*c);
				(*c)->next = temp;
				(*c) = temp;
			}
			else {		//cursor가 문자 사이에 있을때
				temp->next = (*c)->next;
				temp->prev = (*c);
				(*c)->next->prev = temp;
				(*c)->next = temp;
				(*c) = temp;
			}
		}
	}
}

void MoveLeft(List** h, List** c) {		//'<'
	if (*c == nullptr) return;
	else {
		*c = (*c)->prev;
	}
}

void MoveRight(List** h, List** c) {	//'>'
	if (*h == nullptr) return;	//head==NULL, cursor==NULL
	else if (*c == nullptr) {	//head!=NULL, cursor==NULL
		*c = *h;
	}
	else {	//head!=NULL,cursor!=NULL
		if ((*c)->next == nullptr) return;	//이미 curosr 맨끝에있는경우
		else {
			*c = (*c)->next;
		}
	}
}

void Backspace(List** h, List** c) {	//'-'
	if (*c == nullptr) return;	//head상관없이 cursor==NULL -> 지울거없음
	else {	//cursor!=NULL -> 지울거있음
		List* del = new List;	//delete용
		del = *c;
		if ((*c)->prev == nullptr) {	//하나 지우면 cursor가 맨앞일때(head==cursor)
			*h = (*c)->next;
			*c = (*c)->prev;
			delete del;
		}
		else {	//head!=cursor
			if ((*c)->next == nullptr) {	//현재 커서가 맨끝에있을때
				(*c)->prev->next = nullptr;
				*c = (*c)->prev;
				delete del;
			}
			else {	//커서가 문자열 중간에 있을때
				(*c)->prev->next = (*c)->next;
				(*c)->next->prev = (*c)->prev;
				*c = (*c)->prev;
				delete del;
			}
		}
	}
}