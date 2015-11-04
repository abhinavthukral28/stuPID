#ifndef STUDENTREGISTERCONTROLLER_H
#define STUDENTREGISTERCONTROLLER_H
#include <QObject>
class StudentRegister;
class Student;
class StudentRegisterController:public QObject
{
	Q_OBJECT
public:
    StudentRegisterController(StudentRegister *sRegister);
    int goToQualificationsView(Student student);


private:
	StudentRegister *studentRegister;
};

#endif // STUDENTREGISTERCONTROLLER_H
