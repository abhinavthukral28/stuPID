#ifndef STUDENTREGISTERCONTROLLER_H
#define STUDENTREGISTERCONTROLLER_H
#include <QObject>
class StudentRegister;
class Student;
class StudentRegisterController:public QObject
{
	Q_OBJECT
public:
    int goToQualificationsView(Student student);
    static StudentRegisterController* getInstance();
    int setView(StudentRegister *view);


private:
    StudentRegisterController();
	StudentRegister *studentRegister;
    static StudentRegisterController *instance;

};

#endif // STUDENTREGISTERCONTROLLER_H
