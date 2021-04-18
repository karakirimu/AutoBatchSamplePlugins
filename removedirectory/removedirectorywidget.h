#ifndef REMOVEDIRECTRYWIDGET_H
#define REMOVEDIRECTRYWIDGET_H

#include "pluginwidget.h"
#include <QHash>
#include <QFileDialog>

namespace Ui {
class RemoveDirectoryWidget;
}

class RemoveDirectoryWidget : public PluginWidget
{
    Q_OBJECT

public:
    explicit RemoveDirectoryWidget(QWidget *parent = nullptr);
    ~RemoveDirectoryWidget() override;

public slots:
    void receiveList(QStringList args) override;

private slots:
    void rmpathTextChanged(const QString &arg1);
    void rmToolButtonClicked();

    void fileRemoveCheckBoxChanged(int arg1);

private:
    void updateArguments();

    Ui::RemoveDirectoryWidget *ui;

    enum RemoveDirectoryList{
        RemovePath,
        FileInclude
    };

    QHash<RemoveDirectoryList, QString> settingargs;
};

#endif // REMOVEDIRECTRYWIDGET_H
