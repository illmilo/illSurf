//
// Created by illmilo on 06/09/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsDropShadowEffect>


mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    ui->lineEdit->setPlaceholderText("Search anything...");

    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(50);
    shadow->setXOffset(5);
    shadow->setYOffset(4);
    shadow->setColor(QColor(20,20,20));
    ui->lineEdit->setGraphicsEffect(shadow);
}

mainwindow::~mainwindow() {
    delete ui;
}
