/*
    Description: 
    In affine cipher each letter in an alphabet is mapped to its numeric equivalent, encrypted using a
    simple mathematical function, and converted back to a letter.

    Author: Fady Kamal
    Version: 1.0
*/



#include <iostream>
#include <string>
#include <limits>
using namespace std;

// this function will display three options to the user and return the choice into declared varible by refrance (call by refrance)
int display(bool &first_time, int &choice)
{
    // if first_true >> (true) print welcome
    if (first_time)
    {
        cout << "!! Welcome !!" << endl;
        first_time = false;
    }

    cout << "1- Encrypt A Message Using (Affine-Cipher)\n2- Decrypt A Message Using (Affine-Cipher)\n3- Exit" << endl;
    // take the choice
    cout << "#####################" << endl;
    cout << "What Do You Want to do?: ";
    // return the choice into the refrance of choice (&choice)
    cin >> choice;
    return choice;
    
}   



// this function handles all the modulus operation specially if m is negative where (m % n = reminder)
// note that % operator in c++ isn't the modulus operator but it's the division reminder
long mod_for_all_(int a, int b)
{
    return (a % b + b) % b;
}



// Encrypting Function
void encrypt_with_affine()
{
    // take the message from the user
    cout << "Enter The Message You Want to Encrypt: ";
    string message;
    getline( cin >> ws, message);

    // take a, b, c from the user 
    cout << "Enter The value of (a, b) Where (a*x + b) % 26 Is The Formula of Encryption: ";
    int a, b;
    cin >> a >> b;

    // convert all the message's letters into uppercase
    for (auto &c: message) c = toupper(c);
    
    // initiallize thea abc to fetch the chara position
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string encrpyted;

    int position_in_abc, new_position;
    char new_char;
    // iterate over each chara of the message
    for (int i = 0; i < message.length(); ++i)
    {   // fetch each chara from the message
        char chara = message[i];
        // check if the char is space add space to encrypted char and continue
        if (chara == ' ')
        {
            
            encrpyted += " ";
            continue;
        }
        else
        {
            // if not then fetch the char index from abc (x), then  use the following foumla to get the new index >> (5x + 8)
            position_in_abc = abc.find(chara);  

            // here it's guranted that new_position will be positive therefore i used the regulare division reminder >> %
            new_position = ((a * position_in_abc) + b) % 26;
            new_char = abc[new_position];
            encrpyted += new_char;
            
        }
    }
    cout << "Encrypted Message: " << encrpyted << endl;
}

// decryption function
void decrypt()
{
    // take the message from the user
    cout << "Enter The Message you Want to Decrypt: ";
    string message;
    getline(cin >> ws, message);
    cout << "Enter The value of (c, b) Where c*(y - b) % 26 Is The Formula of Decryption: ";
    int c, b;
    cin >> c >> b;


    // convert all the message's letters into uppercase
    for (auto &c : message) c = toupper(c);
    
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string decrypted;
    char chara;
    int position_in_abc;
    int new_position;
    // for each chara in message
    for (int i = 0; i < message.length(); ++i)
    {
        chara = message[i];
        if (chara == ' ')
        {
            decrypted += " ";
            continue;

        }
        else
        { 

            position_in_abc = abc.find(chara);
            // utilizatin of mod_for_all function >> incase the outcome of the decypting formula is negative 
            new_position = mod_for_all_((c / (position_in_abc - b)), 26);
            char new_chara = abc[new_position];
            decrypted += new_chara;

        }
    }

    cout << "Decrypted Message: " << decrypted << endl;
}

int main()
{
    // programe status
    bool programe_running, first_time;
    programe_running = true;
    first_time = true;
    int choice;

    // displey message
    choice = display(first_time, choice);
    // while programe running keep iterating over the following functions
    while (programe_running)
    {
        if (choice == 1)
        {
            encrypt_with_affine();
        }
        else if (choice == 2)
        {
            decrypt();
        }
        else if (choice == 3)
        {
            exit(2);
        }
        cout << "#######################################" << endl;
        choice = display(first_time, choice);
        // seperator
        cout << "#######################################" << endl;
    }
}
