/**
 ******************************************************************************
 *
 * @file       tile.cpp
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2012.
 * @brief
 * @see        The GNU Public License (GPL) Version 3
 * @defgroup   OPMapWidget
 * @{
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "tile.h"


namespace internals {
Tile::Tile(int zoom, Point pos)
{
    this->zoom = zoom;
    this->pos  = pos;
}
void Tile::Clear()
{
#ifdef DEBUG_TILE
    qDebug() << "Tile:Clear Overlays";
#endif // DEBUG_TILE
    mutex.lock();
    Overlays.clear();
    mutex.unlock();
}
Tile::Tile() : zoom(0), pos(0, 0)
{}
Tile & Tile::operator =(const Tile &cSource)
{
    this->zoom = cSource.zoom;
    this->pos  = cSource.pos;
    return *this;
}
}
