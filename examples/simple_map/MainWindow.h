/*
 * Copyright (C) 2017
 * All rights reserved.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <ol/forward_definitions.h>

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    ol::MapPtr m_map;
};

#endif // MAINWINDOW_H
