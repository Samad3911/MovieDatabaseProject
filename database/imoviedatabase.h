/*
 * imoviedatabase.h
 *
 *  Created on: 09-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#ifndef _HOME_KPIT_MOVIEDB_MOVIEDB_DATABASE_IMOVIEDATABASE_H_
#define _HOME_KPIT_MOVIEDB_MOVIEDB_DATABASE_IMOVIEDATABASE_H_

#include <string>
#include <vector>

#include "../include/movie.h"

namespace MovieDB {

using Movie_Shared_Ptr = std::shared_ptr<Movie>;
using Movie_Container = std::unordered_map<int, Movie_Shared_Ptr>;
using Temporary_Container = std::pair<int, Movie_Shared_Ptr>;
using Vector_Movie = std::vector<Movie_Shared_Ptr>;
class IMovieDatabase {
 public:
  /*!
   * @brief method for adding movie
   * @param movie
   * @return string
   */
  virtual const std::string addMovie(Movie&& movie) = 0;

  /*!
   * @brief method for removing movie by id
   * @param id
   * @return string
   */
  virtual const std::string removeMovie(int id) = 0;

  /*!
   * @brief method for removing movie by title
   * @param title
   * @return string
   */
  virtual const std::string removeMovie(std::string& title) = 0;

  /*!
   * @brief method for finding movies by title
   * @param title
   * @return vector
   */

  virtual const Vector_Movie findMoviesByTitle(std::string& title) = 0;

  /*!
   * @brief method for finding movies by hero or heroine
   * @param name
   * @return vector
   */
  virtual const Vector_Movie findMoviesByHeroOrHeroine(std::string& name) = 0;

  /*!
   * @brief method for finding movies by director
   * @param director
   * @return vector
   */
  virtual const Vector_Movie findMoviesByDirector(std::string& director) = 0;

  /*!
   * @brief method for finding movies by language
   * @param language
   * @return vector
   */

  virtual const Vector_Movie findMoviesByLanguage(std::string& language) = 0;
  /*!
   * @brief method for finding movies by year
   * @param startYear
   * @param endYear
   * @return string
   */
  virtual const Vector_Movie findMoviesByYear(int startYear, int endYear) = 0;

  /*!
   * @brief virtual destructor
   */
  virtual ~IMovieDatabase() {}
};
}
#endif  //  _HOME_KPIT_MOVIEDB_MOVIEDB_DATABASE_IMOVIEDATABASE_H_
