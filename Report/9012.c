#include <stdio.h>

char stack[50];
int top = 0;

int isVPS(char *);

void push(char);
char pop();
int isEmpty();

int main() {

	int t;
	char str[51];

	int i;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%s", str);

		if (isVPS(str)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;

}

int isVPS(char *str) {

	int result = 1;

	int i;

	for (i = 0; str[i]; i++) {

		if (str[i] == '(') {
			push(str[i]);
		}
		else {

			if (isEmpty()) {
				result = 0;
				break;
			}
			else {
				pop();
			}

		}

	}

	if (!isEmpty()) result = 0;

	while (!isEmpty()) {
		pop();
	}

	return result;

}

void push(char c) {
	stack[top++] = c;
}

char pop() {
	return stack[--top];
}

int isEmpty() {
	return top == 0;
}
