/*
 * movie.h
 *
 *  Created on: 07-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#ifndef _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_MOVIE_H_
#define _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_MOVIE_H_

#include <iostream>
#include <memory>
#include <string>

#include "movieduration.h"
#include "releasedate.h"
#include "supportingcast.h"

namespace MovieDB {
class Movie {
  std::string m_MovieTitle;
  std::string m_LeadActor;
  std::string m_LeadActress;
  std::string m_Language;
  ReleaseDate m_ReleaseDate;
  std::string m_Villain;
  std::string m_Producer;
  std::string m_Director;
  SupportingCast m_SupportingCast;
  std::string m_Genre;
  MovieDuration m_MovieDuration;

 public:
  static int m_MovieId;
  /*!
   * @brief default constructor
   */
  Movie() = delete;  // movie object must contain some properties at the time of
                     // creation

  /*!
   * @brief parameterized constructor
   * @param title
   * @param leadactor
   * @param leadactress
   * @param language
   * @param releasedate
   * @param villain
   * @param producer
   * @param director
   * @param supportingcast
   * @param genre
   * @param movieduration
   */
  Movie(std::string title, std::string leadactor, std::string leadactress,
        std::string language, ReleaseDate&& releasedate, std::string villain,
        std::string producer, std::string director,
        SupportingCast&& supportingcast, std::string genre,
        MovieDuration&& movieduration);

  /*!
   * @brief copy constructor
   * @param other
   */

  Movie(const Movie& other) = delete;  // each movie object must be unique
                                       /*!
                                        * @brief assignment operator
                                        * @param other
                                        * @return Movie&
                                        */

  Movie& operator=(const Movie& other) =
      delete;  // each movie object must be unique

  /*!
   * @brief move constructor
   * @param other
   */
  Movie(Movie&& other);

  /*!
   * @brief move assignment
   * @param other
   * @return Movie&
   */

  Movie& operator=(Movie&& other);

  /*!
   * @brief method for comparing two movie objects
   * @param other
   * @return bool
   */
  bool operator==(const Movie& other);

  /*!
   * @brief method for getting director
   * @return string
   */
  const std::string& getDirector() const;

  /*!
   * @brief method for setting director
   * @param director
   */
  void setDirector(const std::string& director);

  /*!
   * @brief method to get language
   * @return string
   */
  const std::string& getLanguage() const;

  /*!
   * @brief method to set language
   * @param language
   */
  void setLanguage(const std::string& language);

  /*!
   * @brief method to get lead actor
   * @return string
   */
  const std::string& getLeadActor() const;

  /*!
   * @brief method to set lead actor
   * @param leadActor
   */
  void setLeadActor(const std::string& leadActor);

  /*!
   * @brief method to get lead actress
   * @return string
   */
  const std::string& getLeadActress() const;

  /*!
   * @brief method to set lead actress
   * @param leadActress
   */
  void setLeadActress(const std::string& leadActress);

  /*!
   * @brief method to get movie id
   * @return int
   */

  int getMovieId() const;

  /*!
   *@brief method to get movie title
   * @return string
   */
  const std::string& getMovieTitle() const;

  /*!
   * @brief method to set movie title
   * @param movieTitle
   */
  void setMovieTitle(const std::string& movieTitle);

  /*!
   * @brief method to get movie producer
   * @return
   */

  const std::string& getProducer() const;

  /*!
   * @brief method to set movie producer
   * @param producer
   */
  void setProducer(const std::string& producer);

  /*!
   * @brief method to get Release Date
   * @return ReleaseDate&
   */

  const ReleaseDate& getReleaseDate() const;

  /*!
   * @brief method to set release date
   * @param releaseDate
   */
  void setReleaseDate(const ReleaseDate& releaseDate);

  /*!
   * @brief method to get supporting cats
   * @return SupportingCast&
   */

  const SupportingCast& getSupportingCast() const;

  /*!
   * @brief method to set supporting cast
   * @param supportingCast
   */
  void setSupportingCast(const SupportingCast& supportingCast);

  /*!
   * @brief method to get villain
   * @return string
   */
  const std::string& getVillain() const;

  /*!
   * @brief method to set villain
   * @param villain
   */
  void setVillain(const std::string& villain);

  /*!
   * @brief method to get movie duration
   * @return
   */
  const MovieDuration& getMovieDuration() const;

  /*!
   * @brief method to set movie duration
   * @param movieDuration
   */
  void setMovieDuration(const MovieDuration& movieDuration);

  /*!
   * @brief method to get genre
   * @return string
   */
  const std::string& getGenre() const;

  /*!
   * @brief method to set genre
   * @param genre
   */
  void setGenre(const std::string& genre);

  /*!
   * @brief <<operator overload
   * @param out
   * @param other
   * @return
   */

  friend std::ostream& operator<<(std::ostream& out, const Movie& other);

  /*!
   * destructor
   */
  virtual ~Movie() {}
};
}
#endif  // _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_MOVIE_H_
