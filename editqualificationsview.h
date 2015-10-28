#ifndef EDITQUALIFICATIONSVIEW_H
#define EDITQUALIFICATIONSVIEW_H

#include <QDialog>

namespace Ui {
class editQualificationsView;
}

class editQualificationsView : public QDialog
{
    Q_OBJECT

public:
    explicit editQualificationsView(QWidget *parent = 0);
    ~editQualificationsView();

private slots:
    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::editQualificationsView *ui;
};

#endif // EDITQUALIFICATIONSVIEW_H
