/*
 * releasedate.cpp
 *
 *  Created on: 07-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#include "../include/releasedate.h"

namespace MovieDB {
ReleaseDate::ReleaseDate() : m_date(0), m_month(0), m_year(0) {}

ReleaseDate::ReleaseDate(int date, int month, int year)
    : m_date(date), m_month(month), m_year(year) {}

ReleaseDate::ReleaseDate(const ReleaseDate& other) {
  this->m_date = other.m_date;
  this->m_month = other.m_month;
  this->m_year = other.m_year;
}

ReleaseDate& ReleaseDate::operator=(const ReleaseDate& other) {
  if (*this == other) return *this;
  this->m_date = other.m_date;
  this->m_month = other.m_month;
  this->m_year = other.m_year;
  return *this;
}

ReleaseDate::ReleaseDate(ReleaseDate&& other) {
  this->m_date = std::move(other.m_date);
  this->m_month = std::move(other.m_month);
  this->m_year = std::move(other.m_year);
}

ReleaseDate& ReleaseDate::operator=(ReleaseDate&& other) {
  if (*this == other) return *this;
  this->m_date = std::move(other.m_date);
  this->m_month = std::move(other.m_month);
  this->m_year = std::move(other.m_year);
  return *this;
}

void ReleaseDate::setDate(const int date) { this->m_date = date; }

void ReleaseDate::setMonth(const int month) { this->m_month = month; }

void ReleaseDate::setYear(const int year) { this->m_year = year; }

const int ReleaseDate::getDate() const { return this->m_date; }

const int ReleaseDate::getMonth() const { return this->m_month; }

const int ReleaseDate::getYear() const { return this->m_year; }

bool ReleaseDate::operator==(const ReleaseDate& other) {
  return (this->m_date == other.m_date && this->m_month == other.m_month &&
          this->m_year == other.m_year);
}

std::ostream& operator<<(std::ostream& out, const ReleaseDate& other) {
  out << other.getDate() << "-" << other.getMonth() << "-" << other.getYear();
  return out;
}
}
