#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include <QPluginLoader>
#include <QFileInfo>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include "extraplugininterface.h"
#include "dummytable.h"
#include "receivelistdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestWindow; }
QT_END_NAMESPACE

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    TestWindow(QWidget *parent = nullptr);
    ~TestWindow() override;

    void preloadPlugin(QStringList args);

private slots:
    void openClicked();
    void playClicked();
    void closeClicked();
    void receiveListClicked();
    void resetReceiveListClicked();
    void getInformationClicked();

    void setPluginOutput(QString message);

private:
    QStringList getCommandList();
    bool loadPluginInstance(QString plfile);

    QPluginLoader *pluginloader = nullptr;
    QObject *plugininstance = nullptr;

    Ui::TestWindow *ui;
};
#endif // TESTWINDOW_H
