/*
 * main.cpp
 *
 *  Created on: 19-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#ifndef _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_MOVIEDATABASEMENU_H_
#define _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_MOVIEDATABASEMENU_H_
#include <algorithm>
#include <future>
#include <string>
#include <thread>
#include <vector>

#include "../moviecontroller/moviecontroller.h"
#include "movie.h"

namespace MovieDB {

using MovieCollection = std::vector<Movie_Shared_Ptr>;
using MovieControl = std::unique_ptr<MovieController>;
/*!
 * @brief method for checking whether string contains number or not
 * @param string
 * @return bool
 */
bool validateInput(const std::string& string);

/*!
 * @brief method for checking whether user is sending string instead of number
 * @param input
 * @param number
 * @return int
 */
int validateUserInput(std::istream& input, int&& number);

/*!
 * @brief method for checking whether user is sending digits instead of string
 * @param input
 * @param name
 */
void validateUserInput(std::istream& input, std::string& name);

enum Actions {
  EXIT,
  ADD_MOVIE,
  REMOVE_MOVIEBYID,
  REMOVE_MOVIEBYTITLE,
  FIND_MOVIEBYTITLE,
  FIND_MOVIEBYHEROORHEROINE,
  FIND_MOVIEBYDIRECTOR,
  FIND_MOVIEBYLANGUAGE,
  FIND_MOVIEBYYEAR
};

class MovieDBMenu {
  // std::vector because it is faster while inserting removing and searching
  // elements
  MovieCollection movieCollection;

  // std::unique_ptr because there cannot be two objects of movie controller
  // only the control
  // can be transferred from one object to another
  MovieControl movieController = std::make_unique<MovieController>();

 public:
  /*!
   * @brief default constructor
   */
  MovieDBMenu();

  /*!
   * @brief method for getting user's choice
   * @return int
   */

  int getUserChoice();
  /*!
   * @brief method for performing database operations
   */

  void performMovieDBOperations();
};
}
#endif  // _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_MOVIEDATABASEMENU_H_
