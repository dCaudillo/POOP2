#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

void guessing(int &score, std::vector<int> &guess_list, int ANSWER)
{
  int temp;

  do{
    std::cout << ANSWER << std::endl;
    //Guess number and tracks score & guess_list
    std::cout << "Guess a number:" << std::endl;
    std::cin >> temp;
    guess_list.push_back(temp);
    score++;
    if(temp < ANSWER)
    {
      std::cout << "Too Low" << std::endl;
    }
    else if(temp > ANSWER)
    {
      std::cout << "Too High" << std::endl;
    }
  }while(temp != ANSWER);
}

void add_highscore(int score, std::vector<int> guess_list)
{
  //Creates files and in/outputs
  std::ofstream name_input ("names.txt", std::ios::app);
  std::ofstream high_score_input ("high scores.txt", std::ios::app);
  int add_score;
  std::string name;

  //Prints score
  std::cout << "CLEARED! \nYou guessed correctly in " << score << " tries!" << std::endl;

  //Prints guesses
  std::cout << "You guesssed ";
  
  if(guess_list.size() > 1)
  {
    for(int i = 0; i <= (guess_list.size()-2); i++)
    {
      std::cout << guess_list[i] <<", ";
    }
  }
  std::cout << guess_list[guess_list.size()-1] << "." << std::endl;

  //Asks to add highscore
  std::cout << "Would you like to add your score?   \n1. Yes    \n0. No" << std::endl;
  std::cin >> add_score;
  if(add_score == 1)
  {
    std::cout << "Enter name:";
    std::cin >> name;
    name_input << name;
    high_score_input << score;

    std::cout << name << ": " << score << " points." << std::endl;
  }

}

void display_highscores()
{
  //Creating Outputs and vectors to hold info, as well as, temporay place-holders
  std::ifstream name_print ("names.txt");
  std::ifstream high_score_print ("high scores.txt");
  std::vector<std::string> names = {};
  std::vector<int> scores = {};
  int temp_score;
  std::string temp_name;

  //Initializing vectors
  while(name_print >> temp_name && high_score_print >> temp_score)
  {
    names.push_back(temp_name);
    scores.push_back(temp_score);

    std::cout << temp_name;
  }

  //Prints names and scores
  std::cout << "HIGH SCORES:" << std::endl;

  

  

}


int main()
{

  //Score and Guess vector created
  int score, ANSWER;
  std::vector<int> guess_list;
  srand(time(NULL));

  

  

  //Entering Game or Leaving
  int play = 0;
  do
  {
    //Will ignore 1st time, but will play if player choses yes bc do-while loop
    //allows to change outcome mid-way
    if(play == 1)
    {
      //Random seed is generated for ANSWER and Score & Guess is cleared
      score = 0;
      guess_list = {};
      ANSWER = (rand() % 101);
      
      guessing(score, guess_list, ANSWER);
      add_highscore(score, guess_list);
      display_highscores();
    }
    //Playing?
    std::cout << "Want to Play? \n1. Play \n0. Quit" << std::endl;
    std::cin >> play;
  }while(play == 1);

  std::cout << "Goodbye. Come Again!" << std::endl;
}