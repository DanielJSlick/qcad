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
#include "RUnit.h"

#include <stdio.h>
#include <QObject>

#include "RDocument.h"
#include "RMath.h"
#include "RSettings.h"

/**
 * \return A presentable label for the given value. The number locale
 * is used to determine if the decimal point is a dot or a comma.
 * \see RSettings::getNumberLocale()
 */
QString RUnit::getLabel(double v, RDocument& document,
                        bool forceMaxPrecision, bool forceSuppressTrailingZeroes,
                        bool onlyPreciseResult) {

    if (fabs(v) < 1e-6) {
        v = 0.0;
    }

    return RUnit::formatLinear(v, document.getUnit(),
                document.getLinearFormat(),
                forceMaxPrecision ? 8 : document.getLinearPrecision(),
                false,
                document.showLeadingZeroes(),
                forceSuppressTrailingZeroes ? false : document.showTrailingZeroes(),
                onlyPreciseResult);

    //QLocale locale = RSettings::getNumberLocale();
    //return locale.toString(v, 'g', 6);
}

double RUnit::convert(double value, RS::Unit source, RS::Unit dest) {
    if (source==dest) {
        return value;
    }

    return value * getFactorToM(source) / getFactorToM(dest);
}

RVector RUnit::convert(const RVector& value, RS::Unit source, RS::Unit dest) {
    if (source==dest) {
        return value;
    }

    return value * convert(1.0, source, dest);
}

double RUnit::getFactorToM(RS::Unit unit) {
    switch (unit) {
    case RS::None:
        // none behaves like mm, e.g. for line widths:
        return 1.0 / 1000;
        break;
    case RS::Inch:
        return 25.4 / 1000;
        break;
    case RS::Foot:
        return 304.8 / 1000;
        break;
    case RS::Mile:
        return 1609344.0 / 1000;
        break;
    case RS::Millimeter:
        return 1.0 / 1000;
        break;
    case RS::Centimeter:
        return 10.0 / 1000;
        break;
    case RS::Meter:
        return 1000.0 / 1000;
        break;
    case RS::Kilometer:
        return 1000000.0 / 1000;
        break;
    case RS::Microinch:
        return 0.0000254 / 1000;
        break;
    case RS::Mil:
        return 0.0254 / 1000;
        break;
    case RS::Yard:
        return 914.4 / 1000;
        break;
    case RS::Angstrom:
        return 0.0000001 / 1000;
        break;
    case RS::Nanometer:
        return 0.000001 / 1000;
        break;
    case RS::Micron:
        return 0.001 / 1000;
        break;
    case RS::Decimeter:
        return 100.0 / 1000;
        break;
    case RS::Decameter:
        return 10000.0 / 1000;
        break;
    case RS::Hectometer:
        return 100000.0 / 1000;
        break;
    case RS::Gigameter:
        return 1000000000.0 / 1000;
        break;
    case RS::Astro:
        return 149600000000000.0 / 1000;
        break;
    case RS::Lightyear:
        return 9460731798000000000.0 / 1000;
        break;
    case RS::Parsec:
        return 30857000000000000000.0 / 1000;
        break;
    //case RS::Plu:
    //    return 0.025 / 1000;
    //    break;
    default:
        return 1.0;
        break;
    }
}

bool RUnit::isMetric(RS::Unit unit) {
    if (unit == RS::Inch ||
        unit == RS::Foot ||
        unit == RS::Mile ||
        unit == RS::Mil ||
        unit == RS::Yard) {

        return false;
    }
    return true;
}

/**
 * @return a short string representing the given unit (e.g. "mm")
 */
QString RUnit::unitToSymbol(RS::Unit unit) {
    QString ret = "";

    switch (unit) {
    case RS::None:
        ret = "";
        break;
    case RS::Inch:
        ret = "\"";
        break;
    case RS::Foot:
        ret = "'";
        break;
    case RS::Mile:
        ret = "mi";
        break;
    case RS::Millimeter:
        ret = "mm";
        break;
    case RS::Centimeter:
        ret = "cm";
        break;
    case RS::Meter:
        ret = "m";
        break;
    case RS::Kilometer:
        ret = "km";
        break;
    case RS::Microinch:
        ret = QString("%1\"").arg(QChar(0xB5));
        break;
    case RS::Mil:
        ret = "mil";
        break;
    case RS::Yard:
        ret = "yd";
        break;
    case RS::Angstrom:
        ret = "A";
        break;
    case RS::Nanometer:
        ret = "nm";
        break;
    case RS::Micron:
        ret = QString("%1m").arg(QChar(0xB5));
        break;
    case RS::Decimeter:
        ret = "dm";
        break;
    case RS::Decameter:
        ret = "dam";
        break;
    case RS::Hectometer:
        ret = "hm";
        break;
    case RS::Gigameter:
        ret = "Gm";
        break;
    case RS::Astro:
        ret = "astro";
        break;
    case RS::Lightyear:
        ret = "ly";
        break;
    case RS::Parsec:
        ret = "pc";
        break;
    //case RS::Plu:
    //    ret = "plu";
    //    break;

    default:
        ret = "";
        break;
    }

    return ret;
}

