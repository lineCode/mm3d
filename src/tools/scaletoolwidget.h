/*  Misfit Model 3D
 * 
 *  Copyright (c) 2004-2007 Kevin Worcester
 * 
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, 
 *  USA.
 *
 *  See the COPYING file for full license text.
 */


#ifndef __SCALETOOLWIDGET_H
#define __SCALETOOLWIDGET_H

#include "mq3macro.h"
#include "mq3compat.h"
//Added by qt3to4:
#include <Q3VBoxLayout>
#include <Q3HBoxLayout>
#include <QLabel>

class Q3MainWindow;

class Q3VBoxLayout;
class Q3HBoxLayout;

#ifdef HAVE_QT4
#define Q3GroupBox Q3GroupBox
#endif
class Q3GroupBox;
class QComboBox;
class QLabel;

enum ScaleProportion_e
{
   ST_ScaleFree         = 0,
   ST_ScaleProportion2D = 1,
   ST_ScaleProportion3D = 2,
};
typedef enum ScaleProportion_e ScaleProportionE;

enum _ScalePoint_e
{
   ST_ScalePointCenter  = 0,
   ST_ScalePointFar     = 1,
};
typedef enum _ScalePoint_e ScalePointE;

class ScaleToolWidget : public Q3DockWindow
{
   Q_OBJECT

   public:
      class Observer
      {
         public:
            virtual ~Observer() {};
            virtual void setProportionValue( int newValue ) = 0;
            virtual void setPointValue( int newValue ) = 0;
      };


      ScaleToolWidget( Observer * observer, QWidget * parent );
      virtual ~ScaleToolWidget();

   public slots:
      void proportionValueChanged( int newValue );
      void pointValueChanged( int newValue );

   protected:
      Observer    * m_observer;

      Q3BoxLayout  * m_layout;

      Q3GroupBox   * m_groupBox;
      QLabel      * m_proportionLabel;
      QComboBox   * m_proportionValue;
      QLabel      * m_pointLabel;
      QComboBox   * m_pointValue;
};

#endif // __SCALETOOLWIDGET_H
