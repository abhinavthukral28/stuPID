#ifndef STUDENTPROJECTVIEW_H
#define STUDENTPROJECTVIEW_H

#include <QDialog>
class QListWidgetItem;
namespace Ui {
class studentProjectView;
}

class studentProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit studentProjectView(QWidget *parent = 0);
    ~studentProjectView();

private slots:
    void on_registerButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::studentProjectView *ui;
};

#endif // STUDENTPROJECTVIEW_H
