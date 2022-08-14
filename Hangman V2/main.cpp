#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <cctype>

int main();
std::vector<std::string> randomWord{ "test", "mozarella", "dadaismuss", "tablette", "controller", "maus", "tastatur", "headset", "blatt", "flasche", "glas", "handy", "lautsprecher", "verkehrskontrolle", "kissen", "decke", "spiel", "livestream" };
std::string hiddenAnswer;
int hangmanPaintPhase = 0;
unsigned int randomWordNumber = 0;

void hangmanPaint()
{

	hangmanPaintPhase++;

	if (hangmanPaintPhase == 1)
	{
		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "//" << std::endl << std::endl << std::endl;
	}
	else if (hangmanPaintPhase == 2)
	{
		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "//\\\\" << std::endl << std::endl << std::endl;
	}
	else if (hangmanPaintPhase == 3)
	{
		std::cout << std::endl << std::endl << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << "//\\\\" << std::endl << std::endl << std::endl;
	}
	else if (hangmanPaintPhase == 4)
	{
		std::cout << std::endl << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << "//\\\\" << std::endl << std::endl << std::endl;
	}
	else if (hangmanPaintPhase == 5)
	{
		std::cout << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << "//\\\\" << std::endl << std::endl << std::endl;
	}
	else if (hangmanPaintPhase == 6)
	{
		std::cout << " =======" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << "//\\\\" << std::endl << std::endl << std::endl;
	}
	else if (hangmanPaintPhase == 7)
	{
		std::cout << " =======" << std::endl;
		std::cout << " ||/" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << "//\\\\" << std::endl << std::endl << std::endl;
	}
	else if (hangmanPaintPhase == 8)
	{
		std::cout << " =======" << std::endl;
		std::cout << " ||/   |" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << "//\\\\" << std::endl << std::endl << std::endl;
	}
	else if (hangmanPaintPhase == 9)
	{
		std::cout << " =======" << std::endl;
		std::cout << " ||/   |" << std::endl;
		std::cout << " ||    o" << std::endl;
		std::cout << " ||" << std::endl;
		std::cout << "//\\\\" << std::endl << std::endl << std::endl;
	}
	else if (hangmanPaintPhase == 10)
	{
		std::cout << " =======" << std::endl;
		std::cout << " ||/   |" << std::endl;
		std::cout << " ||    o" << std::endl;
		std::cout << " ||    X" << std::endl;
		std::cout << "//\\\\" << std::endl << std::endl << std::endl;

	}
}


void randomWordGeneration() {
	std::random_device wordSeed;
	const uint_least32_t seed = wordSeed();
	std::mt19937 generator(seed);
	std::uniform_int_distribution< uint_least32_t > distribution(0, randomWord.size());
	randomWordNumber = distribution(generator);
}

void newGame()
{
	std::string inputNewGame;
	do
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Neuer Spiel ? [y/n] " << std::endl;
		std::getline(std::cin, inputNewGame);

		if (inputNewGame == "y" || inputNewGame == "Y")
		{
			system("CLS");
			hiddenAnswer.clear();
			randomWordNumber = 0;
			main();
		}
		else if (inputNewGame == "n" || inputNewGame == "N")
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Das Programm beendet sich nun." << std::endl;
			break;
		}
		else
		{
			std::cout << "Es tut mir leid aber die Eingabe war ungültig" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	} while (inputNewGame != "n" || inputNewGame != "N");
}

void hiddeWord()
{
	char underscore = '_';
	for (unsigned int i = 0; i <= randomWord[randomWordNumber].length() - 1; i++)
	{
		hiddenAnswer.insert(i, "*");
	}
}


int main()
{
	char inputGuess;
	randomWordGeneration();
	hiddeWord();


	do
	{
		int saveBool = 0;
		bool drawHangman = false;
		std::cout << hiddenAnswer << std::endl;
		std::cout << std::endl << std::endl;
		std::cin >> inputGuess;
		std::cout << std::endl;




		for (unsigned int i = 0; i <= randomWord[randomWordNumber].length(); i++)
		{

			if (inputGuess == randomWord[randomWordNumber][i])
			{
				drawHangman = false;
				hiddenAnswer[i] = inputGuess;
				saveBool++;
			}
			else if (inputGuess != randomWord[randomWordNumber][i] && saveBool < 1)
			{
				drawHangman = true;
			}
			if (hiddenAnswer == randomWord[randomWordNumber])
			{
				std::cout << "Herzlichen Glückwunsch,Sie haben gewonnen !!!" << std::endl;
				newGame();
			}

		}




		if (drawHangman == true)
		{
			system("CLS");
			hangmanPaint();
		}


	} while (hangmanPaintPhase != 10);
	{
		std::cout << "Game Over, " << "correct Answer was " << randomWord[randomWordNumber] << std::endl;
		newGame();
	}

	system("PAUSE");
	return 0;
}