#include <iostream>
#include <cstring>  // For standard string functions
#include <cctype>   // For character manipulation
#include <limits>   // For input handling

// Custom implementations for strlwr, strupr, and strrev
char* my_strlwr(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

char* my_strupr(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

char* my_strrev(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}

// Function to clear the screen (multi-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to display the menu
void displayMenu() {
    std::cout << "\t\t\t\t+---------------------------------------+\n";
    std::cout << "\t\t\t\t|     STRING FUNCTIONS DEMONSTRATION    |\n";
    std::cout << "\t\t\t\t|---------------------------------------|\n";
    std::cout << "\t\t\t\t| 1. strlen - Get string length         |\n";
    std::cout << "\t\t\t\t| 2. strcpy - Copy string               |\n";
    std::cout << "\t\t\t\t| 3. strcat - Concatenate strings       |\n";
    std::cout << "\t\t\t\t| 4. strcmp - Compare strings           |\n";
    std::cout << "\t\t\t\t| 5. strlwr - Convert to lowercase      |\n";
    std::cout << "\t\t\t\t| 6. strupr - Convert to uppercase      |\n";
    std::cout << "\t\t\t\t| 7. strrev - Reverse string            |\n";
    std::cout << "\t\t\t\t| 8. View/Edit current strings          |\n";
    std::cout << "\t\t\t\t| 9. Exit                               |\n";
    std::cout << "\t\t\t\t+---------------------------------------+\n";
    std::cout << "\t\t\t\tEnter your choice (1-9): ";
}

// Function to pause and wait for user input
void pauseScreen() {
    std::cout << "\t\t\t\t\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    // Initialize string variables
    char str1[100] = "iloveyou";
    char str2[100] = "imissyou";
    char result[200] = "iloveyouimissyou";  // Start with an empty result string
    bool running = true;
    int choice;
    
    while (running) {
        clearScreen();
        std::cout << "\t\t\t\t Current strings:\n";
        std::cout << "\t\t\t\t  String 1: \"" << str1 << "\"\n";
        std::cout << "\t\t\t\t  String 2: \"" << str2 << "\"\n";
        std::cout << "\t\t\t\t  Result:   \"" << result << "\"\n";
        
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
        
        clearScreen();
        std::cout << "\t\t\t\t Current strings:\n";
        std::cout << "\t\t\t\t  String 1: \"" << str1 << "\"\n";
        std::cout << "\t\t\t\t  String 2: \"" << str2 << "\"\n";
        std::cout << "\t\t\t\t  Result:   \"" << result << "\"\n\n";
        
        // Process user choice
        switch(choice) {
            case 1: { // strlen
                std::cout << "\t\t\t\t+--------------------------------+\n";
                std::cout << "\t\t\t\t|          strlen DEMO           |\n";
                std::cout << "\t\t\t\t+--------------------------------+\n\n";
                std::cout << "\t\t\t\tstrlen(\"" << str1 << "\") = " << strlen(str1) << " characters\n";
                std::cout << "\t\t\t\tstrlen(\"" << str2 << "\") = " << strlen(str2) << " characters\n";
                if (strlen(result) > 0)
                    std::cout << "\t\t\t\tstrlen(\"" << result << "\") = " << strlen(result) << " characters\n";
                break;
            }
            case 2: { // strcpy
                std::cout << "\t\t\t\t+--------------------------------+\n";
                std::cout << "\t\t\t\t|          strcpy DEMO           |\n";
                std::cout << "\t\t\t\t+--------------------------------+\n\n";
                std::cout << "\t\t\t\tWhich string do you want to copy?\n";
                std::cout << "\t\t\t\t1. String 1 (\"" << str1 << "\")\n";
                std::cout << "\t\t\t\t2. String 2 (\"" << str2 << "\")\n";
                std::cout << "\t\t\t\tEnter choice (1 or 2): ";
                int copyChoice;
                std::cin >> copyChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << "\t\t\t\tBefore: result = \"" << result << "\"\n";
                if (copyChoice == 1) {
                    strcpy(result, str1);
                    std::cout << "\t\t\t\tAfter strcpy(result, str1): result = \"" << result << "\"\n";
                } else if (copyChoice == 2) {
                    strcpy(result, str2);
                    std::cout << "\t\t\t\tAfter strcpy(result, str2): result = \"" << result << "\"\n";
                } else {
                    std::cout << "\t\t\t\tInvalid choice.\n";
                }
                break;
            }
            case 3: { // strcat
                std::cout << "\t\t\t\t+--------------------------------+\n";
                std::cout << "\t\t\t\t|          strcat DEMO           |\n";
                std::cout << "\t\t\t\t+--------------------------------+\n\n";
                std::cout << "\t\t\t\tWhich string do you want to concatenate to the result?\n";
                std::cout << "\t\t\t\t1. String 1 (\"" << str1 << "\")\n";
                std::cout << "\t\t\t\t2. String 2 (\"" << str2 << "\")\n";
                std::cout << "\t\t\t\tEnter choice (1 or 2): ";
                int catChoice;
                std::cin >> catChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << "\t\t\t\tBefore: result = \"" << result << "\"\n";
                if (catChoice == 1) {
                    strcat(result, str1);  // Concatenate str1 to result
                    std::cout << "\t\t\t\tAfter strcat(result, str1): result = \"" << result << "\"\n";
                } else if (catChoice == 2) {
                    strcat(result, str2);  // Concatenate str2 to result
                    std::cout << "\t\t\t\tAfter strcat(result, str2): result = \"" << result << "\"\n";
                } else {
                    std::cout << "\t\t\t\tInvalid choice.\n";
                }
                break;
            }
            case 4: { // strcmp
                std::cout << "\t\t\t\t+--------------------------------+\n";
            	std::cout << "\t\t\t\t|     Compare String Lengths     |\n";
            	std::cout << "\t\t\t\t+--------------------------------+\n\n";

            	int lengthStr1 = strlen(str1);
            	int lengthStr2 = strlen(str2);

            	std::cout << "\t\t\t\tLength of String 1 (\"" << str1 << "\"): " << lengthStr1 << " characters\n";
            	std::cout << "\t\t\t\tLength of String 2 (\"" << str2 << "\"): " << lengthStr2 << " characters\n";

            	if (lengthStr1 > lengthStr2) {
                	std::cout << "\t\t\t\tString 1 is longer.\n";
            	} else if (lengthStr1 < lengthStr2) {
                	std::cout << "\t\t\t\tString 2 is longer.\n";
            	} else {
                	std::cout << "\t\t\t\tBoth strings have equal length.\n";
           		}
                break;
            }
            case 5: { // strlwr
                std::cout << "\t\t\t\t+--------------------------------+\n";
                std::cout << "\t\t\t\t|          strlwr DEMO           |\n";
                std::cout << "\t\t\t\t+--------------------------------+\n\n";
                std::cout << "\t\t\t\tWhich string do you want to convert to lowercase?\n";
                std::cout << "\t\t\t\t1. String 1 (\"" << str1 << "\")\n";
                std::cout << "\t\t\t\t2. String 2 (\"" << str2 << "\")\n";
                std::cout << "\t\t\t\t3. Result (\"" << result << "\")\n";
                std::cout << "\t\t\t\tEnter choice (1-3): ";
                int lwrChoice;
                std::cin >> lwrChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                if (lwrChoice == 1) {
                    std::cout << "\t\t\t\tBefore: str1 = \"" << str1 << "\"\n";
                    my_strlwr(str1);
                    std::cout << "\t\t\t\tAfter my_strlwr(str1): str1 = \"" << str1 << "\"\n";
                } else if (lwrChoice == 2) {
                    std::cout << "\t\t\t\t\nBefore: str2 = \"" << str2 << "\"\n";
                    my_strlwr(str2);
                    std::cout << "\t\t\t\tAfter my_strlwr(str2): str2 = \"" << str2 << "\"\n";
                } else if (lwrChoice == 3) {
                    std::cout << "\t\t\t\t\nBefore: result = \"" << result << "\"\n";
                    my_strlwr(result);
                    std::cout << "\t\t\t\tAfter my_strlwr(result): result = \"" << result << "\"\n";
                } else {
                    std::cout << "\t\t\t\tInvalid choice.\n";
                }
                break;
            }
            case 6: { // strupr
                std::cout << "\t\t\t\t+--------------------------------+\n";
                std::cout << "\t\t\t\t|          strupr DEMO           |\n";
                std::cout << "\t\t\t\t+--------------------------------+\n\n";
                std::cout << "\t\t\t\tWhich string do you want to convert to uppercase?\n";
                std::cout << "\t\t\t\t1. String 1 (\"" << str1 << "\")\n";
                std::cout << "\t\t\t\t2. String 2 (\"" << str2 << "\")\n";
                std::cout << "\t\t\t\t3. Result (\"" << result << "\")\n";
                std::cout << "\t\t\t\tEnter choice (1-3): ";
                int uprChoice;
                std::cin >> uprChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                if (uprChoice == 1) {
                    std::cout << "\t\t\t\tBefore: str1 = \"" << str1 << "\"\n";
                    my_strupr(str1);
                    std::cout << "\t\t\t\tAfter my_strupr(str1): str1 = \"" << str1 << "\"\n";
                } else if (uprChoice == 2) {
                    std::cout << "\t\t\t\t\nBefore: str2 = \"" << str2 << "\"\n";
                    my_strupr(str2);
                    std::cout << "\t\t\t\tAfter my_strupr(str2): str2 = \"" << str2 << "\"\n";
                } else if (uprChoice == 3) {
                    std::cout << "\t\t\t\t\nBefore: result = \"" << result << "\"\n";
                    my_strupr(result);
                    std::cout << "\t\t\t\tAfter my_strupr(result): result = \"" << result << "\"\n";
                } else {
                    std::cout << "\t\t\t\tInvalid choice.\n";
                }
                break;
            }
            case 7: { // strrev
                std::cout << "\t\t\t\t+--------------------------------+\n";
                std::cout << "\t\t\t\t|          strrev DEMO           |\n";
                std::cout << "\t\t\t\t+--------------------------------+\n\n";
                std::cout << "\t\t\t\tWhich string do you want to reverse?\n";
                std::cout << "\t\t\t\t1. String 1 (\"" << str1 << "\")\n";
                std::cout << "\t\t\t\t2. String 2 (\"" << str2 << "\")\n";
                std::cout << "\t\t\t\t3. Result (\"" << result << "\")\n";
                std::cout << "\t\t\t\tEnter choice (1-3): ";
                int revChoice;
                std::cin >> revChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                if (revChoice == 1) {
                    std::cout << "\t\t\t\tBefore: str1 = \"" << str1 << "\"\n";
                    my_strrev(str1);
                    std::cout << "\t\t\t\tAfter my_strrev(str1): str1 = \"" << str1 << "\"\n";
                } else if (revChoice == 2) {
                    std::cout << "\t\t\t\t\nBefore: str2 = \"" << str2 << "\"\n";
                    my_strrev(str2);
                    std::cout << "\t\t\t\tAfter my_strrev(str2): str2 = \"" << str2 << "\"\n";
                } else if (revChoice == 3) {
                    std::cout << "\t\t\t\t\nBefore: result = \"" << result << "\"\n";
                    my_strrev(result);
                    std::cout << "\t\t\t\tAfter my_strrev(result): result = \"" << result << "\"\n";
                } else {
                    std::cout << "\t\t\t\tInvalid choice.\n";
                }
                break;
            }
            case 8: { // Edit strings
                std::cout << "\t\t\t\t+--------------------------------+\n";
                std::cout << "\t\t\t\t|     Edit strings DEMO          |\n";
                std::cout << "\t\t\t\t+--------------------------------+\n\n";
                std::cout << "\t\t\t\tWhich string would you like to edit?\n";
                std::cout << "\t\t\t\t1. String 1\n";
                std::cout << "\t\t\t\t2. String 2\n";
                std::cout << "\t\t\t\t3. Result\n";
                std::cout << "\t\t\t\tEnter choice (1-3): ";
                int editChoice;
                std::cin >> editChoice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                if (editChoice == 1) {
                    std::cout << "\t\t\t\tEnter new value for String 1: ";
                    std::cin.getline(str1, sizeof(str1));
                } else if (editChoice == 2) {
                    std::cout << "\t\t\t\tEnter new value for String 2: ";
                    std::cin.getline(str2, sizeof(str2));
                } else if (editChoice == 3) {
                    std::cout << "\t\t\t\tEnter new value for Result: ";
                    std::cin.getline(result, sizeof(result));
                } else {
                    std::cout << "\t\t\t\tInvalid choice.\n";
                }
                break;
            }
            case 9: { // Exit
                running = false;
                std::cout << "\t\t\t\tExiting program...\n";
                break;
            }
            default:
                std::cout << "\t\t\t\tInvalid choice. Please try again.\n";
                break;
        }
        
        if (running) pauseScreen();
    }
    
    return 0;
}

