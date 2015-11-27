#ifndef STUDENTPROJECTVIEW_H
#define STUDENTPROJECTVIEW_H

#include <QDialog>
class QListWidgetItem;
namespace Ui {
class studentProjectView;
}
class studentprojectregisterviewcontroller;
class QStringList;
class Project;
class studentProjectRegisterView : public QDialog
{
    Q_OBJECT

public:
    explicit studentProjectRegisterView(QWidget *parent = 0);
    ~studentProjectRegisterView();
    int updateProjectsList(QList<QString> &projectTitles);
    int updateDetailedView(Project &project);


private slots:
    void on_registerButton_clicked();

    void on_projectsList_doubleClicked(const QModelIndex &index);

    void on_manageProjectButton_clicked();

private:
    Ui::studentProjectView *ui;
    studentprojectregisterviewcontroller *studentProjectRegisterViewController;
};

#endif // STUDENTPROJECTVIEW_H
