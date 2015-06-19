/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 Urban Bruhin
 * http://librepcb.org/
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

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/

#include <QtCore>
#include <QtWidgets>
#include "schematiclayer.h"

/*****************************************************************************************
 *  Constructors / Destructor
 ****************************************************************************************/

SchematicLayer::SchematicLayer(uint id) :
    QObject(0), mId(id)
{
    switch (mId)
    {
        case Grid:
            mName = tr("Grid");
            mColor = Qt::white;                 // background
            mColorHighlighted = Qt::lightGray;  // lines
            break;

        case OriginCrosses:
            mName = tr("Origin Crosses");
            mColor = QColor(0, 0, 0, 50);
            mColorHighlighted = QColor(0, 0, 0, 80);
            break;

        case SymbolOutlines:
            mName = tr("Symbol Outlines");
            mColor = Qt::darkRed;
            mColorHighlighted = Qt::red;
            break;

        case SymbolGrabAreas:
            mName = tr("Symbol Grab Areas");
            mColor = QColor(255, 255, 0, 30);
            mColorHighlighted = QColor(255, 255, 0, 50);
            break;

        case SymbolPinCircles:
            mName = tr("Symbol Pin Circles");
            mColor = Qt::green;             // optional pin
            mColorHighlighted = Qt::red;    // required pin
            break;

        case SymbolPinNames:
            mName = tr("Symbol Pin Names");
            mColor = QColor(64, 64, 64, 255);
            mColorHighlighted = Qt::gray;
            break;

        case ComponentNames:
            mName = tr("Component Names");
            mColor = QColor(32, 32, 32, 255);
            mColorHighlighted = Qt::darkGray;
            break;

        case ComponentValues:
            mName = tr("Component Values");
            mColor = QColor(80, 80, 80, 255);
            mColorHighlighted = Qt::gray;
            break;

        case NetLabels:
            mName = tr("Net Labels");
            mColor = Qt::darkGreen;
            mColorHighlighted = Qt::green;
            break;

        case Nets:
            mName = tr("Nets");
            mColor = Qt::darkGreen;
            mColorHighlighted = Qt::green;
            break;

        case Busses:
            mName = tr("Busses");
            mColor = Qt::darkBlue;
            mColorHighlighted = Qt::blue;
            break;

        default:
            if (mId >= UserDefinedBaseId)
            {
                // TODO: this is a user-defined layer...
            }
            else
            {
                qCritical() << "invalid schematic layer id:" << mId;
            }
            break;
    }
}

SchematicLayer::~SchematicLayer()
{
}

/*****************************************************************************************
 *  Getters
 ****************************************************************************************/

const QColor& SchematicLayer::getColor(bool highlighted) const
{
    return highlighted ? mColorHighlighted : mColor;
}

/*****************************************************************************************
 *  Static Methods
 ****************************************************************************************/

QList<SchematicLayer::LayerID> SchematicLayer::getAllLayerIDs() noexcept
{
    QList<LayerID> IDs;
    IDs << SchematicLayer::Grid
        << SchematicLayer::OriginCrosses    << SchematicLayer::SymbolOutlines
        << SchematicLayer::SymbolPinCircles << SchematicLayer::SymbolPinNames
        << SchematicLayer::ComponentNames   << SchematicLayer::ComponentValues
        << SchematicLayer::Nets             << SchematicLayer::Busses
        << SchematicLayer::SymbolGrabAreas  << SchematicLayer::NetLabels;
    return IDs;
}

/*****************************************************************************************
 *  End of File
 ****************************************************************************************/
