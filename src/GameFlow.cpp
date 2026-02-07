 #include "GameFlow.h"
#include "terminal_colors.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <iomanip>
#include <algorithm>


GameFlow::GameFlow() : currentState(GameState::MAIN_MENU), currentScore(0), dataPath("data/")
{
    loadWordList();
    loadCredits();
    loadHighScores();
    selectDailyWord();
}



void GameFlow::run()
{
    // our loop for game state
    while (currentState != GameState::EXIT_GAME)
    {
        switch (currentState)
        {
        case GameState::MAIN_MENU:
            handleMainMenu();
            break;
        case GameState::NEW_GAME:
            handleNewGame();
            break;
        case GameState::HIGH_SCORES:
            handleHighScores();
            break;
        case GameState::ROLL_CREDITS:
            handleCredits();
            break;
        case GameState::SAVE_SCORE:
            handleSaveScore();
            break;
        case GameState::EXIT_GAME:
            break;
        }
    }
    std::cout << "Thanks for playing" << std::endl;
}

std::string GameFlow::getDataPath(const std::string & filename)
{
    return dataPath + filename;
}



void GameFlow::handleMainMenu()
{
    std::cout << PURPLE << " ========================== " <<  RESET << std::endl;
    std::cout << PURPLE << "|         Word Hunt        |" << RESET <<  std::endl;
    std::cout << PURPLE << " ========================== " <<  RESET << std::endl;
    std::cout << PURPLE << "|      [1] NEW GAME        |" << RESET <<  std::endl;
    std::cout << PURPLE << "|      [2] HIGH SCORES     |" <<  RESET << std::endl;
    std::cout << PURPLE << "|      [3] CREDITS         |" << RESET <<  std::endl;
    std::cout << PURPLE << "|      [4] EXIT            |" << RESET << std::endl;
    std::cout << PURPLE << " ========================== " << RESET << std::endl;

    std::cout << LIGHT_PINK << " Choose an option:  " <<  RESET << std::endl;

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    // here we go, switch statement to controll outcome of menu options
    switch (choice)
    {
        case 1:
            currentState = GameState::NEW_GAME;
            break;
        case 2: 
            currentState = GameState::HIGH_SCORES;
            break;
        case 3:
            currentState = GameState::ROLL_CREDITS;
            break;
        case 4:
            currentState = GameState::EXIT_GAME;
            break;
        default:
            std::cout << LIGHT_RED << "Invalid choice. Try again." << RESET << std::endl;
            break;
    }
}

void GameFlow::handleNewGame()
{
    std::cout << PURPLE << " ========================== " << RESET << std::endl;
    std::cout << PURPLE << "|         NEW GAME         |" << RESET << std::endl;
    std::cout << PURPLE << " ========================== " << RESET << std::endl;
    std::cout << LIGHT_PINK << " Enter your name:  " << RESET << std::endl;

    currentScore = 0;
    int attempts = 0;

    std::cout << LIGHT_PINK << "Guess the 5-letter word! you have " << attempts << ": " << RESET << std::endl;
    for (int i = 0; i < attempts; i++)
    {
        std::cout << "Attempt " << (i + 1) << "/" << attempts << ": " << std::endl;
        std::string guess;
        std::getline(std::cin, guess);

        std::transform(guess.begin(), guess.end(), guess.begin(), ::toupper);

        if (guess.length() != 5)
        {
            std::cout << LIGHT_RED << "Please enter a 5-letter word!" << RESET << std::endl;
            i--;
            continue;
        }

        if(guess == targetWord)
        {
            currentScore = (attempts - i) * 100;
            std::cout << FOREST_GREEN << "🎉 Correct! the word was: " << targetWord << RESET << std::endl;
            std::cout << FOREST_GREEN << "Your score: " << currentScore << RESET << std::endl;

            std::cout << LIGHT_PINK << "Do you want to save your score? (y/n): " << RESET << std::endl;
            char save;
            std::cin >> save;
            std::cin.ignore();

            currentState = (save == 'y' || save == 'Y') ? GameState::SAVE_SCORE : GameState::MAIN_MENU;
            return;
        }
        else {
            provideFeedback(guess);
        }
    }
    std::cout << BRIGHT_ORANGE << "Game Over! The word was: " << targetWord << RESET << std::endl;
    currentState = GameState::MAIN_MENU;
}

void GameFlow::provideFeedback(const std::string& guess)
{
    std::cout << "Feedback: " << std::endl;
    for (size_t i = 0; i < guess.length(); i++)
    {
        if (guess[i] == targetWord[i])
        {
            std::cout << LIGHT_YELLOW << "[" << guess[i] << "] " << RESET << std::endl;
        }
        else if (targetWord.find(guess[i]) != std::string::npos) {
            std::cout << LIGHT_YELLOW << "(" << guess[i] << ") " << RESET << std::endl;
        }
        else {
            std::cout << LIGHT_YELLOW << " " << guess[i] << "   " << RESET << std::endl;
        }
    }
    std::cout << "[] = correct, () = wrong position" << std::endl;
}

void GameFlow::handleHighScores()
{
    std::cout << PURPLE << " ========================== " << RESET << std::endl;
    std::cout << PURPLE << "|         HIGH SCORES      |" << RESET << std::endl;
    std::cout << PURPLE << " ========================== " << RESET << std::endl;

    if (highScores.empty())
    {
        std::cout << LIGHT_PINK << "No high scores yet!" << RESET << std::endl;
    }
    else {
        std::sort(highScores.begin(), highScores.end(), [](const Score& a, const Score& b) {return a.score > b.score; });
        std::cout << std::left << std::setw(20) << "Player" 
                               << std::setw(10) << "Score" 
                               << std::setw(15) << "Date" << std::endl;

        std::cout << std::string(45, '-') << std::endl;

        for (size_t i = 0; i < std::min(highScores.size(), size_t(10)); i++)
        {
            std::cout << std::left << std::setw(20) << highScores[i].playerName 
                                   << std::setw(10) << highScores[i].score 
                                   << std::setw(15) << highScores[i].date << std::endl;
        }
    }

    std::cout << "Press Enter to return to menu..." << std::endl;
    std:: cin.get();
    currentState = GameState::MAIN_MENU;
}


void GameFlow::handleCredits()
{
    std::cout << PURPLE << " ========================== " << RESET << std::endl;
    std::cout << PURPLE << "|         CREDITS          |" << RESET << std::endl;
    std::cout << PURPLE << " ========================== " << RESET << std::endl;
}

/*
    OH I FORGOT, IF YOU'RE WATCHING AND YOU'RE NOT SUBSCRIBED, PLEASE PLEASE DO SO!
    >>> If you want your name in the credits, type it in the chat <<<
*/