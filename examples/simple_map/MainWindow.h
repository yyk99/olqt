/*
 * Copyright (C) 2017
 * All rights reserved.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWindow>

#include <ol/forward_definitions.h>

class MainWindow : public QWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWindow *parent = 0);
    ~MainWindow();

private:
    ol::MapPtr m_map;
};

#endif // MAINWINDOW_H
