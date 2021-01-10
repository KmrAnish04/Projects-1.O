#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void speaker(string newsCotent)
{
    string phrase = newsCotent;
    string command = "espeak -v +f3 -s 145 \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
}

void loadingBar() 
{ 
    // 0 - black background, 
    // A - Green Foreground 
    system("color 0A"); 
  
    // Initialize char for printing 
    // loading bar 
    char a = 177, b = 219; 
  
    printf("\n\n\n\n"); 
    printf("\n\n\n\n\t\t\t\t\tFetching news from sources...\n\n"); 
    printf("\t\t\t\t\t"); 
  
    // Print initial loading bar 
    for (int i = 0; i < 26; i++) 
        printf("%c", a); 
  
    // Set the cursor again starting 
    // point of loading bar 
    printf("\r"); 
    printf("\t\t\t\t\t"); 
  
    // Print loading bar progress 
    for (int i = 0; i < 26; i++) { 
        printf("%c", b); 
  
        // Sleep for 1 second 
        Sleep(1000); 
    } 
} 

int main()
{

    int counter = 1;
    string currentContent;
    string Links;

    ifstream file;
    file.open("NewsContent.txt", ios::in);
    
    ifstream fLink;
    fLink.open("Links.txt", ios::in);

    loadingBar();

    while (std::getline(file, currentContent))
    {
        int Linker = 1;
        if (counter % 2 == 0)
        {
            cout << "Discription:- " << currentContent << "\n\n";
            speaker("Disciption");
            Sleep(1000);
            speaker(currentContent);
            Sleep(1000);
            counter++;

            for (int i = Linker; i < Linker+1; i++)
            {
                std::getline(fLink, Links);
                cout<<"For More Info: " << Links << "\n";
            }

            cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-END-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

        }

        else
        {
            cout<<"\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-NEWS-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
            cout << "Title:- " << currentContent << "\n\n";
            speaker("Title");
            Sleep(1000);
            speaker(currentContent);
            Sleep(1000);
            counter++;
        }

        Linker++;
        
    }

    file.close();
    fLink.close();
    return 0;
}