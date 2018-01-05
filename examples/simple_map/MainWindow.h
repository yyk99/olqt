/*
 * Copyright (C) 2017
 * All rights reserved.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWindow>

class MainWindow : public QWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWindow *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
