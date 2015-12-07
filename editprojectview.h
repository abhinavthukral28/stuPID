#ifndef EDITPROJECTVIEW_H
#define EDITPROJECTVIEW_H

#include <QDialog>

namespace Ui {
class EditProjectView;
}

class EditProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit EditProjectView(QWidget *parent = 0);
    ~EditProjectView();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditProjectView *ui;
};

#endif // EDITPROJECTVIEW_H
