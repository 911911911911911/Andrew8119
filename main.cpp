#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

enum Amplua
{
Defender,
Midfielder,
Goalkeeper,
Forward
};

struct Football
{char surname[50];
enum Amplua position;
int age;
int count_of_games;
int count_of_goals;
};



void The_best(struct Football* players, int number)
{
int j = -1;
int max = 0;

for (int i = 0; i < number; ++i)
{
if ((players[i].position == Forward) && (players[i].count_of_goals > max))
{
j = i;
max = players[i].count_of_goals;
}
}

if (j != -1)
{
printf("Найкращий бомбардир:\n");
printf("Прізвище: %s\n", players[j].surname);
printf("Амплуа: Forward\n");
printf("Вік: %d\n", players[j].age);
printf("Кількість голів: %d\n", players[j].count_of_goals);
}
else
{
printf("Немає бомбардирів!\n");
}
}



void Five_games(struct Football* players, int number) {
printf("Гравці, які зіграли менше 5 ігор:\n");
for (int i = 0; i < number; ++i)
{
if (players[i].count_of_games < 5)
{
    printf("Прізвище: %s\n", players[i].surname);
    printf("Амплуа: ");
    switch (players[i].position)
    {
        case Goalkeeper:
            printf("Goalkeeper\n");
            break;
        case Defender:
            printf("Defender\n");
            break;
        case Midfielder:
            printf("Midfielder\n");
            break;
        case Forward:
            printf("Forward\n");
            break;
    }
            printf("Вік: %d\n", players[i].age);
            printf("Зіграні ігри: %d\n", players[i].count_of_games);
            printf("Кількість голів: %d\n", players[i].count_of_goals);
            printf("\n");
}
}
}




int main()
{int number;
printf("Введіть кількість гравців: ");
scanf("%d", &number);
getchar();

struct Football* players = (struct Football*)malloc(number * sizeof(struct Football));

for (int i = 0; i < number; i++)
{
printf("Гравець №%d:\n", i + 1);
        
       
printf("Прізвище: ");
fgets(players[i].surname, sizeof(players[i].surname), stdin);
players[i].surname[strlen(players[i].surname) - 1] = '\0';

     
printf("Амплуа (0 - Goalkeeper, 1 - Defender, 2 - Midfielder, 3 - Forward): ");
scanf("%d", (int*)&players[i].position);
getchar();

     
printf("Вік: ");
scanf("%d", &players[i].age);
getchar();

       
printf("Кількість ігор: ");
scanf("%d", &players[i].count_of_games);
getchar();

        
printf("Кількість голів: ");
scanf("%d", &players[i].count_of_goals);
getchar();
}

The_best(players, number);
Five_games(players, number);

free(players);

return 0;
}
