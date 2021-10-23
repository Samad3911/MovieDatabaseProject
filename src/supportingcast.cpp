/*
 * supportingcast.cpp
 *
 *  Created on: 08-Jan-2020
 *      Author: AbdulSamad
 *      Copyright [2020] <AbdulSamad>
 */

#include "../include/supportingcast.h"

namespace MovieDB {
SupportingCast::SupportingCast()
    : m_SupportingActor(" "), m_SupportingActress(" "), m_Comedian(" ") {}

SupportingCast::SupportingCast(std::string supportingActor,
                               std::string supportingActress,
                               std::string comedian)
    : m_SupportingActor(supportingActor),
      m_SupportingActress(supportingActress),
      m_Comedian(comedian) {}

SupportingCast::SupportingCast(const SupportingCast& other) {
  this->m_Comedian = other.m_Comedian;
  this->m_SupportingActor = other.m_SupportingActor;
  this->m_SupportingActress = other.m_SupportingActress;
}

SupportingCast& SupportingCast::operator=(const SupportingCast& other) {
  if (*this == other) return *this;
  this->m_Comedian = other.m_Comedian;
  this->m_SupportingActor = other.m_SupportingActor;
  this->m_SupportingActress = other.m_SupportingActress;
  return *this;
}

SupportingCast::SupportingCast(SupportingCast&& other) {
  this->m_Comedian = std::move(other.m_Comedian);
  this->m_SupportingActor = std::move(other.m_SupportingActor);
  this->m_SupportingActress = std::move(other.m_SupportingActress);
}

SupportingCast& SupportingCast::operator=(SupportingCast&& other) {
  if (*this == other) return *this;
  this->m_Comedian = std::move(other.m_Comedian);
  this->m_SupportingActor = std::move(other.m_SupportingActor);
  this->m_SupportingActress = std::move(other.m_SupportingActress);
  return *this;
}

const std::string& SupportingCast::getComedian() const { return m_Comedian; }

const std::string& SupportingCast::getSupportingActor() const {
  return m_SupportingActor;
}

const std::string& SupportingCast::getSupportingActress() const {
  return m_SupportingActress;
}

bool SupportingCast::operator==(const SupportingCast& other) {
  return (this->m_Comedian == other.m_Comedian &&
          this->m_SupportingActor == other.m_SupportingActor &&
          this->m_SupportingActress == other.m_SupportingActress);
}
}
