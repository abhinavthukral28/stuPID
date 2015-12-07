#ifndef EDITPROJECTVIEW_H
#define EDITPROJECTVIEW_H

#include <QDialog>
#include "editprojectcontroller.h"
namespace Ui {
class EditProjectView;
}

//class EditProjectController;
class EditProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit EditProjectView(QWidget *parent = 0);
    const QString getProjectDescription();
    const QString getProjectTitle();
    const int& getProjectTeamMin();
    const int& getProjectTeamMax();

    QString aTitle, aMin, aMax, aDescription;
    void accept();
    ~EditProjectView();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditProjectView *ui;
    EditProjectController *editProjectController;
};

#endif // EDITPROJECTVIEW_H
