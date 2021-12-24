//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//struct Timeline {
//	int year;
//	int day;
//	int second;
//	int sum;
//	struct Timeline* next;
//};
//struct Timeline subtr(struct Timeline a, struct Timeline b)
//{
//	struct Timeline c;
//	int d = 0;;
//	c.second = a.second - b.second;
//	if (c.second < 0)
//	{
//		c.second += 86400;
//		d = 1;
//	}
//	c.day = a.day - b.day - d;
//	d = 0;
//	if (c.day < 0)
//	{
//		c.day += 365;
//		d = 1;
//	}
//	c.year = a.year - b.year - d;
//	return c;
//}
//int comp(struct Timeline a)
//{
//	if (a.year < 0)
//	{
//		return -1;
//	}
//	if (a.year == 0 && a.day == 0 && a.second == 0)
//	{
//		return 0;
//	}
//	return 1;
//}
//int lala(char month[])
//{
//	if (strcmp(month, "Jan") == 0)
//	{
//		return 0;
//	}
//	if (strcmp(month, "Feb") == 0)
//	{
//		return 31;
//	}
//	if (strcmp(month, "Mar") == 0)
//	{
//		return 59;
//	}
//	if (strcmp(month, "Apr") == 0)
//	{
//		return 90;
//	}
//	if (strcmp(month, "May") == 0)
//	{
//		return 120;
//	}
//	if (strcmp(month, "Jun") == 0)
//	{
//		return 151;
//	}
//	if (strcmp(month, "Jul") == 0)
//	{
//		return 181;
//	}
//	if (strcmp(month, "Aug") == 0)
//	{
//		return 212;
//	}
//	if (strcmp(month, "Sep") == 0)
//	{
//		return 243;
//	}
//	if (strcmp(month, "Oct") == 0)
//	{
//		return 273;
//	}
//	if (strcmp(month, "Nov") == 0)
//	{
//		return 304;
//	}
//	if (strcmp(month, "Dec") == 0)
//	{
//		return 334;
//	}
//}
//int main(){
//	FILE* in = fopen("access_log_Jul95.txt", "r");
//	//FILE* in = fopen("1.txt", "r");
//	FILE* out = fopen("0.txt", "w"); 
//	int m = 0, max = 0, sum = 0, var;
//	struct Timeline* tail = NULL, * head = NULL, par = {0, 0, 0}, output[2];
//	scanf("%d", &var);
//	par.second = var % 86400;
//	par.day = var / 86400 % 365;
//	par.year = var / 86400 / 365;
//	int mu[] = { 0, 0, 60 * 60, 60, 1 };
//	char str[300];
//	while (fgets(str, 300, in) != NULL) 
//	{
//		int i = 0, second = 0, pr = 0, num = 0, k = -1, j = 0, ind = 0, year = 0, day = 0;
//		char month[5];
//		while (str[i] != '\0')
//		{
//			if (str[i] == ' ')
//			{
//				pr++;
//			}
//			if (pr == 3)
//			{
//				if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
//				{
//					month[j] = str[i];
//					j++;
//				}
//				if (str[i] >= '0' && str[i] <= '9') 
//				{
//					if (str[i - 1] < '0' || str[i - 1] > '9')
//					{
//						k++;
//					}
//					num = num * 10 + str[i] - 48;
//				}
//				else
//				{
//					if (k == 0 && day == 0)
//					{
//						day = num;
//					}
//					if (k == 1 && year == 0)
//					{
//						year = num;
//					}
//					second += num * mu[k];
//					num = 0;
//				}
//			}
//			if (str[i] == '\"')
//			{
//				ind = i;
//			}
//			i++;
//		}
//		if (str[ind + 2] == '5')
//		{
//			sum = sum + 1;
//			fprintf(out, "%s", str);
//		}
//		month[j] = '\0';
//		day += lala(month);
//		second += num;
//		struct Timeline* time = (struct Timeline*)malloc(sizeof(struct Timeline));
//		time->year = year;
//		time->day = day;
//		time->second = second;
//		time->sum = 1;
//		time->next = NULL;
//		if (tail != NULL && comp(subtr(*time, *tail)) == 0)
//		{
//			tail->sum += 1;
//			free(time);
//		}
//		else
//		{
//			if (tail == NULL)
//			{
//				tail = time;
//				head = tail;
//			}
//			else
//			{
//				tail->next = time;
//				tail = time;
//			}
//		}
//		m++;
//		while (head!=tail)
//		{
//			if (comp(subtr(subtr(*tail, *head), par)) > 0)
//			{
//				m -= head->sum;
//				time = head->next;
//				free(head);
//				head = time;
//			}
//			else
//			{
//				break;
//			}
//		}
//		if (max < m)
//		{
//			max = m;
//			output[0] = *head;
//			output[1] = *tail;
//		}
//	}
//	fprintf(out, "\n%d", sum);
//	printf("\n%d\n", max);
//	printf("%d/%d/%d -- %d/%d/%d", output[0].year, output[0].day, output[0].second, output[1].year, output[1].day, output[1].second);
//	return 0;
//}