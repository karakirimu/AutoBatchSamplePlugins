#ifndef DOWNLOADWIDGET_H
#define DOWNLOADWIDGET_H

#include <pluginwidget.h>
#include <QRadioButton>
#include <QFileDialog>
#include <QHash>

namespace Ui {
class DownloadWidget;
}

class DownloadWidget : public PluginWidget
{
    Q_OBJECT

public:
    explicit DownloadWidget(QWidget *parent = nullptr);
    ~DownloadWidget() override;

public slots:

    // This function receives the current setting
    // information from the main editor.
    void receiveList(QStringList args) override;

private slots:
    void urlRadioButtonClicked();
    void urlFileRadioButtonClicked();
    void lineEditChanged(QString text);
    void folderLineEditChanged(QString text);
    void openFile();
    void openFolder();

private:
    void updateArguments();

    enum DownloadArgumentList{
        InputType,
        InputPath,
        OutputPath
    };

    QHash<DownloadArgumentList, QString> settingargs;

    Ui::DownloadWidget *ui;
};

#endif // DOWNLOADWIDGET_H
