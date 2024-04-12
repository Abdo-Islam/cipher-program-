// File: CS112_A2_T2_S21_20230225_20230374_20230328.cpp
// Purpose: this is a program to cipher or to decipher a message in three diffrent ways(Baconian cipher, Simple Substitution Cipher, XOR cipher)
// Author: Abdullah Islam Fathy Ibrahim , S21 
//         Mahmoud Ali Anwar Mohammed , S21
//         Mohamed Gamal Abd-Elmalek Abd-Elrehem , S21
// Abdullah Islam did the Simple Substitution Cipher , Mahmoud Ali did the Baconian cipher , Mohamed Gamal did the XOR cipher
// Emails: Abdullah : abdoislam2050@gmail.com 
//         Mahmoud : mahmoud.ali.ashor@gmail.com
//         Mohamed : mg4803558@gmail.com
// IDs: Abdullah : 20230225 , did the main menu + Simple Substitution Cipher and decipher 
//      Mahmoud : 20230374 , did the Baconian cipher and decipher 
//      Mohamed : 20230328 , did the XOR cipher and decipher 
#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std; 

// Function to check text[i] subset of this list1 or not (the first cipher in the main menu)
bool isFound(string array[], int size, string input)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == input)
            return true;
    }
    return false;
}

int hextodec (string hexNumber);
bool allCharactersInSet(const std::string& str, const std::string& characterSet);

