#ifndef MANAGEPROJECTSVIEW_H
#define MANAGEPROJECTSVIEW_H
#include <QListWidgetItem>
#include <QMainWindow>

#include "manageprojectscontroller.h"

namespace Ui {
class ManageProjectsView;
}

class ManageProjectsView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageProjectsView(QWidget *parent = 0);
    ~ManageProjectsView();

private slots:
    void on_projectsList_itemClicked(QListWidgetItem *item);

private:
    Ui::ManageProjectsView *ui;
    ManageProjectsController *manageProjectsController;
};

#endif // MANAGEPROJECTSVIEW_H