/**
 * @return a string representing the given unit (e.g. "Millimeter").
 *      translated if \c tr is true (the default).
 */
QString RUnit::unitToName(RS::Unit unit, bool tr) {
    QString ret = "";

    switch (unit) {
    case RS::None:
        ret = tr ? QObject::tr("None") : QString("None");
        break;
    case RS::Inch:
        ret = tr ? QObject::tr("Inch") : QString("Inch");
        break;
    case RS::Foot:
        ret = tr ? QObject::tr("Foot") : QString("Foot");
        break;
    case RS::Mile:
        ret = tr ? QObject::tr("Mile") : QString("Mile");
        break;
    case RS::Millimeter:
        ret = tr ? QObject::tr("Millimeter") : QString("Millimeter");
        break;
    case RS::Centimeter:
        ret = tr ? QObject::tr("Centimeter") : QString("Centimeter");
        break;
    case RS::Meter:
        ret = tr ? QObject::tr("Meter") : QString("Meter");
        break;
    case RS::Kilometer:
        ret = tr ? QObject::tr("Kilometer") : QString("Kilometer");
        break;
    case RS::Microinch:
        ret = tr ? QObject::tr("Microinch") : QString("Microinch");
        break;
    case RS::Mil:
        ret = tr ? QObject::tr("Mil") : QString("Mil");
        break;
    case RS::Yard:
        ret = tr ? QObject::tr("Yard") : QString("Yard");
        break;
    case RS::Angstrom:
        ret = tr ? QObject::tr("Angstrom") : QString("Angstrom");
        break;
    case RS::Nanometer:
        ret = tr ? QObject::tr("Nanometer") : QString("Nanometer");
        break;
    case RS::Micron:
        ret = tr ? QObject::tr("Micron") : QString("Micron");
        break;
    case RS::Decimeter:
        ret = tr ? QObject::tr("Decimeter") : QString("Decimeter");
        break;
    case RS::Decameter:
        ret = tr ? QObject::tr("Decameter") : QString("Decameter");
        break;
    case RS::Hectometer:
        ret = tr ? QObject::tr("Hectometer") : QString("Hectometer");
        break;
    case RS::Gigameter:
        ret = tr ? QObject::tr("Gigameter") : QString("Gigameter");
        break;
    case RS::Astro:
        ret = tr ? QObject::tr("Astro") : QString("Astro");
        break;
    case RS::Lightyear:
        ret = tr ? QObject::tr("Lightyear") : QString("Lightyear");
        break;
    case RS::Parsec:
        ret = tr ? QObject::tr("Parsec") : QString("Parsec");
        break;
    //case RS::Plu:
    //    ret = tr ? QObject::tr("Plu") : QString("Plu");
    //    break;

    default:
        ret = "";
        break;
    }

    return ret;
}


/**
 * Formats the given length in the given format.
 *
 * \param length The length in the current unit of the drawing.
 * \param format Format of the string.
 * \param prec Precision of the value (e.g. 0.001 or 1/128 = 0.0078125)
 & \param showUnit Append unit to the value.
 */
