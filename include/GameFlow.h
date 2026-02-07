#pragma once
#include "GameState.h"
#include <vector>
#include <string>


// we use a struct here because the data in it has no functionality?
struct Score
{
	std::string playerName;
	int score;
	std::string date;
};

class GameFlow
{
private:
	GameState currentState;
	std::vector<std::string> wordList;
	std::vector<std::string> credits;
	std::vector<std::string> recentWords;
	std::vector<Score> highScores;
	std::string targetWord;
	int currentScore;
	std::string playerName;
	std::string dataPath; // we're saving scores, player names, and date to .txt files

	// handlers for State
	void handleMainMenu();
	void handleNewGame();
	void handleHighScores();
	void handleCredits();
	void handleSaveScore();

	// handlers for helper methods
	void loadWordList();
	void loadCredits();
	void loadHighScores();
	void saveHighScores();
	void selectDailyWord();
	void provideFeedback(const std::string& guess);

	// file path helper
	std::string getDataPath(const std::string& filename);

public:
	GameFlow();
	void run();
	GameState getCurrentState() const { return currentState; }
};