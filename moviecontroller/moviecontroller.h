/*
 * moviecontroller.h
 *
 *  Created on: 13-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#ifndef _HOME_KPIT_MOVIEDB_MOVIEDB_MOVIECONTROLLER_MOVIECONTROLLER_H_
#define _HOME_KPIT_MOVIEDB_MOVIEDB_MOVIECONTROLLER_MOVIECONTROLLER_H_

#include "../database/moviedatabase.h"

namespace MovieDB {
class MovieController {
  IMovieDatabase* m_Moviedatabase;

 public:
  /*!
   * @brief default constructor
   */
  MovieController();
  /*!
   * @brief parameterized constructor
   * @param moviedatabase
   */

  MovieController(IMovieDatabase* moviedatabase);

  /*!
   * @brief copy constructor
   * @param other
   */
  MovieController(const MovieController& other) = delete;

  /*!
   * @brief assignment operator
   * @param other
   * @return MovieController&
   */
  MovieController& operator=(const MovieController& other) = delete;

  /*!
   * @brief move constructor
   * @param other
   */
  MovieController(MovieController&& other);
  /*!
   * @brief move constructor
   * @param other
   * @return
   */
  MovieController& operator=(MovieController&& other);

  /*!
   * @brief method for adding movie
   * @param title
   * @param leadactor
   * @param leadactress
   * @param language
   * @param day
   * @param month
   * @param year
   * @param villain
   * @param producer
   * @param director
   * @param comedian
   * @param supportingActor
   * @param supportingActress
   * @param genre
   * @param hour
   * @param min
   * @param sec
   * @return string
   */
  const std::string addMovie(std::string title, std::string leadactor,
                             std::string leadactress, std::string language,
                             int day, int month, int year, std::string villain,
                             std::string producer, std::string director,
                             std::string comedian, std::string supportingActor,
                             std::string supportingActress, std::string genre,
                             int hour, int min, int sec);

  /*!
   * @brief method for removingMovieByIdAndTitle
   * @param movie
   * @return string
   */
  template <typename T>
  const std::string removeMovie(T movie) {
    if (m_Moviedatabase != nullptr) return m_Moviedatabase->removeMovie(movie);
    return "Movie doesn't gets removed";
  }

  /*!
   * @brief method for finding movies by title
   * @param title
   * @return vector
   */
  const std::vector<Movie_Shared_Ptr> findMoviesByTitle(std::string& title);

  /*!
   * @brief method for finding movies by hero or heroine
   * @param name
   * @return
   */
  const std::vector<Movie_Shared_Ptr> findMoviesByHeroOrHeroine(
      std::string& name);

  /*!
   * @brief method for finding movies by director
   * @param director
   * @return vector
   */
  const std::vector<Movie_Shared_Ptr> findMoviesByDirector(
      std::string& director);

  /*!
   * @brief method for finding movies by language
   * @param language
   * @return vector
   */
  const std::vector<Movie_Shared_Ptr> findMoviesByLanguage(
      std::string& language);

  /*!
   * @brief method for finding movies by year
   * @param startYear
   * @param endYear
   * @return vector
   */
  const std::vector<Movie_Shared_Ptr> findMoviesByYear(int startYear,
                                                       int endYear);
  /*!
   * @brief operator == overloaded
   * @param other
   * @return bool
   */

  bool operator==(const MovieController& other);

  /*!
   * destructor
   */
  ~MovieController() {
    delete m_Moviedatabase;
    m_Moviedatabase = nullptr;
  }
};
}

#endif  //_HOME_KPIT_MOVIEDB_MOVIEDB_MOVIECONTROLLER_MOVIECONTROLLER_H_
