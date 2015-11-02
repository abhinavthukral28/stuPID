#ifndef MANAGEPROJECTSVIEW_H
#define MANAGEPROJECTSVIEW_H
#include <QListWidgetItem>
#include <QDialog>

namespace Ui {
class ManageProjectsView;
}

class ManageProjectsView : public QDialog
{
    Q_OBJECT

public:
    explicit ManageProjectsView(QWidget *parent = 0);
    ~ManageProjectsView();

private slots:
    void on_projectsList_itemClicked(QListWidgetItem *item);

private:
    Ui::ManageProjectsView *ui;
};

#endif // MANAGEPROJECTSVIEW_H
