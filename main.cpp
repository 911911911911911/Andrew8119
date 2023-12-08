#include <iostream>

enum Position {
    Goalkeeper,
    Defender,
    Midfielder,
    Forward
};

struct FootballPlayer {
    std::string lastName;
    Position position;
    int age;
    int gamesPlayed;
    int goalsScored;
    FootballPlayer* next;
};

// Функція для створення списку за даними з клавіатури і повернення вказівника на голову списку
FootballPlayer* createListFromInput() {
    int n;
    FootballPlayer* head = nullptr;
    FootballPlayer* newNode;

    std::cout << "Enter the number of football players: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        newNode = new FootballPlayer;
        std::cout << "Enter the last name of player " << i + 1 << ": ";
        std::cin >> newNode->lastName;
        std::cout << "Enter the position of player " << i + 1 << " (0 - Goalkeeper, 1 - Defender, 2 - Midfielder, 3 - Forward): ";
        int position;
        std::cin >> position;
        newNode->position = static_cast<Position>(position);
        std::cout << "Enter the age of player " << i + 1 << ": ";
        std::cin >> newNode->age;
        std::cout << "Enter the number of games played by player " << i + 1 << ": ";
        std::cin >> newNode->gamesPlayed;
        std::cout << "Enter the number of goals scored by player " << i + 1 << ": ";
        std::cin >> newNode->goalsScored;

        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Функція для формування списку за допомогою параметру (не повертає значення)
void formListWithParameter(FootballPlayer*& head) {
    int n;
    FootballPlayer* newNode;

    std::cout << "Enter the number of football players: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        newNode = new FootballPlayer;
        std::cout << "Enter the last name of player " << i + 1 << ": ";
        std::cin >> newNode->lastName;
        std::cout << "Enter the position of player " << i + 1 << " (0 - Goalkeeper, 1 - Defender, 2 - Midfielder, 3 - Forward): ";
        int position;
        std::cin >> position;
        newNode->position = static_cast<Position>(position);
        std::cout << "Enter the age of player " << i + 1 << ": ";
        std::cin >> newNode->age;
        std::cout << "Enter the number of games played by player " << i + 1 << ": ";
        std::cin >> newNode->gamesPlayed;
        std::cout << "Enter the number of goals scored by player " << i + 1 << ": ";
        std::cin >> newNode->goalsScored;

        newNode->next = head;
        head = newNode;
    }
}

// Функція для виведення елементів списку
void displayFootballPlayers(FootballPlayer* head) {
    FootballPlayer* current = head;
    while (current != nullptr) {
        std::cout << "Last Name: " << current->lastName << std::endl;
        std::cout << "Position: " << current->position << std::endl;
        std::cout << "Age: " << current->age << std::endl;
        std::cout << "Games Played: " << current->gamesPlayed << std::endl;
        std::cout << "Goals Scored: " << current->goalsScored << std::endl << std::endl;
        current = current->next;
    }
}

// Функція для визначення кращого форварда
void findBestForward(FootballPlayer* head) {
    FootballPlayer* current = head;
    FootballPlayer* bestForward = nullptr;
    int maxGoals = 0;

    while (current != nullptr) {
        if (current->position == Forward && current->goalsScored > maxGoals) {
            maxGoals = current->goalsScored;
            bestForward = current;
        }
        current = current->next;
    }

    if (bestForward != nullptr) {
        std::cout << "Best Forward:\n";
        std::cout << "Last Name: " << bestForward->lastName << std::endl;
        std::cout << "Position: " << bestForward->position << std::endl;
        std::cout << "Age: " << bestForward->age << std::endl;
        std::cout << "Games Played: " << bestForward->gamesPlayed << std::endl;
        std::cout << "Goals Scored: " << bestForward->goalsScored << std::endl;
    } else {
        std::cout << "No forward found in the list.\n";
    }
}

// Функція для виведення футболістів, які зіграли менше 5 ігор
void displayPlayersWithFewGames(FootballPlayer* head) {
    FootballPlayer* current = head;

    std::cout << "Football Players who played less than 5 games:\n";
    while (current != nullptr) {
        if (current->gamesPlayed < 5) {
            std::cout << "Last Name: " << current->lastName << std::endl;
            std::cout << "Position: " << current->position << std::endl;
            std::cout << "Age: " << current->age << std::endl;
            std::cout << "Games Played: " << current->gamesPlayed << std::endl;
            std::cout << "Goals Scored: " << current->goalsScored << std::endl << std::endl;
        }
        current = current->next;
    }
}

int main() {
    FootballPlayer* list1 = createListFromInput();
    std::cout << "List created using createListFromInput:\n";
    displayFootballPlayers(list1);

    FootballPlayer* list2 = nullptr;
    formListWithParameter(list2);
    std::cout << "List created using formListWithParameter:\n";
    displayFootballPlayers(list2);

    findBestForward(list1);

    displayPlayersWithFewGames(list1);

    // Очищення пам'яті
    while (list1 != nullptr) {
        FootballPlayer* temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2 != nullptr) {
        FootballPlayer* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}
