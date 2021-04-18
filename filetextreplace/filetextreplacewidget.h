#ifndef FILETEXTREPLACEWIDGET_H
#define FILETEXTREPLACEWIDGET_H

#include <QHash>
#include <pluginwidget.h>
#include <QFileDialog>

namespace Ui {
class FileTextReplaceWidget;
}

class FileTextReplaceWidget : public PluginWidget
{
    Q_OBJECT

public:
    explicit FileTextReplaceWidget(QWidget *parent = nullptr);
    ~FileTextReplaceWidget() override;

public slots:
    void receiveList(QStringList args) override;

private slots:
    void inputEditChanged(const QString &arg1);
    void inputToolButtonClicked();

    void outputEditChanged(const QString &arg1);
    void outputToolButtonClicked();

    void searchEditChanged(const QString &arg1);

    void replaceEditChanged(const QString &arg1);

private:
    void updateArguments();

    Ui::FileTextReplaceWidget *ui;

    enum FileTextReplaceList{
        InputFile,
        OutputFile,
        SearchWord,
        ReplaceWord
    };

    QHash<FileTextReplaceList, QString> settingargs;
};

#endif // FILETEXTREPLACEWIDGET_H
