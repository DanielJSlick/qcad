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
// Auto generated by Testing Dashboard
// File        : scripts/Draw/Circle/CircleCR/Tests/CircleCRTest00.js
// Timestamp   : 2011-02-28 14:04:43
// Description : 6 circles defined by radius and center

include('scripts/Pro/Developer/TestingDashboard/TdbTest.js');

function CircleCRTest00() {
    TdbTest.call(this, 'scripts/Draw/Circle/CircleCR/Tests/CircleCRTest00.js');
}

CircleCRTest00.prototype = new TdbTest();

CircleCRTest00.prototype.test00 = function() {
    qDebug('running CircleCRTest00.test00()...');
    this.setUp();
    this.clickOnWidget('MainWindow::MainToolsPanel::CircleMenuButton');
    this.clickOnWidget('MainWindow::CircleToolsPanel::CircleCRButton');
    this.setToolOption('CircleCR/Radius',  [ 1, 0 ] );
    this.updateToolOptions();
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(20.1, 19.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(20.1, 19.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setToolOption('CircleCR/Radius',  [ 2, 0 ] );
    this.updateToolOptions();
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(23.1, 19.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(23.1, 19.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setToolOption('CircleCR/Radius',  [ 3, 0 ] );
    this.updateToolOptions();
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(28.3, 20);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(28.3, 20);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setToolOption('CircleCR/Radius',  [ 4, 0 ] );
    this.updateToolOptions();
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(34.9, 19.7);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(34.9, 19.7);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setToolOption('CircleCR/Radius',  [ 5, 0 ] );
    this.updateToolOptions();
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(35.3, 10.8);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(35.3, 10.8);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    this.setToolOption('CircleCR/Radius',  [ 6, 0 ] );
    this.updateToolOptions();
    this.setZoom(10, new RVector(5, 5, 0) );
    var p = new RVector(23.7, 11.2);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.LeftButton, 1, 0);
    var p = new RVector(23.7, 11.2);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.LeftButton, 0, 0);
    var p = new RVector(45.8, 12.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonPress, p, Qt.RightButton, 2, 0);
    var p = new RVector(45.8, 12.9);
    this.sendMouseEventModelPos(QEvent.MouseButtonRelease, p, Qt.RightButton, 0, 0);
    this.verifyDrawing('CircleCRTest00_000.dxf');
    this.tearDown();
    qDebug('finished CircleCRTest00.test00()');
};

