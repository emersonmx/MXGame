/**
 * Copyright 2012 Emerson Max de Medeiros Silva
 *
 * Author: Emerson Max de Medeiros Silva <emersonmx@gmail.com>
 *
 * This file is part of mxgame.
 *
 * mxgame is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mxgame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mxgame.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MXGAME_WINDOW_H
#define _MXGAME_WINDOW_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct mxgame_window_t mxgame_window;

mxgame_window* mxgame_create_window(int width, int height, int depth);
void mxgame_destroy_window(mxgame_window* window);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MXGAME_WINDOW_H */

