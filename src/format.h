/*
 * libkeepass - KeePass key database importer/exporter
 * Copyright (C) 2014 Christian Kindahl
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <sstream>

class Format {
 private:
  std::stringstream str_;

  Format(const Format& rhs) = delete;
  Format& operator=(const Format& rhs) = delete;

 public:
  Format() = default;

  template <typename T>
  Format& operator<<(const T& val) {
    str_ << val;
    return *this;
  }

  operator std::string() const {
    return str_.str();
  }
};
