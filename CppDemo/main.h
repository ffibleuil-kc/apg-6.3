/*******************************************************************************
  Version 6.3
  APG - an ABNF Parser Generator
  Copyright (C) 2012 Coast to Coast Research, Inc.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see
  <http://www.gnu.org/licenses/old-licenses/gpl-2.0.html>
  or write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

  author:  Lowell D. Thomas
  email:   info@coasttocoastresearch.com
  website: http://www.coasttocoastresearch.com
*******************************************************************************/

#ifndef MAIN_H_
#define MAIN_H_

#include "Apg.h"
#include "ApgUtilities.h"
#include "CppDemo.h"
#include <iostream>
using namespace std;

#define CPPASSERT(cond, msg) if(!(cond)){vTerminalAlertMsg(__LINE__, __FILE__, (msg));}

#endif /* MAIN_H_ */
