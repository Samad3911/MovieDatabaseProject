/*
 * movieduration.h
 *
 *  Created on: 08-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#ifndef _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_MOVIEDURATION_H_
#define _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_MOVIEDURATION_H_

#include <iostream>
#include <utility>

namespace MovieDB {
class MovieDuration {
  int m_Hours;
  int m_Minutes;
  int m_Seconds;

 public:
  /*!
   * @brief default constructor
   */
  MovieDuration();

  /*!
   * @brief parameterized constructor
   * @param hours
   * @param minutes
   * @param seconds
   */
  MovieDuration(int hours, int minutes, int seconds);

  /*!
   * @brief copy constructor
   * @param other
   */
  MovieDuration(const MovieDuration& other);

  /*!
   * @brief assignment operator
   * @param other
   * @return MovieDuration&
   */

  MovieDuration& operator=(const MovieDuration& other);

  /*!
   * @brief move constructor
   * @param other
   */

  MovieDuration(MovieDuration&& other);

  /*!
   * @brief move assignment operator
   * @param other
   * @return MovieDuration&
   */

  MovieDuration& operator=(MovieDuration&& other);

  /*!
   * @brief method to get no. of hours
   * @return int
   */
  int getHours() const;

  /*!
   * @brief method to set no. of hours
   * @param hours
   */

  void setHours(int hours);

  /*!
   * @brief method to get no. of minutes
   * @return int
   */
  int getMinutes() const;

  /*!
   * @brief method to set no. of minutes
   * @param minutes
   */
  void setMinutes(int minutes);

  /*!
   * @brief method to get no. of seconds
   * @return int
   */

  int getSeconds() const;

  /*!
   * @brief method to set no. of seconds
   * @param seconds
   */
  void setSeconds(int seconds);

  /*!
   * @brief method for comparing two movieduration onjects
   * @param other
   * @return bool
   */
  bool operator==(const MovieDuration& other);

  /*!
   * @brief operator << overloaded method
   * @param out
   * @param other
   * @return out
   */
  friend std::ostream& operator<<(std::ostream& out,
                                  const MovieDuration& other);

  /*!
   * @brief destructor
   */
  ~MovieDuration() {}
};
}
#endif  // _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_MOVIEDURATION_H_
