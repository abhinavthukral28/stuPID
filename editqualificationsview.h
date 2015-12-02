#ifndef EDITQUALIFICATIONSVIEW_H
#define EDITQUALIFICATIONSVIEW_H

#include <QDialog>
#include "student.h"
#include "editqualificationscontroller.h"
#include "qualification.h"
class EditQualificationsController;
namespace Ui {
class editQualificationsView;

}

class EditQualificationsView : public QDialog
{
    Q_OBJECT

public:
    explicit EditQualificationsView(QWidget *parent = 0);
    ~EditQualificationsView();

private slots:
    void on_listWidget_clicked(const QModelIndex &index);
    void updatePanel(int index);
    void on_NextButton_2_clicked();

private:
    Ui::editQualificationsView *ui;
    EditQualificationsController *controller;
    Student stu;
    QList<Qualification*> qualificationList;
};

#endif // EDITQUALIFICATIONSVIEW_H
