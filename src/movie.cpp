/*
 * movie.cpp
 *
 *  Created on: 08-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#include "../include/movie.h"

namespace MovieDB {
int Movie::m_MovieId = 1000;
Movie::Movie(std::string title, std::string leadactor, std::string leadactress,
             std::string language, ReleaseDate&& releasedate,
             std::string villain, std::string producer, std::string director,
             SupportingCast&& supportingcast, std::string genre,
             MovieDuration&& movieduration)
    : m_MovieTitle(title),
      m_LeadActor(leadactor),
      m_LeadActress(leadactress),
      m_Language(language),
      m_ReleaseDate(std::move(releasedate)),
      m_Villain(villain),
      m_Producer(producer),
      m_Director(director),
      m_SupportingCast(std::move(supportingcast)),
      m_Genre(genre),
      m_MovieDuration(std::move(movieduration)) {}

Movie::Movie(Movie&& other) {
  this->m_MovieId = std::move(other.m_MovieId);
  this->m_MovieTitle = std::move(other.m_MovieTitle);
  this->m_LeadActor = std::move(other.m_LeadActor);
  this->m_LeadActress = std::move(other.m_LeadActress);
  this->m_Language = std::move(other.m_Language);
  this->m_ReleaseDate = std::move(other.m_ReleaseDate);
  this->m_Villain = std::move(other.m_Villain);
  this->m_Producer = std::move(other.m_Producer);
  this->m_Director = std::move(other.m_Director);
  this->m_SupportingCast = std::move(other.m_SupportingCast);
  this->m_Genre = std::move(other.m_Genre);
  this->m_MovieDuration = std::move(other.m_MovieDuration);
}

Movie& Movie::operator=(Movie&& other) {
  if (*this == other) return *this;
  this->m_MovieId = std::move(other.m_MovieId);
  this->m_MovieTitle = std::move(other.m_MovieTitle);
  this->m_LeadActor = std::move(other.m_LeadActor);
  this->m_LeadActress = std::move(other.m_LeadActress);
  this->m_Language = std::move(other.m_Language);
  this->m_ReleaseDate = std::move(other.m_ReleaseDate);
  this->m_Villain = std::move(other.m_Villain);
  this->m_Producer = std::move(other.m_Producer);
  this->m_Director = std::move(other.m_Director);
  this->m_SupportingCast = std::move(other.m_SupportingCast);
  this->m_Genre = std::move(other.m_Genre);
  this->m_MovieDuration = std::move(other.m_MovieDuration);
  return *this;
}

const std::string& Movie::getDirector() const { return m_Director; }

void Movie::setDirector(const std::string& director) { m_Director = director; }

const std::string& Movie::getLanguage() const { return m_Language; }

void Movie::setLanguage(const std::string& language) { m_Language = language; }

const std::string& Movie::getLeadActor() const { return m_LeadActor; }

void Movie::setLeadActor(const std::string& leadActor) {
  m_LeadActor = leadActor;
}

const std::string& Movie::getLeadActress() const { return m_LeadActress; }

void Movie::setLeadActress(const std::string& leadActress) {
  m_LeadActress = leadActress;
}

int Movie::getMovieId() const { return m_MovieId; }

const std::string& Movie::getMovieTitle() const { return m_MovieTitle; }

void Movie::setMovieTitle(const std::string& movieTitle) {
  m_MovieTitle = movieTitle;
}

const std::string& Movie::getProducer() const { return m_Producer; }

void Movie::setProducer(const std::string& producer) { m_Producer = producer; }

const ReleaseDate& Movie::getReleaseDate() const { return m_ReleaseDate; }

void Movie::setReleaseDate(const ReleaseDate& releaseDate) {
  m_ReleaseDate = releaseDate;
}

const SupportingCast& Movie::getSupportingCast() const {
  return m_SupportingCast;
}

void Movie::setSupportingCast(const SupportingCast& supportingCast) {
  m_SupportingCast = supportingCast;
}

const std::string& Movie::getVillain() const { return m_Villain; }

void Movie::setVillain(const std::string& villain) { m_Villain = villain; }

const MovieDuration& Movie::getMovieDuration() const { return m_MovieDuration; }

void Movie::setMovieDuration(const MovieDuration& movieDuration) {
  m_MovieDuration = movieDuration;
}

const std::string& Movie::getGenre() const { return m_Genre; }

void Movie::setGenre(const std::string& genre) { m_Genre = genre; }

bool Movie::operator==(const Movie& other) {
  return (this->m_MovieId == other.m_MovieId &&
          this->m_MovieTitle == other.m_MovieTitle &&
          this->m_LeadActor == other.m_LeadActor &&
          this->m_LeadActress == other.m_LeadActress &&
          this->m_Language == other.m_Language &&
          this->m_ReleaseDate == other.m_ReleaseDate &&
          this->m_Villain == other.m_Villain &&
          this->m_Producer == other.m_Producer &&
          this->m_Director == other.m_Director &&
          this->m_SupportingCast == other.m_SupportingCast &&
          this->m_Genre == other.m_Genre);
}

std::ostream& operator<<(std::ostream& out, const Movie& other) {
  out << "Movie Id:" << other.getMovieId() << "\n";
  out << "Title: " << other.getMovieTitle() << "\n";
  out << "Hero: " << other.getLeadActor() << "\n";
  out << "Heroine: " << other.getLeadActress() << "\n";
  out << "Language: " << other.getLanguage() << "\n";
  out << "Director: " << other.getDirector() << "\n";
  out << "Producer: " << other.getProducer() << "\n";
  out << "ReleaseDate: " << other.getReleaseDate() << "\n";
  out << "MovieDuration: " << other.getMovieDuration() << "\n";
  out << "\n";
  out << "---------------------------------------------------------"
      << "\n ";

  return out;
}
}
