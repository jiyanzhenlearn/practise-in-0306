void swap(char* a, char* b, int c)
{
	int i = 0;
	for (i = 0; i < c; i++)
	{
		char temp = *a;
		*a = *b;
		*b = temp;
		a++;
		b++;
	}
}

void bubble_sort(void* base, int num, int width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
struct stu
{
	char name[10];
	int age;
};
int cmp_s(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
int cmp_m(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
int main()
{
	int arr[] = { 5,7,6,8,9,4,3,2,1 };
	struct stu con[3] = { {"zhangsan",20 },{"lisi",25},{"wangwu",22} };
	int sz = sizeof(con) / sizeof(con[0]);
	bubble_sort(con, sz, sizeof(con[0]), cmp_s);
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_m);

	return 0;
}