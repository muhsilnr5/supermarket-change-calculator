#include <stdio.h>
#include <string.h>
const int quarters = 25;
const int dimes = 10;
const int nickels = 5;
const int pennies = 1;
const int MAX = 4; // total types of  coins
const int coin[MAX] = {quarters, dimes, nickels, pennies};
int coin_count(int coin_type, int change);
struct transaction
{
    int money;
    int cost;
};

int main(void)
{
    struct transaction bill;
    // prompting user for cost and money paid
    printf("Cost: ");
    scanf("%i", &bill.cost);
    printf("Paid Amount ");
    scanf("%i", &bill.money);
    // Check weather the value is valid
    if (bill.cost < 1 || bill.money < 1)
    {
        printf("Error\n");
        return 1;
    }
    // check weather paid money is enough
    int change = bill.money - bill.cost;
    if (change < 0)
    {
        printf("Not enough cash\n");
        return 2;
    }
    printf("Change: %i\n",change);
    // intilising the count array
    int count_coin[MAX];
    // count number of quaters
    for (int i = 0; i < MAX; i++)
    {
        count_coin[i] = coin_count(coin[i], change);
        change -= coin[i] * count_coin[i];
    }
    printf("Quarters: %i\nDimes: %i\nNickels: %i\nPennies %i\n", count_coin[0], count_coin[1],
           count_coin[2], count_coin[3]);
    return 0;
}
// function for counting coin
int coin_count(int coin_type, int change)
{
    int count = 0;
    while (change >= coin_type)
    {
        change -= coin_type;
        count++;
    }
    return count;
}
