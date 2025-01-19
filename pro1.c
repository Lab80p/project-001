#include <stdio.h>
#define MAX_CURRENCIES 25

char *currencyCodes[MAX_CURRENCIES] =
{
    "USD", "EUR", "JPY", "GBP", "CHF", "CAD", "AUD", "BDT", "PKR", "CNY",
    "HKD", "SGD", "KRW", "NZD", "INR", "MXN", "RUB", "ZAR", "BRL", "TRY",
    "THB", "IDR", "NOK", "SEK", "DKK"
};

float exchangeRates[MAX_CURRENCIES] =
{
    1.0, 0.97, 156.15, 0.82, 0.91, 1.45, 1.61, 121.50, 278.67, 7.32, 7.79, 1.37,
    1458.38, 1.79, 86.58, 20.75, 102.46, 18.75, 6.08, 35.57, 34.51, 16380.65, 11.42, 11.17,
    7.25
};

char *currencyNames[MAX_CURRENCIES] =
{
    "US Dollar", "Euro", "Japanese Yen", "British Pound Sterling", "Swiss Franc", "Canadian Dollar",
    "Australian Dollar", "Bangladeshi Taka", "Pakistani Rupee", "Chinese Yuan Renminbi",
    "Hong Kong Dollar", "Singapore Dollar", "South Korean Won", "New Zealand Dollar", "Indian Rupee",
    "Mexican Peso", "Russian Ruble", "South African Rand", "Brazilian Real", "Turkish Lira",
    "Thai Baht", "Indonesian Rupiah", "Norwegian Krone", "Swedish Krona", "Danish Krone"
};

float convert(float amount, float fromRate, float toRate)
{
    return (amount / fromRate) * toRate;
}

int main()
{
    int choiceFrom, choiceTo;
    float amount, convertedAmount;

    while (1)
    {
        printf("\nWelcome to BYTE BUILDERS Currency Exchange Program\n");

        printf("\nAvailable Currencies:\n");
        for (int i = 0; i < MAX_CURRENCIES; i++)
        {
            printf("%d. %s (%s)\n", i + 1, currencyNames[i], currencyCodes[i]);
        }
        printf("%d. Exit\n", MAX_CURRENCIES + 1);

        printf("\nSelect the currency to convert FROM: ");
        scanf("%d", &choiceFrom);

        if (choiceFrom == MAX_CURRENCIES + 1)
        {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choiceFrom < 1 || choiceFrom > MAX_CURRENCIES)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Select the currency to convert TO: ");
        scanf("%d", &choiceTo);

        if (choiceTo == MAX_CURRENCIES + 1)
        {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choiceTo < 1 || choiceTo > MAX_CURRENCIES || choiceFrom == choiceTo)
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter the amount to convert: ");
        scanf("%f", &amount);

        if (amount < 0)
        {
            printf("Invalid amount. Please enter a positive number.\n");
            continue;
        }

        convertedAmount = convert(amount, exchangeRates[choiceFrom - 1], exchangeRates[choiceTo - 1]);

        printf("\n%.2f %s is equivalent to %.2f %s\n",
               amount, currencyCodes[choiceFrom - 1],
               convertedAmount, currencyCodes[choiceTo - 1]);
    }

    return 0;
}
