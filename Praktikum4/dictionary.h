#define SIZE 5

int insert(int a);
int delete(int a);
int member(int a);
void visit_all(void (*work)(int value, int flag));
int get_size();