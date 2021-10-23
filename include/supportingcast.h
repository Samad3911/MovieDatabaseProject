/*
 * supportingcast.h
 *
 *  Created on: 07-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#ifndef _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_SUPPORTINGCAST_H_
#define _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_SUPPORTINGCAST_H_

#include <string>

namespace MovieDB {
class SupportingCast {
  std::string m_SupportingActor;
  std::string m_SupportingActress;
  std::string m_Comedian;

 public:
  /*!
   * @brief default constructor
   */
  SupportingCast();
  /*!
   * @brief parameterized constructor
   * @param supportingActor
   * @param supportingActress
   * @param comedian
   */
  SupportingCast(std::string supportingActor, std::string supportingActress,
                 std::string comedian);

  /*!
   * @brief copy constructor
   * @param other
   */
  SupportingCast(const SupportingCast& other);

  /*!
   * @brief assignment operator
   * @param other
   * @return
   */

  SupportingCast& operator=(const SupportingCast& other);

  /*!
   * @brief move constructor
   * @param other
   */
  SupportingCast(SupportingCast&& other);

  /*!
   * @brief move assignment operator
   * @param other
   * @return SupportingCast&
   */
  SupportingCast& operator=(SupportingCast&& other);

  /*!
   * @brief method to get comedian
   * @return string
   */
  const std::string& getComedian() const;

  /*!
   * @brief method to get supporting actor
   * @return string
   */
  const std::string& getSupportingActor() const;

  /*!
   * @brief method to get supporting actress
   * @return string
   */
  const std::string& getSupportingActress() const;

  /*!
   * @brief method to compare two Supporting Cast objects
   * @param other
   * @return string
   */
  bool operator==(const SupportingCast& other);

  /*!
   * @brief destructor
   */
  virtual ~SupportingCast() {}
};
}
#endif  // _HOME_KPIT_MOVIEDB_MOVIEDB_INCLUDE_SUPPORTINGCAST_H_
