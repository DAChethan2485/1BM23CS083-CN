#include <stdio.h>

#include <string.h>

int min(int x, int y)

{

    if (x < y)

        return x;

    else

        return y;

}

int main()

{

    int drop = 0, mini, nsec, cap, count = 0, i, inp[25], process;

    printf("Enter the bucket size:\n");

    scanf("%d", &cap);

    printf("Enter the processing rate \n");

    scanf("%d", &process);

    printf("Enter the number of seconds you want to stimulate \n");

    scanf("%d", &nsec);

    for (i = 0; i < nsec; i++)

    {

        printf("Enter the size of the packet entering at %d sec \n", i + 1);

        scanf("%d", &inp[i]);

    }

    printf("\nSecond | Packet received | Packet sent | Packet left | Dropped\n");

    printf("---------------------------------------------------------------\n");

    // First phase: process incoming packets for nsec seconds

    for (i = 0; i < nsec; i++)

    {

        count += inp[i];

        if (count > cap)

        {

            drop = count - cap;

            count = cap;

        }

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, inp[i], min(count, process), count - min(count, process), drop);

        drop = 0;

    }

    // Second phase: continue processing remaining packets until empty

    for (; count != 0; i++)

    {

        if (count > cap)

        {

            drop = count - cap;

            count = cap;

        }

        printf("%d\t0\t\t%d\t\t%d\t\t%d\n", i + 1, min(count, process), count - min(count, process), drop);

        count -= min(count, process);

        drop = 0;

    }

    return 0;

}


