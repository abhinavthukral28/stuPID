#ifndef STUDENTPROJECTVIEW_H
#define STUDENTPROJECTVIEW_H

#include <QDialog>
class QListWidgetItem;
namespace Ui {
class studentProjectView;
}

class studentProjectRegisterView : public QDialog
{
    Q_OBJECT

public:
    explicit studentProjectRegisterView(QWidget *parent = 0);
    ~studentProjectRegisterView();

private slots:
    void on_registerButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::studentProjectView *ui;
};

#endif // STUDENTPROJECTVIEW_H
