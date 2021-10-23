/*
 * moviedatabase.h
 *
 *  Created on: 09-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#ifndef _HOME_KPIT_MOVIEDB_MOVIEDB_DATABASE_MOVIEDATABASE_H_
#define _HOME_KPIT_MOVIEDB_MOVIEDB_DATABASE_MOVIEDATABASE_H_

#include <memory>
#include <thread>
#include <unordered_map>

#include "imoviedatabase.h"

namespace MovieDB {

class MovieDatabase : public IMovieDatabase {
  Movie_Container m_MovieContainer;  // std::shared_ptr is used so that Movie
  // object can be copied while finding movies

 public:
  /*!
   * @brief default constructor
   */
  MovieDatabase() = default;

  /*!
   * @brief parameterized constructor
   * @param container
   */
  MovieDatabase(Movie_Container container);

  /*!
   * @brief copy constructor
   * @param other
   */

  MovieDatabase(const MovieDatabase& other);

  /*!
   * @brief assignment operator
   * @param other
   * @return MovieDatabase&
   */

  MovieDatabase& operator=(const MovieDatabase& other);

  /*!
   * @brief move constructor
   * @param other
   */

  MovieDatabase(MovieDatabase&& other);

  /*!
   * @brief Move Assignment Operator
   * @param other
   * @return MovieDatabase&
   */
  MovieDatabase& operator=(MovieDatabase&& other);

  /*!
   * @brief method for adding movie
   * @param movie
   * @return string
   */

  const std::string addMovie(Movie&& movie) override;

  /*!
   * @brief method for removing id
   * @param id
   * @return string
   */
  const std::string removeMovie(int id) override;

  /*!
   * @brief method for removing movie by title
   * @param title
   * @return string
   */
  const std::string removeMovie(std::string& title) override;

  /*!
   * @brief method for finding Movies By Title
   * @param title
   * @return vector
   */

  const Vector_Movie findMoviesByTitle(std::string& title) override;

  /*!
   * @brief method for finding Movies By HeroOr Heroine
   * @param name
   * @return vector
   */
  const Vector_Movie findMoviesByHeroOrHeroine(std::string& name) override;

  /*!
   * @brief method for finding Movies By Director
   * @param director
   * @return vector
   */

  const Vector_Movie findMoviesByDirector(std::string& director) override;

  /*!
   * @brief method for finding Movies By Language
   * @param language
   * @return vector
   */

  const Vector_Movie findMoviesByLanguage(std::string& language) override;

  /*!
   * @brief method for finding Movies By Year
   * @param startYear
   * @param endYear
   * @return vector
   */

  const Vector_Movie findMoviesByYear(int startYear, int endYear) override;
  /*!
   * @brief method for comparing two movie database objects
   * @param other
   * @return bool
   */

  bool operator==(const MovieDatabase& other);

  /*!
   * @brief virtual destructor of MovieDatabase class
   */

  virtual ~MovieDatabase() {}
};
}
#endif  // _HOME_KPIT_MOVIEDB_MOVIEDB_DATABASE_MOVIEDATABASE_H_
