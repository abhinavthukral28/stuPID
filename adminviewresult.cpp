#include "adminviewresult.h"
#include "ui_adminviewresult.h"
#include "logindialog.h"

AdminViewResult::AdminViewResult(AdminViewResultController *newController) :
        QDialog(),
        ui(new Ui::AdminViewResult),
        adminViewResultController(newController)
{
    ui->setupUi(this);
    teams = adminViewResultController->getTeams();
    for(int i=0; i< teams.count(); i++)
    {
        ui->listWidget->addItem("Team");
    }

}

AdminViewResult::~AdminViewResult()
{
    delete ui;
}

void AdminViewResult::on_BackButton_clicked()
{

}

void AdminViewResult::on_pushButton_clicked()
{

}
void AdminViewResult::updatePanel(int index){

    QList<int> idList = teams.at(index)->getTeamMembers();
    QStringList nameList;

    for(int j=0; j<idList.count();j++){
        Student student = adminViewResultController->getStudent(idList.at(j));
        nameList.append(student.getUsername());
    }
    ui->textBrowser_2->setText(nameList.join(','));
    QString str = teams.at(index)->getResultDisplay();
    QStringList compatibilityLevels = str.split('/');
    QStringList highCompatibility = compatibilityLevels.at(0).split('_');
    QStringList mediumCompatibility = compatibilityLevels.at(1).split('_');
    QStringList lowCompatibility = compatibilityLevels.at(2).split('_');
    QString finalString = "High Compatibility\n";
    for(int i=0;i<highCompatibility.count();i++){
        finalString += highCompatibility.at(i) + "\n";
    }
    finalString += "\nMedium Compatibility\n";
    for(int i=0;i<mediumCompatibility.count();i++){
        finalString += mediumCompatibility.at(i) + "\n";
    }
    if(lowCompatibility.length() > 0){
        finalString += "\nLow Compatibility\n";
        for(int i=0;i<lowCompatibility.count();i++){
            finalString += lowCompatibility.at(i) + "\n";
        }
    }
    ui->textBrowser->setText(finalString);



}

void AdminViewResult::on_listWidget_clicked(const QModelIndex &index)
{
    int i = index.row();


    updatePanel(i);



}

