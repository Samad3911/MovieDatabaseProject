/*
 * releasedate.h
 *
 *  Created on: 07-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#ifndef _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_RELEASEDATE_H_
#define _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_RELEASEDATE_H_

#include <iostream>
#include <utility>

namespace MovieDB {
class ReleaseDate {
  int m_date;
  int m_month;
  int m_year;

 public:
  /*!
   * @brief default constructor
   */
  ReleaseDate();

  /*!
   * @brief parameterized constructor
   * @param date
   * @param month
   * @param year
   */
  ReleaseDate(int date, int month, int year);

  /*!
   * @brief copy constructor
   * @param other
   */

  ReleaseDate(const ReleaseDate& other);

  /*!
   * @brief assignment operator
   * @param other
   * @return ReleaseDate&
   */
  ReleaseDate& operator=(const ReleaseDate& other);

  /*!
   * @brief move constructor
   * @param other
   */
  ReleaseDate(ReleaseDate&& other);

  /*!
   * @brief move assignment operator
   * @param other
   * @return ReleaseDate&
   */
  ReleaseDate& operator=(ReleaseDate&& other);

  /*!
   * @brief overloaded == operator
   * @param other
   * @return bool
   */

  bool operator==(const ReleaseDate& other);

  /*!
   * @brief method to set date
   * @param date
   */
  void setDate(int date);

  /*!
   * @brief method to get date
   * @return int
   */
  const int getDate() const;

  /*!
   * @brief method to set month
   * @param month
   */
  void setMonth(int month);

  /*!
   * @brief method to get month
   * @return int
   */
  const int getMonth() const;

  /*!
   * @brief method to set year
   * @param year
   */
  void setYear(int year);
  /*!
   * @brief method to get year
   * @return int
   */

  const int getYear() const;

  /*!
   * @brief method for overloading << operator
   * @param out
   * @param other
   * @return ostream
   */

  friend std::ostream& operator<<(std::ostream& out, const ReleaseDate& other);

  /*!
   * destructor
   */
  virtual ~ReleaseDate() {}
};
}
#endif  // _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_RELEASEDATE_H_
