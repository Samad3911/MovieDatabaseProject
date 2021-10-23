/*
 * moviedatabase.cpp
 *
 *  Created on: 09-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#include <algorithm>

#include "moviedatabase.h"

namespace MovieDB {

std::string conversionIntoUpperCase(std::string temp) {
  for (auto& t : temp) t = toupper(t);
  return temp;
}

bool searchElement(std::string first, std::string second) {
  if (conversionIntoUpperCase(first) == conversionIntoUpperCase(second))
    return true;
  else if (conversionIntoUpperCase(first).find(
               conversionIntoUpperCase(second)) != std::string::npos)
    return true;
  else
    return false;
}

MovieDatabase::MovieDatabase(Movie_Container container)
    : m_MovieContainer(container) {}

MovieDatabase::MovieDatabase(const MovieDatabase& other) {
  this->m_MovieContainer = other.m_MovieContainer;
}

MovieDatabase& MovieDatabase::operator=(const MovieDatabase& other) {
  if (*this == other) return *this;
  this->m_MovieContainer.clear();
  this->m_MovieContainer = other.m_MovieContainer;
  return *this;
}

MovieDatabase::MovieDatabase(MovieDatabase&& other) {
  this->m_MovieContainer = std::move(other.m_MovieContainer);
}

MovieDatabase& MovieDatabase::operator=(MovieDatabase&& other) {
  if (*this == other) return *this;
  this->m_MovieContainer.clear();
  this->m_MovieContainer = std::move(other.m_MovieContainer);
  return *this;
}

const std::string MovieDatabase::addMovie(Movie&& movie) {
  Movie_Shared_Ptr moviePtr = std::make_shared<Movie>(std::move(movie));
  if (m_MovieContainer.empty())
    m_MovieContainer.emplace(++Movie::m_MovieId, moviePtr);
  else {
    for (Temporary_Container temporaryContainer : m_MovieContainer) {
      if (temporaryContainer.second->getMovieTitle() ==
              moviePtr->getMovieTitle() &&
          temporaryContainer.second->getLeadActor() ==
              moviePtr->getLeadActor() &&
          temporaryContainer.second->getLeadActress() ==
              moviePtr->getLeadActress())
        return "Movie Already Exist";
    }
    m_MovieContainer.emplace(++Movie::m_MovieId, moviePtr);
  }
  return "Movie gets stored successfully\n";
}

const std::string MovieDatabase::removeMovie(int id) {
  if (m_MovieContainer.empty())
    return "Database doesn't contain any movie add some movies first\n ";
  auto search = m_MovieContainer.find(id);
  if (search != m_MovieContainer.end()) {
    m_MovieContainer.erase(search);
    return "Movie deleted successfully\n";
  }
  return "Movie with id: " + std::to_string(id) + " doesn't exist";
}

const std::string MovieDatabase::removeMovie(std::string& title) {
  if (m_MovieContainer.empty()) return "Database doesn't contain any movie\n ";
  auto search = std::find_if(
      m_MovieContainer.begin(), m_MovieContainer.end(),
      [title](Temporary_Container temporaryContainer) {
        return searchElement(temporaryContainer.second->getMovieTitle(), title);
      });

  if (search != m_MovieContainer.end()) {
    m_MovieContainer.erase(search);
    return "Movie deleted successfully\n";
  }
  return "Movie with title " + title + " doesn't exist\n ";
}

const Vector_Movie MovieDatabase::findMoviesByTitle(std::string& title) {
  Vector_Movie movieCollection;
  for (Temporary_Container temporaryContainer : m_MovieContainer) {
    if (searchElement(temporaryContainer.second->getMovieTitle(), title))
      movieCollection.push_back(temporaryContainer.second);
  }
  return movieCollection;
}

const Vector_Movie MovieDatabase::findMoviesByHeroOrHeroine(std::string& name) {
  Vector_Movie movieCollection;
  for (Temporary_Container temporaryContainer : m_MovieContainer) {
    if (searchElement(temporaryContainer.second->getLeadActor(), name) ||
        searchElement(temporaryContainer.second->getLeadActress(), name))
      movieCollection.push_back(temporaryContainer.second);
  }
  return movieCollection;
}

const Vector_Movie MovieDatabase::findMoviesByDirector(std::string& director) {
  Vector_Movie movieCollection;
  for (Temporary_Container temporaryContainer : m_MovieContainer) {
    if (searchElement(temporaryContainer.second->getDirector(), director))
      movieCollection.push_back(temporaryContainer.second);
  }
  return movieCollection;
}

const Vector_Movie MovieDatabase::findMoviesByLanguage(std::string& language) {
  Vector_Movie movieCollection;
  for (Temporary_Container temporaryContainer : m_MovieContainer) {
    if (conversionIntoUpperCase(temporaryContainer.second->getLanguage()) ==
        conversionIntoUpperCase(language))
      movieCollection.push_back(temporaryContainer.second);
  }
  return movieCollection;
}

const Vector_Movie MovieDatabase::findMoviesByYear(int startYear, int endYear) {
  Vector_Movie movieCollection;
  for (Temporary_Container temporaryContainer : m_MovieContainer) {
    if (temporaryContainer.second->getReleaseDate().getYear() >= startYear &&
        temporaryContainer.second->getReleaseDate().getYear() <= endYear)
      movieCollection.push_back(temporaryContainer.second);
  }
  return movieCollection;
}

bool MovieDatabase::operator==(const MovieDatabase& other) {
  return (this->m_MovieContainer == other.m_MovieContainer);
}
}
