#include <iostream>
#include <stdlib.h>
#include <vector>

std::string pick_item(int, std::vector<std::string>);

int main() {
  srand(time(NULL));
  int computer = rand() % 5 + 1;
  int user = 0;
  std::string winner;
  std::vector<std::string> actionNext = {"cuts", "covers", "crushes", "poisons", "smashes"};
  std::vector<std::string> actionBeforeLast = {"decapitates", "disproves", "crushes", "eats", "vaporizes"};
  std::vector<std::string> signs = {"Scissors", "Paper", "Rock", "Lizard", "Spock"};
  std::string action;

  std::cout << "=================================\n";
  std::cout << "Rock Paper Scissors Lizard Spock!\n";
  std::cout << "=================================\n";
 
  std::cout << "1) ✌️\n";
  std::cout << "2) ✋\n";
  std::cout << "3) ✊\n";
  std::cout << "4) 🤏\n";
  std::cout << "5) 🖖\n";
 
  std::cout << "shoot!\n\n";
  std::cin >> user;
  std::cout << "\n";

  if(computer != user) {
    if((user + 1) % 5 == computer % 5) { 
      action = pick_item(user, actionNext);
      winner = "you";
    }
    if((user + 5 - 2) % 5 == computer % 5) {
      action = pick_item(user, actionBeforeLast);
      winner = "you";
    }
    if((computer + 1) % 5 == user % 5) {
      action = pick_item(computer, actionNext);
      winner = "computer";
    }
    if((computer + 5 - 2) % 5 == user % 5) {
      action = pick_item(computer, actionBeforeLast);
      winner = "computer";
    }

    if(winner == "computer") {
      std::cout << pick_item(computer, signs) << " " << action << " " << pick_item(user, signs) << "\n";
      std::cout << "And the winner is: " << winner << "!\n";
    } else if (winner == "you") {
        std::cout << pick_item(user, signs) << " " << action << " " << pick_item(computer, signs) << "\n";
        std::cout << "And the winner is: " << winner << "!\n";
    }
  } else
    std::cout << "The game ended in a draw\n";
  
  return 0;
}

std::string pick_item(int index, std::vector<std::string> items) {
  return items[index - 1];
}
