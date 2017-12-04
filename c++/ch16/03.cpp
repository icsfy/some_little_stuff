#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>
using std::string;
#define WORDLIST "wordlist.txt"
/* Read wordlist from file: "wordlist.txt"
const int NUM = 26;
const string wordlist[NUM] = {
  "apiary", "beetle", "cereal", "danger", "ensign", "florid",
  "garage", "health", "insult", "jackal", "keeper", "loaner",
  "manage", "nonce", "onset", "plaid", "quilt", "remote",
  "stolid", "train", "useful", "valid", "whence", "xenon",
  "yearn", "zippy"
}; */
void showWord(const string & s)
{
  std::cout << s << " ";
}

int main()
{
  using std::cout; using std::cin; using std::endl;
  using std::vector; using std::ifstream;
  using std::tolower;

  ifstream fin(WORDLIST);
  if(!fin.is_open()) {
    cout << "Cannot open file: " << WORDLIST << endl;
    exit(EXIT_FAILURE);
  }
  vector<string> wordlist;
  string tempword;
  while(fin >> tempword)
    wordlist.push_back(tempword);
  fin.close();
  int NUM = wordlist.size();
  cout << "Read " << NUM << " words from " << WORDLIST << endl;
  for_each(wordlist.begin(), wordlist.end(), showWord);

  std::srand(std::time(0));
  char play;
  cout << "\nWill you play a word game? <y/n> ";
  cin >> play;
  play = tolower(play);
  while(play == 'y')
  {
    string target = wordlist[std::rand() % NUM];
    int length = target.length();
    string attempt(length, '-');
    string badchars;
    int guesses = 6;
    cout << "Guess my secret word. It has " << length
         << " letters, and you guess\n"
         << "one letter at a time. You get " << guesses
         << " wrong guesses.\n";
    cout << "Your word: " << attempt << endl;
    while (guesses > 0 && attempt != target)
    {
      char letter;
      cout << "Guess a letter: ";
      cin >> letter;
      if (badchars.find(letter) != string::npos
        || attempt.find(letter) != string::npos)
      {
        cout << "You already guessed that. Try again.\n";
        continue;
      }
      int loc = target.find(letter);
      if (loc == string::npos) {
        cout << "Oh, bad guess!\n";
        --guesses;
        badchars += letter;
      } else {
        cout << "Good guess!\n";
        attempt[loc] = letter;
        loc = target.find(letter, loc + 1);
        while (loc != string::npos) {
          attempt[loc] = letter;
          loc = target.find(letter, loc + 1);
        }
      }
      cout << "Your word: " << attempt << endl;
      if (attempt != target) {
        if (badchars.length() > 0)
          cout << "Bad choices: " << badchars << endl;
        cout << guesses << " bad guesses left\n";
      }
    }
    if (guesses > 0)
      cout << "That's right!\n";
    else
      cout << "Sorry, the word is " << target << ".\n";
    cout << "Will you play another? <y/n> ";
    cin >> play;
    play = tolower(play);
  }
  cout << "Bye\n";
  return 0;
}
