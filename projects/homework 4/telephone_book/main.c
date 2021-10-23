#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct
{
    char name[50];
    char phone[30];
} PhoneBookEntry;

int main()
{
    PhoneBookEntry entry[SIZE];
    int pointer = 0;
    FILE* phoneBook = fopen("phoneBook.txt", "r");
    if (phoneBook == NULL)
    {
        printf("Файл не найден.");
        return -1;
    }
    while (!feof(phoneBook))
    {
        fscanf(phoneBook, "%[^\n]%*c", &entry[pointer].name);
        fscanf(phoneBook, "%[^\n]%*c", &entry[pointer].phone);
        pointer++;
    }
    fclose(phoneBook);
    printf("0 - выйти");
    printf("\n1 - добавить запись(имя и телефон)");
    printf("\n2 - распечатать все имеющиеся записи");
    printf("\n3 - найти телефон по имени");
    printf("\n4 - найти имя по телефону");
    printf("\n5 - сохранить текущие данные в файл");
    while (pointer != SIZE)
    {
        printf("\nВведите команду: ");
        int input = 0;
        scanf_s("%d", &input);
        while (scanf_s("%*c") == 1);
        switch (input)
        {
        case 0:
            fclose(phoneBook);
            printf("Вы вышли из программы.");
            return -1;
            break;
        case 1:
            printf("Пожалуйста, введите имя: ");
            gets(&entry[pointer].name);
            printf("Пожалуйста, введите номер телефона: ");
            gets(&entry[pointer].phone);
            pointer++;
            break;
        case 2:
            for (int i = 0; i < pointer; i++)
            {
                printf("\n%s – %s", entry[i].name, entry[i].phone);
            }
            break;
        case 3:
            printf("Пожалуйста, введите имя: ");
            char nameSearch[50] = { 0 };
            gets(&nameSearch);
            for (int i = 0; i < pointer; i++)
            {
                if (strcmp(entry[i].name, nameSearch) == 0)
                {
                    printf("%s", entry[i].phone);
                    break;
                }
            }
            break;
        case 4:
            printf("Пожалуйста, введите номер телефона: ");
            char phoneSearch[30] = { 0 };
            gets(&phoneSearch);
            for (int i = 0; i < pointer; i++)
            {
                if (strcmp(entry[i].phone, phoneSearch) == 0)
                {
                    printf("%s", entry[i].name);
                    break;
                }
            }
            break;
        case 5:;
            FILE* phoneBookSave = fopen("phoneBook.txt", "w");
            if (phoneBookSave == NULL)
            {
                printf("Файл не найден.");
                return -1;
            }
            for (int i = 0; i < pointer; i++)
            {
                fprintf(phoneBookSave, "%s\n", &entry[i].name);
                fprintf(phoneBookSave, "%s\n", &entry[i].phone);
            }
            fclose(phoneBookSave);
            break;
        default:
            printf("\nНеправильный ввод команды.\n");
            break;
        }
    }
}