int main() 
{
while (true)
{
  string choice1, choice2, message; 
  cout << "Ahlan ya user ya habibi. \n";
  cout << "What do you like to do today ?\n";
  cout << "1- Cipher a message\n";
  cout << "2- Decipher a message\n";
  cout << "3- End\n";
  cin >> choice1;
  while (choice1 != "1" && choice1 != "2" && choice1 != "3")
  {
    cout << "please enter a valid choice : ";
    cin >> choice1; 
  }
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (choice1 == "1")
    {
    cout << "Please enter the message to cipher : ";
    getline(cin,message); 
    cout << "Which Cipher do you like to choose?\n";
    cout << "1-Baconian cipher \n";
    cout << "2-Simple Substitution Cipher \n";
    cout << "3-XOR cipher \n";
    cout << "4-Return \n";
    cin >> choice2; 
    while (choice2 != "1" && choice2 != "2" && choice2 != "3" && choice2 != "4")
    {
      cout << "please enter a valid choice : ";
      cin >> choice2; 
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choice2 == "1")
    {
      
    string list1[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    string list2[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb", "bbaaa", "bbaab"};

    string text = message;

    // To convert each small letter into a capital letter
    for (char &c : text)
    {
        c = toupper(c);
    }

    cout << "*** The Cipher text: ";

    // Give each letter in the sentence individually
    for (int i = 0; i < text.size(); i++)
    {
        // if text.substr(i, 1) not in  list1  implement this code
        if (!isFound(list1, 26, text.substr(i, 1)))
        {
            if (text.substr(i, 1) == " ")
                cout << "";
            else
                cout << text.substr(i, 1) << " ";
        }

        // if text.substr(i, 1) in  list1  implement this code
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (list1[j] == text.substr(i, 1))
                {
                    cout << list2[j] << " ";
                    break;
                }
            }
        }
    }
    cout << " ***\n";

    }
    if (choice2 == "2")
    {
    // making a list for the english letters and 4 strings, key is the key word, m is the alphapit in the new order
    // c is the meesage to cipher, l is the message after the cipher 
    list<char> alphlist = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string key ,m = "" ,c ,l ;
    // taking the key word from the user 
    cout << "enter a five letter word : ";
    cin >> key;
    // checking that the key word is valid 
    while (size(key) != 5)
    {
        cout << "please enter a five word letter : ";
        cin >> key;
    }
    while (true)
    {   
    bool z = true; 
    for (int i = 0; i < key.size(); i++)
    {
      for (int j = 0; j < key.size(); j++)
      {
        if (i == j)continue; 
        if (key[i] == key[j]) z = false; 
      }
    }
    if (z) break; 
    else 
    {
      cout << "please enter a five letter word and have no reppeted characters : ";
      cin >> key; 
    }
    }
    while (true)
    {
        bool x = true; 
        for (int i = 0; i < size(key); i++)
        {
        if (!(isalpha(key[i])))
        {
            x = false;
            cout << "please enter a five word letter : ";
            cin >> key;
            break;
        }
        }
        if (x) break;
        while (size(key) != 5)
        {
            cout << "please enter a five word letter : ";
            cin >> key;
        }
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int i = 0;
    // converting the key word to lower case and romeve it from the alphapit list to put it in the first of it 
    for (char x : key)
    {
    x = tolower(x);
    key[i] = x;
    i++;
    alphlist.remove(x);
    }
    // making the new order for the english alphapit 
    for (char x : alphlist)
     m += x;
     m = key + m; 
    //putting the message to cipher in c
    c = message;
    i = 0;
    // converting the message to be lower case
    for (char x : c)
    {
    c[i] = tolower(x);
    i++; 
    }
    // ciphering the message 
    for (int i = 0; i < size(c); i++)
    {                                          
        if (isalpha(c[i])) 
        {
            l += m[(int(c[i]) - 97)];
        }
        else l += c[i];
    } 
    // printing the ciphered message 
    cout << "the ciphered message is : " << l << endl ;
    }
    if (choice2 == "3")
    {
      
    string word;
    string key_s;
    string key_r;
    int a;
    int b;
    int x=0;
    vector<int> asci(word.length());
    vector<int> c;
    word = message;
    int t=1;
    while (t==1) {
        cout<<"Enter key: ";
        getline(cin, key_s);
        for (int i = 0; i < key_s.length(); ++i) {
            if (isalpha(key_s[i])) {
                key_r += key_s[i];
            }

        }
        if(key_s.length()==key_r.length()){
            t=0;
        } else{
            cout<<"Invalid key\n";
            key_r="";
            key_s="";
        }
    }
    for(int i=0;i<word.length();i++) {
        if(word[i]==' '){
            asci.push_back(' ');
        } else {
            asci.push_back(int(word[i]));
            //cout<<asci[i]<<",";
        }
    }
    for(int i=0;i<asci.size();i++){
        a=asci[i];
        b= int (key_r[x]);
        c.push_back(a^b);
        x++;
        if(x==key_r.length()){
            x=0;
        }
        // cout<<c[i]<<",";
    }cout<<"Cipher text: ";
    for(int i=0;i<asci.size();i++){
        cout<<char(c[i]);
    }
    cout<<"\nHexa: ";
    // Input decimal number
    for(int i=0;i<c.size();i++) {
        int decimal_number=c[i];
        // Convert decimal_number to hexadecimal using std::hex
        cout << hex << decimal_number<<' ';
    }
    cout << endl;
    }
    if (choice2 == "4")
    {
      continue;
    }
    }

  if (choice1 == "2")
    {
    cout << "Please enter the message to decipher : ";
    getline(cin,message); 
    cout << "Which Cipher do you like to choose to decipher your message ?\n";
    cout << "1-Baconian cipher \n";
    cout << "2-Simple Substitution Cipher \n";
    cout << "3-XOR cipher \n";
    cout << "4-Return \n";
    cin >> choice2; 
    while (choice2 != "1" && choice2 != "2" && choice2 != "3" && choice2 != "4")
    {
      cout << "please enter a valid choice : ";
      cin >> choice2; 
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choice2 == "1")
    {
      
    string list1[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab", "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba", "babbb", "bbaaa", "bbaab"};
    string list2[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    string text = message;
    string name = "";
    bool valid = true;

    cout << "*** The encrypted message: ";

    // Give every five letters together in the sentence individually
    for (int i = 0; i < text.size(); i += 5)
    {
        // if find space remove it
        while (text.substr(i, 1) == " ")
        {
            text = text.substr(0, i) + text.substr(i + 1);
        }

        // Check if the remaining text is enough for another group of 5 characters
        if (i + 5 > text.size())
        {
            valid = false;
            break;
        }

        // if text.substr(i, 5) not in  list1 end the program
        if (!isFound(list1, 26, text.substr(i, 5)))
        {
            valid = false;
            break;
        }

        for (int j = 0; j < 26; j++)
        {
            if (list1[j] == text.substr(i, 5))
            {
                name += list2[j];
                break;
            }
        }
    }

    if (valid == true)
        cout << name;
    else
        cout << "invalid message to decipher ";

    cout << " *** \n";

    }
    if (choice2 == "2")
    {
    // making a list for the english letters and 4 strings, key is the key word, m is the alphapit in the new order
    // c is the meesage to decipher, l is the message after the cipher 
    list<char> alphlist = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string key ,m = "" ,c ,l ;
    // taking the key word from the user 
    cout << "enter a five letter word : ";
    cin >> key;
    // checking that the key word is valid 
    while (size(key) != 5)
    {
        cout << "please enter a five word letter : ";
        cin >> key;
    }
    while (true)
    {
        bool x = true; 
        for (int i = 0; i < size(key); i++)
        {
        if (!(isalpha(key[i])))
        {
            x = false;
            cout << "please enter a five word letter : ";
            cin >> key;
            break;
        }
        }
        if (x) break;
        while (size(key) != 5)
        {
            cout << "please enter a five word letter : ";
            cin >> key;
        }
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int i = 0;
    // converting the key word to lower case and romeve it from the alphapit list to put it in the first of it 
    for (char x : key)
    {
    x = tolower(x);
    key[i] = x;
    i++;
    alphlist.remove(x);
    }
    // making the new order for the english alphapit 
    for (char x : alphlist)
     m += x;
     m = key + m; 
    // putting the message to decipher in c
    c = message;
    i = 0;
    // converting the message to be lower case
    for (char x : c)
    {
    c[i] = tolower(x);
    i++; 
    }
    // deciphering the message 
    int j;  
    for (int i = 0; i < size(c); i++)
    {                               
        if (isalpha(c[i]))         
        {  
            for (j = 0; j < size(m);j++) 
            {
                if (m[j] == c[i])
                {
                    l += char(j + 97);
                }
            }
        }
        else l += c[i];
    } 
    // printing the ciphered message 
    cout << "the ciphered message is : " << l << endl ;
    }
    if (choice2 == "3")
    {
      
    string key_rr;
    string key_d;
    vector<int>key_n;
    string codeh;
    vector<int>dech;
    vector<char>de_char;
    vector<string>massageh;
    while (true) {
        codeh = message; 
        if(allCharactersInSet(codeh," 0123456789abcdef")){
            break;
        } else{
            cout <<"invalid hexadecimal number!\n";
            cout<<"enter a massage to decipher"<<": ";
            continue;
        }
    }int t=1;
    while (t==1) {
        cout << "enter key:";
        cin >> key_d;
        for (int i = 0; i < key_d.length(); ++i) {
            if (isalpha(key_d[i])) {
                key_rr += key_d[i];
            }

        }
        if(key_d.length()==key_rr.length()){
            t=0;
        } else{
            cout<<"Invalid key\n";
            key_rr="";
            key_d="";
        }
    }
    string tempmsg;
    for(int i=0; i < codeh.length(); i++){
        if (codeh[i] == ' '){
            massageh.push_back(tempmsg);
            tempmsg="";
            continue;
        }else{
            tempmsg+=codeh[i];
        }
    }
    massageh.push_back(tempmsg);

//for(int i=0;i<massageh.size();i++){
//  cout<<massageh[i]<<" ";
//}
    for (int i = 0; i < massageh.size(); ++i) {
        dech.push_back(hextodec(massageh[i]));
    }
    for (int i = 0; i < key_rr.length(); ++i) {
        key_n.push_back(int(key_rr[i]));
    }
    int x=0;
    for (int i = 0; i < dech.size(); ++i) {
        de_char.push_back(char(dech[i]^key_n[x]));
        x++;
        if(x==key_n.size()){
            x=0;
        }
    }cout<<"Plain text: ";
    for (int i = 0; i < de_char.size(); ++i) {
        cout<<de_char[i];
    }
    cout << endl;
    }
    if (choice2 == "4")
    {
      continue; 
    }
    }

  if (choice1 == "3")
    break;

}
return 0; 
}

int hextodec (string hexNumber) {
    // Converting hex to decimal
    int decimalNumber = 0;
    int hexLength = hexNumber.length();
    int power = 0;

    for (int i = hexLength - 1; i >= 0; i--) {
        char digit = hexNumber[i];
        int digitValue;

        if (digit >= '0' && digit <= '9') {
            digitValue = digit - '0';
        } else if (digit >= 'a' && digit <= 'f') {
            digitValue = 10 + (digit - 'a');
        } else if (digit >= 'A' && digit <= 'F') {
            digitValue = 10 + (digit - 'A');
        } else {
            cout << "Invalid hexadecimal number!" << endl;
            return 1;
        }

        decimalNumber += digitValue * pow(16, power);
        power++;
    }
    return decimalNumber;
}
bool allCharactersInSet(const std::string& str, const std::string& characterSet) {
    for (char ch : str) {
        if (characterSet.find(ch) == std::string::npos) {
            // If the character is not in the set, return false
            return false;
        }
    }
    // If all characters are in the set, return true
    return true;
}