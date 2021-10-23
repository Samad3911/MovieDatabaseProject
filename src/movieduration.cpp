/*
 * movieduration.cpp
 *
 *  Created on: 08-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#include "../include/movieduration.h"

namespace MovieDB {
MovieDuration::MovieDuration() : m_Hours(0), m_Minutes(0), m_Seconds(0) {}

MovieDuration::MovieDuration(int hours, int minutes, int seconds)
    : m_Hours(hours), m_Minutes(minutes), m_Seconds(seconds) {}

MovieDuration::MovieDuration(const MovieDuration& other) {
  this->m_Hours = other.m_Hours;
  this->m_Minutes = other.m_Minutes;
  this->m_Seconds = other.m_Seconds;
}

MovieDuration& MovieDuration::operator=(const MovieDuration& other) {
  if (*this == other) return *this;
  this->m_Hours = other.m_Hours;
  this->m_Minutes = other.m_Minutes;
  this->m_Seconds = other.m_Seconds;
  return *this;
}

MovieDuration::MovieDuration(MovieDuration&& other) {
  this->m_Hours = std::move(other.m_Hours);
  this->m_Minutes = std::move(other.m_Minutes);
  this->m_Seconds = std::move(other.m_Seconds);
}

MovieDuration& MovieDuration::operator=(MovieDuration&& other) {
  if (*this == other) return *this;
  this->m_Hours = std::move(other.m_Hours);
  this->m_Minutes = std::move(other.m_Minutes);
  this->m_Seconds = std::move(other.m_Seconds);
  return *this;
}

int MovieDuration::getHours() const { return m_Hours; }

void MovieDuration::setHours(int hours) { m_Hours = hours; }

int MovieDuration::getMinutes() const { return m_Minutes; }

void MovieDuration::setMinutes(int minutes) { m_Minutes = minutes; }

int MovieDuration::getSeconds() const { return m_Seconds; }

void MovieDuration::setSeconds(int seconds) { m_Seconds = seconds; }

bool MovieDuration::operator==(const MovieDuration& other) {
  return (this->m_Hours == other.m_Hours &&
          this->m_Minutes == other.m_Minutes &&
          this->m_Seconds == other.m_Seconds);
}

std::ostream& operator<<(std::ostream& out, const MovieDuration& other) {
  out << other.getHours() << "h"
      << " " << other.getMinutes() << "m";
  return out;
}
}
