//
// Created by illmilo on 06/09/2024.
//

#ifndef ILLSURF_MAINWINDOW_H
#define ILLSURF_MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private slots:
    void handleSearch();

private:
    Ui::mainwindow *ui;
    QWebEngineView *webView;
};


#endif //ILLSURF_MAINWINDOW_H
