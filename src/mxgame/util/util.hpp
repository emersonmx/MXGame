/*
  Copyright (C) 2013 Emerson Max de Medeiros Silva

  This file is part of mxgame.

  mxgame is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  mxgame is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with mxgame.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MXGAME_UTIL_UTIL_HPP_
#define MXGAME_UTIL_UTIL_HPP_

#ifdef DEBUG
#define MXGAME_UTIL_MAIN(NEW_APPLICATION)                                      \
int main() {                                                                   \
    int error_code;                                                            \
    mxgame::application::Application* application = NEW_APPLICATION;           \
    error_code = application->Run();                                           \
    printf("Error code: %d\n", error_code);                                    \
    delete application;                                                        \
    return error_code;                                                         \
}
#else
#define MXGAME_UTIL_MAIN(NEW_APPLICATION)                                      \
int main() {                                                                   \
    int error_code;                                                            \
    mxgame::application::Application* application = NEW_APPLICATION;           \
    error_code = application->Run();                                           \
    delete application;                                                        \
    return error_code;                                                         \
}
#endif /* DEBUG */

#endif /* MXGAME_UTIL_UTIL_HPP_ */

