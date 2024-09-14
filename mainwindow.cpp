//
// Created by illmilo on 06/09/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsDropShadowEffect>

#include <QUrl>
#include <QDesktopServices>
#include <QVBoxLayout>

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

    webView = new QWebEngineView(this);
    webView->hide();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(webView);
    ui->centralwidget->setLayout(layout);

    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &mainwindow::handleSearch);
    connect(ui->pushButton, &QPushButton::clicked, this, &mainwindow::handleSearch);
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::handleSearch() {
    QString query = ui->lineEdit->text();
    if (!query.isEmpty()) {
        if (query.startsWith("http://") || query.startsWith("https://"))
            webView->setUrl(QUrl(query));
        else {
            QString searchUrl = QString("https://www.google.com/search?q=%1").arg(query);
            webView->setUrl(QUrl(searchUrl));
        }
        webView->show();
    }
}