QString RUnit::formatLinear(double length, RS::Unit unit,
                            RS::LinearFormat format,
                            int prec, bool showUnit,
                            bool showLeadingZeroes, 
                            bool showTrailingZeroes,
                            bool onlyPreciseResult) {
    QString ret;

    // imperial display: show as fraction:
    switch (format) {
    case RS::Scientific:
        ret = formatScientific(length, unit, prec, showUnit, 
            showLeadingZeroes, showTrailingZeroes, onlyPreciseResult);
        break;

    case RS::Decimal:
        ret = formatDecimal(length, unit, prec, showUnit,
            showLeadingZeroes, showTrailingZeroes, onlyPreciseResult);
        break;

    case RS::Engineering:
        ret = formatEngineering(length, unit, prec, showUnit,
            showLeadingZeroes, showTrailingZeroes, onlyPreciseResult);
        break;

    case RS::Architectural:
    case RS::ArchitecturalStacked:
        ret = formatArchitectural(length, unit, prec, showUnit,
            showLeadingZeroes, showTrailingZeroes, onlyPreciseResult);
        break;

    case RS::Fractional:
    case RS::FractionalStacked:
        ret = formatFractional(length, unit, prec, showUnit,
            showLeadingZeroes, showTrailingZeroes, onlyPreciseResult);
        break;

    default:
        qWarning() << "RUnit::formatLinear: Unknown format";
        ret = "";
        break;
    }
    
    return ret;
}



/**
 * Formats the given length in scientific format (e.g. 2.5E7).
 *
 * \param length The length in the current unit of the drawing.
 * \param prec Precision of the value (e.g. 0.001 or 1/128 = 0.0078125)
 & \param showUnit Append unit to the value.
 */
QString RUnit::formatScientific(double length, RS::Unit unit,
                                int prec, bool showUnit,
                                bool /*showLeadingZeroes*/, bool /*showTrailingZeroes*/,
                                bool /*onlyPreciseResult*/) {
    QString ret;

    // negative prec crashes sprintf:
    if (prec<0) {
        prec = 0;
    }

    // unit appended to value (e.g. 'mm'):
    QString unitString = "";
    if (showUnit) {
        unitString = unitToSymbol(unit);
    }

    char format[128];
    sprintf(format, "%%.%dE%%s", prec);
    ret.sprintf(format, length, (const char*)unitString.toLatin1());
    
    return ret;
}



/**
 * Formats the given length in decimal (normal) format (e.g. 2.5).
 *
 * \param length The length in the current unit of the drawing.
 * \param prec Precision of the value (e.g. 0.001)
 & \param showUnit Append unit to the value.
 */
QString RUnit::formatDecimal(double length, RS::Unit unit,
                             int prec, bool showUnit,
                             bool showLeadingZeroes, bool showTrailingZeroes,
                             bool /*onlyPreciseResult*/) {

    QString ret;
    
    // unit appended to value (e.g. 'mm'):

    ret = doubleToString(length, prec,
            showLeadingZeroes, showTrailingZeroes);

    if(showUnit) {
        ret+=unitToSymbol(unit);
    }
    
    return ret;
}



/**
 * Formats the given length in engineering format (e.g. 5' 4.5").
 *
 * \param length The length in the current unit of the drawing.
 * \param prec Precision of the value (e.g. 0.001 or 1/128 = 0.0078125)
 & \param showUnit Append unit to the value.
 */
QString RUnit::formatEngineering(double length, RS::Unit unit,
                                 int prec, bool /*showUnit*/,
                                 bool /*showLeadingZeroes*/, bool /*showTrailingZeroes*/,
                                 bool /*onlyPreciseResult*/) {

    if (unit!=RS::Inch) {
        qWarning() << "RUnit::formatEngineering:"
                   << "Unit must be set to 'Inch' for engineering format";
        return "";
    }

    QString ret;

    bool sign = (length<0.0);
    int feet = (int)floor(fabs(length)/12);
    double inches = fabs(length) - feet*12;

    QString sInches = doubleToString(inches, prec);

    if (sInches=="12") {
        feet++;
        sInches="0";
    }

    if (feet!=0) {
        ret.sprintf("%d'-%s\"", feet, (const char*)sInches.toLatin1());
    } else {
        ret.sprintf("%s\"", (const char*)sInches.toLatin1());
    }

    if (sign) {
        ret = "-" + ret;
    }

    return ret;
}



/**
 * Formats the given length in architectural format (e.g. 5' 4 1/2").
 *
 * \param length The length in the current unit of the drawing.
 * \param prec Precision of the value (e.g. 0.001 or 1/128 = 0.0078125)
 & \param showUnit Append unit to the value.
 */
