#include "mainwindow.h"
#include "ui_mainwindow.h"


/**
 * @brief MainWindow::BUTTON_TEXT This is the initial text that will be on the button
 *                                (this can also be set using the design tool).
 */
const QString MainWindow::BUTTON_TEXT = "Click me!";

/**
 * @brief MainWindow::PUSHED_BUTTON_TEXT This is the text for the clicked button.
 */
const QString MainWindow::PUSHED_BUTTON_TEXT = "Wow congrats!!!!!!!!!!!!";

/**
 * @brief MainWindow::MainWindow Main constructor and entry point for this class.
 * @param parent A pointer to the parent window that contains this UI.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Button text is set here
    ui->pushButton->setText(BUTTON_TEXT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_pushButton_clicked Click listener for the QPushButton.
 *                                          Listeners can be generated in design mode by;
 *                                          1. right click ui desired ui widget
 *                                          2. go to slot
 *                                          3. select the listener you want to program
 */
void MainWindow::on_pushButton_clicked()
{
    QPushButton* pushButton = ui->pushButton;

    //Set the text on the clicked button
    pushButton->setText(PUSHED_BUTTON_TEXT);

    //Necessary to resize button to text size
    pushButton->resize(pushButton->sizeHint().width(), pushButton->sizeHint().height());
}
