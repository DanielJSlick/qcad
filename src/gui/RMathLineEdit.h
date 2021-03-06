/**
 * Copyright (c) 2011-2013 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */

#ifndef RMATHLINEEDIT_H_
#define RMATHLINEEDIT_H_

#include "gui_global.h"

#include <QMetaType>
#include <QLabel>
#include <QLineEdit>
#include <QtDesigner/QDesignerExportWidget>

#include "RMath.h"

/**
 * \scriptable
 * \ingroup gui
 */
class QCADGUI_EXPORT RMathLineEdit: public QLineEdit {

Q_OBJECT
Q_PROPERTY(bool angle READ isAngle WRITE setAngle);
//Q_PROPERTY(double defaultValue READ getDefaultValue WRITE setDefaultValue);
//Q_PROPERTY(int defaultUnit READ getDefaultUnit WRITE setDefaultUnit);
//Q_PROPERTY(RS::Unit defaultUnit READ getDefaultUnit WRITE setDefaultUnit);
//Q_ENUMS(RS::Unit);

public:
    RMathLineEdit(QWidget* parent = NULL);

    bool isAngle() const {
       return angle;
    }
    void setAngle(bool on) {
       angle = on;
    }
    bool isInteger() const {
        return integer;
    }
    void setInteger(bool on) {
        integer = on;
    }

    void setValue(double v, int precision=6);
    double getValue();
    QString getError();
    void clearError();

    bool isValid() {
        return !RMath::isNaN(value);
    }

    void setToolTip(const QString& toolTip);

    /*
    double getDefaultValue() {
        return defaultValue;
    }
    void setDefaultValue(double v) {
        defaultValue = v;
    }
    */

    //void setDefaultUnit(int defaultUnit);
    //int getDefaultUnit();

protected:
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void keyReleaseEvent(QKeyEvent* event);

public slots:
    void slotTextChanged(const QString& text);
    void slotTextEdited(const QString& text);

signals:
    void valueChanged(double value, const QString& error);

private:
    QPalette oriPalette;
    bool angle;
    bool integer;
    double value;
    //RS::Unit defaultUnit;
    QString error;
    QString originalToolTip;
    bool noEmit;
    //double defaultValue;
//    QLabel* resultTip;
};

Q_DECLARE_METATYPE(RMathLineEdit*)

#endif
