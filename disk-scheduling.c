#include <stdio.h>
#include <stdlib.h>

int a[20], n, start;

void sort()
{
    int i, j, t;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void sstf()
{
    int i, j, head = start, total = 0;
    int visited[20] = {0}, min, pos = -1;

    printf("\nSSTF: %d", head);

    for(i = 0; i < n; i++)
    {
        min = 99999;
        pos = -1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && abs(head - a[j]) < min)
            {
                min = abs(head - a[j]);
                pos = j;
            }
        }

        visited[pos] = 1;
        total += abs(head - a[pos]);
        head = a[pos];

        printf(" -> %d", head);
    }

    printf("\nTotal Movement: %d\n", total);
}

void scan()
{
    int i, head = start, total = 0;

    printf("\nSCAN: %d", head);

    for(i = 0; i < n; i++)
    {
        if(a[i] >= start)
        {
            total += abs(head - a[i]);
            head = a[i];
            printf(" -> %d", head);
        }
    }

    total += abs(head - 199);
    head = 199;
    printf(" -> %d", head);

    for(i = n - 1; i >= 0; i--)
    {
        if(a[i] < start)
        {
            total += abs(head - a[i]);
            head = a[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Movement: %d\n", total);
}

void clook()
{
    int i, head = start, total = 0;

    printf("\nC-LOOK: %d", head);

    for(i = 0; i < n; i++)
    {
        if(a[i] >= start)
        {
            total += abs(head - a[i]);
            head = a[i];
            printf(" -> %d", head);
        }
    }

    for(i = 0; i < n; i++)
    {
        if(a[i] < start)
        {
            total += abs(head - a[i]);
            head = a[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Movement = %d\n", total);
}

int main()
{
    printf("Enter number of requests: ");

    if(scanf("%d", &n) != 1 || n < 1 || n > 20)
        return 1;

    printf("Enter requests: ");

    for(int i = 0; i < n; i++)
    {
        if(scanf("%d", &a[i]) != 1 || a[i] < 0 || a[i] > 199)
            return 1;
    }

    printf("Enter Initial head position: ");

    if(scanf("%d", &start) != 1 || start < 0 || start > 199)
        return 1;

    sstf();

    sort();

    scan();
    clook();

    return 0;
}