#ifndef STUDENTPROJECTVIEW_H
#define STUDENTPROJECTVIEW_H

#include <QDialog>

namespace Ui {
class studentProjectView;
}

class studentProjectView : public QDialog
{
    Q_OBJECT

public:
    explicit studentProjectView(QWidget *parent = 0);
    ~studentProjectView();

private:
    Ui::studentProjectView *ui;
};

#endif // STUDENTPROJECTVIEW_H
