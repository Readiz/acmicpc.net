//#include <stdio.h>
//#define INF 987654321
//int n, T;
//int arr[100002];
//int pos[100002];
//int size;
//typedef struct Node {
//	int idx;
//	int value;
//}Node;
//Node heap[100001];
//void swap(Node *a, Node *b)
//{
//	Node temp = *a;
//	*a = *b;
//	*b = temp;
//	int tmp = pos[a->idx];
//	pos[a->idx] = pos[b->idx];
//	pos[b->idx] = tmp;
//}
//int get(int i)
//{
//	int ret = arr[i] > arr[i - 1] ? arr[i] - arr[i - 1] : 0;
//	ret += arr[i] > arr[i + 1] ? arr[i] - arr[i + 1] : 0;
//	return ret;
//}
//bool check(int a, int b)
//{
//	if (heap[a].value < heap[b].value)
//		return true;
//	else if (heap[a].value > heap[b].value)
//		return false;
//	else // 값이 같음
//	{
//		int p = get(heap[a].idx);
//		int q = get(heap[b].idx);
//		if (p < q)
//			return true;
//		else
//			return false;
//	}
//}
//void insert(int idx, int value)
//{
//	heap[++size].idx = idx;
//	heap[size].value = value;
//	pos[idx] = size;
//	int p = size;
//	while (p != 1)
//	{
//		if (heap[p].value > heap[p / 2].value)
//		{
//			swap(&heap[p], &heap[p / 2]);
//			p = p / 2;
//		}
//		else
//			return;
//	}
//}
//void adjust(int p)
//{
//	int q = p;
//	while (p < size)
//	{
//		if (2 * p + 1 <= size)
//		{
//			int idx = check(2 * p, 2 * p + 1);
//			int flag = check(p, 2 * p + idx);
//			if (flag)
//			{
//				swap(&heap[p], &heap[2 * p + idx]);
//				p = 2 * p + idx;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else if (2 * p <= size)
//		{
//			int flag = check(p, 2 * p);
//			if (flag)
//			{
//				swap(&heap[p], &heap[2 * p]);
//				p = 2 * p;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			break;
//		}
//	}
//	while (q != 1)
//	{
//		if (check(q / 2, q))
//		{
//			swap(&heap[q], &heap[q / 2]);
//			q = q / 2;
//		}
//		else
//		{
//			return;
//		}
//	}
//}
//void del()
//{
//	swap(&heap[1], &heap[size]);
//	size--;
//	adjust(1);
//}
//int main()
//{
//	int i;
//	scanf("%d %d", &n, &T);
//	for (i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	arr[0] = arr[n + 1] = INF;
//	for (i = 1; i <= n; i++)
//	{
//		if (arr[i] != 1)
//		{
//			int v = get(i);
//			insert(i, v);
//		}
//	}
//	for (i = 0; i < T; i++)
//	{
//		int idx = heap[1].idx;
//		arr[idx]--;
//		if (arr[idx] == 1)
//			del();
//		else
//		{
//			heap[1].value = get(idx);
//			adjust(1);
//			if (idx > 1)
//			{
//				heap[pos[idx - 1]].value = get(idx - 1);
//				adjust(idx - 1);
//			}
//			if (idx < n)
//			{
//				heap[pos[idx + 1]].value = get(idx + 1);
//				adjust(idx + 1);
//			}
//		}
//	}
//	for (i = 1; i <= n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}