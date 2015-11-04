#ifndef CREATEPROJECTVIEWCONTROLLER_H
#define CREATEPROJECTVIEWCONTROLLER_H

class CreateProjectView;
class Project;
class Database;
class CreateProjectViewController
{
public:
    CreateProjectViewController(CreateProjectView *view);
//    int setNewProjectTeamMax(int& i);
//    int setNewProjectTeamMin(int& i);
//    int setNewProjectDescription(QString& description);
//    int setNewProjectTitle(QString& title);
//    int saveProject();
private:
    CreateProjectView *createProjectsView;
    Database *database;
    //QList<Project*> projectList;
    Project *newproject;


};

#endif // CREATEPROJECTVIEWCONTROLLER_H