QString RUnit::formatArchitectural(double length, RS::Unit unit,
                                   int prec, bool showUnit,
                                   bool /*showLeadingZeroes*/, bool /*showTrailingZeroes*/,
                                   bool /*onlyPreciseResult*/) {
    if (unit!=RS::Inch) {
        qWarning() << "RUnit::formatArchitectural:"
                   << "Unit must be set to 'Inch' for architectural format";
        return "";
    }

    QString ret;
    bool neg = (length<0.0);

    int feet = (int)floor(fabs(length)/12);
    double inches = fabs(length) - feet*12;

    QString sInches = formatFractional(inches, RS::Inch, prec, showUnit);

    if (sInches=="12") {
        feet++;
        sInches = "0";
    }

    // suppress 0 feet:
    if (feet==0) {
        if (neg) {
            ret.sprintf("-%s\"", (const char*)sInches.toLatin1());
        } else {
            ret.sprintf("%s\"", (const char*)sInches.toLatin1());
        }
    }
    else {
        if (neg) {
            ret.sprintf("-%d'-%s\"", feet, (const char*)sInches.toLatin1());
        } else {
            ret.sprintf("%d'-%s\"", feet, (const char*)sInches.toLatin1());
        }
    }

    return ret;
}



/**
 * Formats the given length in fractional format (e.g. 3 1/64).
 *
 * \param length The length in the current unit of the drawing.
 * \param unit Should be inches.
 * \param prec Precision of the value (e.g. 0.001 or 1/128 = 0.0078125)
 & \param showUnit Append unit to the value.
 */
QString RUnit::formatFractional(double length, RS::Unit /*unit*/,
                                int prec, bool /*showUnit*/,
                                bool /*showLeadingZeroes*/, bool /*showTrailingZeroes*/,
                                bool onlyPreciseResult) {

    int num;            // number of complete inches (num' 7/128")
    int nominator;      // number of fractions (nominator/128)
    int denominator;    // (4/denominator)

    // sign:
    QString neg = "";
    if(length < 0) {
        neg = "-";
        length = fabs(length);
    }

    num = (int)floor(length);

    denominator = (int)RMath::pow(2, prec);
    nominator = RMath::mround((length-num)*denominator);


    // fraction rounds up to 1:
    if (nominator==denominator) {
        nominator=0;
        denominator=0;
        ++num;
    }

    // Simplify the fraction
    if (nominator!=0 && denominator!=0) {
        int gcd = RMath::getGcd(nominator, denominator);
        if (gcd!=0) {
            nominator = nominator / gcd;
            denominator = denominator / gcd;
        } else {
            qWarning() << "RUnit::formatFractional: invalid gcd";
            nominator = 0;
            denominator = 0;
        }
    }

    if (onlyPreciseResult) {
        double res = (double)num + (double)nominator / (double)denominator;
        if (!RMath::fuzzyCompare(res, length)) {
            return "";
        }
    }

    QString ret;

    if (num!=0 && nominator!=0 ) {
        ret.sprintf("%s%d %d/%d",
                    (const char*)neg.toLatin1(), num,
                    nominator, denominator);
    } else if(nominator!=0) {
        ret.sprintf("%s%d/%d",
                    (const char*)neg.toLatin1(),
                    nominator, denominator);
    } else if(num!=0) {
        ret.sprintf("%s%d",
                    (const char*)neg.toLatin1(),
                    num);
    } else {
        ret.sprintf("0");
    }

    return ret;
}





/**
 * Formats the given angle with the given format.
 *
 * \param angle The angle (always in rad).
 * \param format Format of the string.
 * \param prec Precision of the value (e.g. 0.001 or 1/128 = 0.0078125)
 *
 * \ret String with the formatted angle.
 */
