#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<stdlib.h>
//MUAHAHAHAHAHAHAHA

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 *
 * A stupid class to do stupid things.
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    static const QString BUTTON_TEXT;
    static const QString PUSHED_BUTTON_TEXT;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
