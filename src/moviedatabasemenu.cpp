/*
 * main.cpp
 *
 *  Created on: 19-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#include "../include/moviedatabasemenu.h"

namespace MovieDB {

bool validateInput(const std::string& string) {
  return std::any_of(string.begin(), string.end(), ::isdigit);
}

int validateUserInput(std::istream& input, int&& number) {
  int num;
  input.clear();
  input.ignore();
  std::cout << "You can only enter numbers.\n";
  std::cout << "Enter a number.\n";
  input >> num;
  number = num;
  return number;
}

void validateUserInput(std::istream& input, std::string& name) {
  while (validateInput(name)) {
    std::cout << "Name must not contain  digits\n";
    input.ignore();
    std::getline(input, name);
  }

  while (name.length() < 4) {
    std::cout << "Name must have minimum 4 characters\n";
    input.ignore();
    std::getline(input, name);
  }
}

MovieDBMenu::MovieDBMenu() {}

int MovieDBMenu::getUserChoice() {
  long int choice;
  std::cout << "\n";
  std::cout << "Enter your choice\n";
  std::cout << "0.Exit\n";
  std::cout << "1.Add movie\n";
  std::cout << "2.Remove Movie By Id\n";
  std::cout << "3.Remove Movie By Title\n";
  std::cout << "4.Find Movies By Title\n";
  std::cout << "5.Find Movies By Hero Or Heroine\n";
  std::cout << "6.Find Movies By Director\n";
  std::cout << "7.Find Movies By Language\n";
  std::cout << "8.Find Movies By Year\n";
  std::cin >> choice;
  while (std::cin.fail()) choice = validateUserInput(std::cin, choice);
  return choice;
}

void MovieDBMenu::performMovieDBOperations() {
  std::string movieTitle, actor, actress, director, producer, language, villain,
      comedian, supportingActor, supportingActress, genre, name;
  long int day, month, year, hour, min, second, choice;
  do {
    choice = getUserChoice();
    switch (choice) {
      case EXIT:
        exit(0);
        break;
      case ADD_MOVIE:
        std::cout << "Enter title of the movie\n";
        std::cin.ignore();
        std::getline(std::cin, movieTitle);
        std::cout << "Enter lead actor's name\n";
        std::getline(std::cin, actor);
        validateUserInput(std::cin, actor);
        std::cout << "Enter lead actress name\n";
        std::getline(std::cin, actress);
        validateUserInput(std::cin, actress);
        std::cout << "Enter director's name\n";
        std::getline(std::cin, director);
        validateUserInput(std::cin, director);
        std::cout << "Enter producer's name\n";
        std::getline(std::cin, producer);
        validateUserInput(std::cin, producer);
        std::cout << "Enter language\n";
        std::getline(std::cin, language);
        validateUserInput(std::cin, language);
        std::cout << "Enter villain's name\n";
        std::getline(std::cin, villain);
        validateUserInput(std::cin, villain);
        std::cout << "Enter comedian's name\n";
        std::getline(std::cin, comedian);
        validateUserInput(std::cin, comedian);
        std::cout << "Enter supporting actor's name\n";
        std::getline(std::cin, supportingActor);
        validateUserInput(std::cin, supportingActor);
        std::cout << "Enter supporting actress name\n";
        std::getline(std::cin, supportingActress);
        validateUserInput(std::cin, supportingActress);
        std::cout << "Genre\n";
        std::getline(std::cin, genre);
        validateUserInput(std::cin, genre);
        std::cout << "Enter Release Date\n";
        std::cin >> day;
        while (std::cin.fail()) {
          validateUserInput(std::cin, day);
        }
        while (day < 0 || day > 31) {
          std::cout << "Day must be in between 0 to 31\n";
          std::cin >> day;
        }
        std::cout << "Enter Release Month\n";
        std::cin >> month;

        while (std::cin.fail()) {
          validateUserInput(std::cin, month);
        }
        while (month < 0 || month > 12) {
          std::cout << "Month must be in between 1 to 12\n";
          std::cin >> month;
        }
        std::cout << "Enter Release Year\n";
        std::cin >> year;
        while (std::cin.fail()) {
          validateUserInput(std::cin, year);
        }
        while (year < 1996 || year > 2020) {
          std::cout << "Year must be in between 1996 to 2020\n";
          std::cin >> year;
        }
        std::cout << "Enter movie duration\n";
        std::cout << "Movie Time (Hours)\n";
        std::cin >> hour;
        while (std::cin.fail()) {
          validateUserInput(std::cin, hour);
        }
        while (hour < 0 || hour > 4) {
          std::cout << "Hours must be in between 0 to 4\n";
          std::cin >> hour;
        }
        std::cout << "Movie Time(Mins)\n";
        std::cin >> min;
        while (std::cin.fail()) {
          validateUserInput(std::cin, min);
        }
        while (min < 0 || min > 59) {
          std::cout << "Mins must be in between 0 to 59\n";
          std::cin >> min;
        }

        std::cout << "Movie Time(Seconds)\n";
        std::cin >> second;
        while (std::cin.fail()) {
          validateUserInput(std::cin, second);
        }
        while (second < 0 || second > 59) {
          std::cout << "Seconds must be in between 0 to 59\n";
          std::cin >> second;
        }

        std::cout << movieController->addMovie(
                         movieTitle, actor, actress, language, day, month, year,
                         villain, producer, director, comedian, supportingActor,
                         supportingActress, genre, hour, min, second)
                  << "\n";
        break;
      case REMOVE_MOVIEBYID:
        long int id;
        std::cout << "Enter id of the movie that you want to remove\n";
        std::cin >> id;
        while (std::cin.fail()) {
          validateUserInput(std::cin, id);
        }
        std::cout << movieController->removeMovie<int>(id) << "\n";

        break;

      case REMOVE_MOVIEBYTITLE: {
        std::string title;
        std::cout << "Enter title of the movie that you want to remove\n";
        std::cin.ignore();
        std::getline(std::cin, title);
        std::cout << movieController->removeMovie<std::string>(title) << "\n";
        break;
      }

      case FIND_MOVIEBYTITLE: {
        std::string title;
        std::cout << "Enter title of the movie that you want to search\n ";
        std::cin.ignore();
        std::getline(std::cin, title);
        if (!movieCollection.empty())
          movieCollection.erase(movieCollection.begin(), movieCollection.end());
        movieCollection = movieController->findMoviesByTitle(title);
        if (movieCollection.empty()) {
          std::cout << "Not found\n";
        }
        for (auto movie : movieCollection) std::cout << *movie.get();
        break;
      }
      case FIND_MOVIEBYHEROORHEROINE: {
        std::string actorName;
        std::cout << "Enter name of hero or heroine that you want to search\n ";
        std::cin.ignore();
        std::getline(std::cin, actorName);
        validateUserInput(std::cin, actorName);
        if (!movieCollection.empty())
          movieCollection.erase(movieCollection.begin(), movieCollection.end());
        movieCollection = movieController->findMoviesByHeroOrHeroine(actorName);
        if (movieCollection.empty()) std::cout << "Not found\n";
        for (auto movie : movieCollection) std::cout << *movie.get();
        break;
      }
      case FIND_MOVIEBYDIRECTOR: {
        std::string movieDirector;
        std::cout
            << "Enter name of director whose movies you want to search\n ";
        std::cin.ignore();
        std::getline(std::cin, movieDirector);
        validateUserInput(std::cin, movieDirector);
        if (!movieCollection.empty())
          movieCollection.erase(movieCollection.begin(), movieCollection.end());
        movieCollection = movieController->findMoviesByDirector(movieDirector);
        if (movieCollection.empty()) std::cout << "Not found\n";
        for (auto movie : movieCollection) std::cout << *movie.get();
        break;
      }
      case FIND_MOVIEBYLANGUAGE: {
        std::string movieLanguage;
        std::cout << "Enter  the language in which you want to search movie\n ";
        std::cin >> movieLanguage;
        validateUserInput(std::cin, movieLanguage);
        if (!movieCollection.empty())
          movieCollection.erase(movieCollection.begin(), movieCollection.end());
        movieCollection = movieController->findMoviesByLanguage(movieLanguage);
        if (movieCollection.empty()) std::cout << "Not found\n";
        for (auto movie : movieCollection) std::cout << *movie.get();
        break;
      }

      case FIND_MOVIEBYYEAR: {
        long int startYear, endYear;
        std::cout
            << "Enter duration in which you want to search for the movie\n ";
        std::cout << "Enter starting year\n";
        std::cin >> startYear;
        while (!std::cin) {
          validateUserInput(std::cin, startYear);
        }
        while (startYear < 1960 || startYear > 2020) {
          std::cout << "Years must be in between 1960 and 2020\n";
          std::cin >> startYear;
        }
        std::cout << "Enter end year\n";
        std::cin >> endYear;
        while (!std::cin) {
          validateUserInput(std::cin, endYear);
        }
        while (endYear < 1960 || endYear > 2020) {
          std::cout << "Years must be in between 1960 and 2020\n";
          std::cin >> endYear;
        }
        if (!movieCollection.empty())
          movieCollection.erase(movieCollection.begin(), movieCollection.end());
        movieCollection = movieController->findMoviesByYear(startYear, endYear);
        if (movieCollection.empty()) std::cout << "Not found\n";
        for (auto movie : movieCollection) std::cout << *movie.get();
        break;
      }
      default:
        std::cout << "Enter choice between 0 to 8\n";
        break;
    }
  }

  while (true);
}
}