QString RUnit::formatAngle(double angle, RS::AngleFormat format,
                           int prec,
                           bool showLeadingZeroes,
                           bool showTrailingZeroes) {

    QString ret;
    double value;

    switch (format) {
    case RS::DegreesDecimal:
    case RS::DegreesMinutesSeconds:
        value = RMath::rad2deg(angle);
        break;
    case RS::Radians:
        value = angle;
        break;
    case RS::Gradians:
        value = RMath::rad2gra(angle);
        break;
    default:
        qWarning() << "RUnit::formatAngle: Unknown Angle Unit";
        return "";
        break;
    }

    switch (format) {
    case RS::DegreesDecimal:
    case RS::Radians:
    case RS::Gradians:
        ret = doubleToString(value, prec, showLeadingZeroes, showTrailingZeroes);
        if (format==RS::DegreesDecimal)
            ret+=QChar(0xB0);
        if (format==RS::Radians)
            ret+="r";
        if (format==RS::Gradians)
            ret+="g";
        break;

    case RS::DegreesMinutesSeconds: {
            int vDegrees, vMinutes;
            double vSeconds;
            QString degrees, minutes, seconds;

            vDegrees = (int)floor(value);
            vMinutes = (int)floor((value - vDegrees) * 60.0);
            vSeconds = (value - vDegrees - (vMinutes/60.0)) * 3600.0;

            seconds = doubleToString(vSeconds, (prec>1 ? prec-2 : 0), showLeadingZeroes, showTrailingZeroes);

            if (seconds=="60") {
                seconds="0";
                ++vMinutes;
                if(vMinutes==60) {
                    vMinutes=0;
                    ++vDegrees;
                }
            }

            if (prec==0 && vMinutes>=30.0) {
                vDegrees++;
            } else if (prec==1 && vSeconds>=30.0) {
                vMinutes++;
            }

            degrees.setNum(vDegrees);
            minutes.setNum(vMinutes);

            switch (prec) {
            case 0:
                ret = degrees + QChar(0xB0);
                break;
            case 1:
                ret = degrees + QChar(0xB0) + " " + minutes + "'";
                break;
            default:
                ret = degrees + QChar(0xB0) + " " + minutes + "' "
                      + seconds + "\"";
                break;
            }
        }
        break;

    default:
        break;
    }

    return ret;
}
    
    
    
QString RUnit::trimTrailingZeroes(const QString& s) {
    QString ret = s;

    bool done = false;
    while (!done) {
        if (ret.size()>0) {
            if (ret.at(ret.size()-1)=='0') {
                ret = ret.left(ret.size()-1);
            }
            else if (ret.at(ret.size()-1)=='.') {
                ret = ret.left(ret.size()-1);
                done = true;
            }
            else {
                done = true;
            }
        }
        else {
            done = true;
        }
    }

    return ret;
}

/**
 * Converts a double into a string which is as short as possible
 *
 * @param value The double value
 * @param prec Precision e.g. a precision of 1 would mean that a
 *     value of 2.12030 will be converted to "2.1". 2.000 is always just "2").
 */
QString RUnit::doubleToString(double value, double prec,
        bool /*showLeadingZeroes*/, bool /*showTrailingZeroes*/) {

    QString ret;
    QString exaStr;
    int dotPos;
    int num;
    if (prec>1.0e-12) {
        num = RMath::mround(value / prec);
    }
    else {
        num = RMath::mround(value);
    }

    exaStr = doubleToString(prec, 10);
    dotPos = exaStr.indexOf('.');

    if (dotPos==-1) {
        ret.sprintf("%d", RMath::mround(num*prec));
    } else {
        int digits = exaStr.length() - dotPos - 1;
        ret = doubleToString(num*prec, digits);
    }

    return ret;
}




/**
 * Converts a double into a string which is as short as possible.
 *
 * @param value The double value
 * @param prec Precision
 */
QString RUnit::doubleToString(double value, int prec,
        bool /*showLeadingZeroes*/, bool showTrailingZeroes) {

    QString ret;

    QString formatString;
    if (showTrailingZeroes) {
        formatString = QString("%.0%1f").arg(prec);
    }
    else {
        formatString = QString("%.%1f").arg(prec);
    }

    // avoid banker's rounding, always round 0.5 up and -0.5 down:
    double fuzz = 1.0e-13;
    if (value<0.0) {
        fuzz*=-1;
    }

    ret.sprintf(formatString.toLatin1(), value + fuzz);

    if (!showTrailingZeroes) {
        if (ret.contains('.')) {
            // Remove zeros at the end:
            while (ret.at(ret.length()-1)=='0') {
                ret.truncate(ret.length()-1);
            }

            if(ret.at(ret.length()-1)=='.') {
                ret.truncate(ret.length()-1);
            }
        }
    }

    return ret;

    /*
    QString valStr;

    value *= exp10(prec);
    value = RMath::mround(value);
    value /= exp10(prec);

    valStr.setNum(value, 'f', prec);

    if (valStr.contains('.')) {
        // Remove zeros at the end:
        while (valStr.at(valStr.length()-1)=='0') {
            valStr.truncate(valStr.length()-1);
        }

        if(valStr.at(valStr.length()-1)=='.') {
            valStr.truncate(valStr.length()-1);
        }
    }

    return valStr;
    */
}
