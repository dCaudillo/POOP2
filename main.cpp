#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

bool guessing

int main()
{
  //Creates files and in/outputs
  std::ofstream names_out ("names.txt");
  std::ifstream names_in ("names.txt");
  std::ofstream high_scores_out ("high scores.txt");
  std::ifstream high_scores_in ("high scores.txt");

  //Score and Guess vector created
  int score = 0;
  std::vector<int> guess_list;
  std::string name;
  
  //Random seed is generated for ANSWER
  srand(time(NULL));
  const int ANSWER = (rand() % 101);

  

  //Entering Game or Leaving
  bool play = 0;
  do
  {
    //Will ignore 1st time, but will play if player choses yes bc do-while loop
    //allows to change outcome mid-way
    if(play)
    {
      guessing();
      add_highscore();
      display_final_scores();
    }
    //Playing?
    std::cout << "Want to Play? \n1. Play \n0. Quit" << std::endl;
    std::cin >> play;
  }while(play);

  std::cout << "Goodbye. Come Again!" << std::endl;
}