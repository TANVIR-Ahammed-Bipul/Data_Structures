#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User
{
    char username[50];
    char password[50];
    struct User* next;
};
typedef struct User user;
user* userList = NULL;

user* createUser(char username[], char password[]);
void addUser(user** userList, user* newUser);
int authenticateUser(user* userList, char username[], char password[]);

user* createUser(char username[], char password[])
{
    user* newUser = (user*)malloc(sizeof(user));
    if (newUser == NULL)
    {
        printf("Error: Could not allocate memory for new user.\n");
        exit(1);
    }
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->next = NULL;
    return newUser;
}

void addUser(user** userList, user* newUser)
{
    newUser->next = *userList;
    *userList = newUser;
}

int authenticateUser(user* userList, char username[], char password[])
{
    user* current = userList;
    while (current != NULL)
    {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main()
{
    int loggedIn = 0;
    char currentUser[50] = "";

    int choice;
    char searchName[100];

    while(1)
    {
        if(!loggedIn)
        {
            char title[]="Welcome to our CampusMart";
            printf("\033[1m%60s\033[0m\n", title);
            printf("%40s1. Sign Up\n", "");
            printf("%40s2. Log In\n", "");
            printf("%40s3. Exit\n", "");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
            case 1:
                ;
                char newUsername[50], newPassword[50];
                printf("Enter a username: ");
                scanf("%s", newUsername);
                printf("Enter a password: ");
                scanf("%s", newPassword);

                user* newUser = createUser(newUsername, newPassword);
                addUser(&userList, newUser);
                printf("Account created successfully!\n");
                break;

            case 2:
                if (loggedIn)
                {
                    printf("You are already logged in as %s.\n", currentUser);
                }
                else
                {
                    char loginUsername[50], loginPassword[50];
                    printf("Enter your username: ");
                    scanf("%s", loginUsername);
                    printf("Enter your password: ");
                    scanf("%s", loginPassword);

                    if (authenticateUser(userList, loginUsername, loginPassword))
                    {
                        loggedIn = 1;
                        strcpy(currentUser, loginUsername);
                        printf("Welcome, %s!\n", currentUser);
                    }
                    else
                    {
                        printf("Authentication failed. Please check your credentials.\n");
                    }
                }
                break;
            case 3:
                printf("\033[1m%40sGoodbye!\033[0m\n", "");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
    return 0;
}
